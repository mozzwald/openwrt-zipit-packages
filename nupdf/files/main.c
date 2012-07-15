/*
 * main.c - main source file for nupdf:
 * 
 * nupdf-a pdf viewer for the dingoo-a320(dingux), and the ben nanonote
 *
 * Copyright (C) 2010  Gareth Francis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include <stdio.h>
#include <SDL/SDL.h>
#include "fitz.h"
#include "mupdf.h"
#include "pdfapp.h"
#include "SDL_picofont.h"

static void load_page(pdfapp_t *app);
static void draw_page(pdfapp_t *app);
int init_graphics(void);
int main_loop(void);
void reset_panning(void);
int init_config(void);
int save_config(void);
int menu_loop(void);


#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define DEFAULT_ZOOM 0.555

#ifdef DINGOO_BUILD
#define BPP 16
#else
#define BPP 32
#endif

#ifdef DINGOO_BUILD
#define NUPDF_ZOOMIN SDLK_SPACE
#define NUPDF_ZOOMOUT SDLK_LALT
#define NUPDF_NEXTPAGE SDLK_BACKSPACE
#define NUPDF_PREVPAGE SDLK_TAB
#define NUPDF_FINEPAN SDLK_LCTRL
#define NUPDF_ROTATE SDLK_LSHIFT
#define NUPDF_MENU SDLK_RETURN
#else
#define NUPDF_ZOOMIN SDLK_o
#define NUPDF_ZOOMOUT SDLK_l
#define NUPDF_NEXTPAGE SDLK_p
#define NUPDF_PREVPAGE SDLK_i
#ifdef ZIPIT_Z2
/* Zipit has many keys, so select nanonote keys and add Zipit keys. */
/* But remap NUPDF_FINEPAN modifier to SDLK_LCTRL (like the dingoo) */
#define NUPDF_FINEPAN SDLK_LCTRL
#else
#define NUPDF_FINEPAN SDLK_a   /* maybe change later */
#endif
#define NUPDF_ROTATE SDLK_q
#define NUPDF_MENU SDLK_RETURN
#endif

pdfapp_t app;
SDL_Surface *screen = NULL, *image = NULL, *loading = NULL;
SDL_Rect src, oldsrc, dest, desthourglass;

int check_input=1;
int fine_pan[5];
int topreturn=0;

#define NUPDF_FINEPAN_ENABLE 0
#define NUPDF_FINEPAN_UP 1
#define NUPDF_FINEPAN_DOWN 2
#define NUPDF_FINEPAN_LEFT 3
#define NUPDF_FINEPAN_RIGHT 4




static void doc_open(pdfapp_t *app, char *path);


int main(int argc, char** argv)
{
	int i;

	if(argc==1)
	{
		fprintf(stderr, "You must supply a filename to open\n");
		return 1;
	}
		
	FILE *pdfile;
	pdfile=fopen(argv[1], "r");
	if(pdfile==NULL)
	{
		fprintf(stderr, "error, file %s does not exist\n", argv[1]);
		return 1;
	}
	fclose(pdfile);


	if(init_config())
		return 1;
	
	oldsrc.x = oldsrc.y = 0;

	if ((i = init_graphics()) != 0)
	{
		fprintf(stderr, "error, Could not init SDL graphics (%d)\n", i);
		return 1;
	}
	src.x=0;
	src.y=0;
	src.w=SCREEN_WIDTH;
	src.h=SCREEN_HEIGHT;
	
	dest.x=0;
	dest.y=0;

	desthourglass.x=280;
	desthourglass.y=0;
	
	pdfapp_init(&app);
	
	app.scrw=SCREEN_WIDTH;
	app.scrh=SCREEN_HEIGHT;
	app.zoom=DEFAULT_ZOOM;
	
	app.pageno=1;
	
#if 0
	pdfapp_open(&app, argv[1]);
#else
	doc_open(&app, argv[1]);
#endif
		
	load_page(&app);
	draw_page(&app);
	
	if (loading)
		SDL_FreeSurface(loading);
	loading = NULL;
	
	SDL_Surface *temp_bmp;
		
#ifdef ZIPIT_Z2
        temp_bmp = SDL_LoadBMP("/usr/share/nupdf/data/loadingsmall.bmp");
#else
 	temp_bmp = SDL_LoadBMP("data/loadingsmall.bmp");
#endif
	if (temp_bmp == NULL)
	{
		fprintf(stderr, "Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	
	loading = SDL_DisplayFormat(temp_bmp);
	if(loading==NULL)
		return 1;

	SDL_FreeSurface(temp_bmp);
	
	/* fprintf(stderr, "main_loop()\n"); */
	main_loop();
	
	pdfapp_close(&app);
	if (image)
	SDL_FreeSurface(image);
	
	SDL_Quit();
	return 0;
}
	
int main_loop(void)
{

	int done=0;
	SDL_Event keyevent; 
	Uint8 *keystate; 
	float oldzoom;

	while(!done)
	{
		
	if(check_input)
	{
		/* get the input, and act upon it */
	    while (SDL_PollEvent(&keyevent))   
		{
		  if(keyevent.type==SDL_KEYDOWN)
		  {

			  /* fprintf(stderr, "main_loop(SDL keyevent)\n"); */

			  switch(keyevent.key.keysym.sym)
			  {
				case NUPDF_ZOOMIN:
#ifdef ZIPIT_Z2
		                case SDLK_PAGEUP:
#endif
				  if(app.zoom!=2)
				  {
					SDL_BlitSurface(loading, NULL, screen, &desthourglass);
				    SDL_Flip(screen);
					check_input=0;
						oldzoom=app.zoom;
						app.zoom+=0.25;
					if(app.zoom>2)
						app.zoom=2;
					else
					{
						src.x+=(int)(app.zoom*100*0.5);
						src.y+=(int)(app.zoom*100*0.5);
					}
					reset_panning();
					draw_page(&app);
				  }
				  break;
				  
				case NUPDF_ZOOMOUT:
#ifdef ZIPIT_Z2
		                case SDLK_PAGEDOWN:
#endif
				if(app.zoom!=0.5)
				{
					SDL_BlitSurface(loading, NULL, screen, &desthourglass);
					SDL_Flip(screen);
					check_input=0;
					oldzoom=app.zoom;
					app.zoom-=0.25;
					if(app.zoom<0.5)
						app.zoom=0.5;
					else
					{
						src.x-=(int)(app.zoom*100*0.5);
						src.y-=(int)(app.zoom*100*0.5);
					}
					reset_panning();
					draw_page(&app);
				}
				  break;
				  
				case NUPDF_NEXTPAGE:
#ifdef ZIPIT_Z2
		                case SDLK_PERIOD:
		                case SDLK_END:
#endif
				if(fine_pan[NUPDF_FINEPAN_ENABLE])
				{
					if(app.pageno!=app.pagecount)
					{
						SDL_BlitSurface(loading, NULL, screen, &desthourglass);
						SDL_Flip(screen);
						if(app.pageno<(app.pagecount-5))
							app.pageno+=5;
						else 
							app.pageno=app.pagecount;
						check_input=0;
						reset_panning();
						
						/* topreturn code */
						if(topreturn)
							src.y=0;
						
						load_page(&app);
						draw_page(&app);
						SDL_PollEvent(&keyevent);
						keystate=SDL_GetKeyState(NULL);
						if(keystate[NUPDF_FINEPAN])
							fine_pan[NUPDF_FINEPAN_ENABLE]=1;
					}	
				}
				else
					if(app.pageno<app.pagecount)
						{
							SDL_BlitSurface(loading, NULL, screen, &desthourglass);
							SDL_Flip(screen);
							app.pageno++;
							check_input=0;
							reset_panning();
							
							/* topreturn code */
							if(topreturn)
								src.y=0;
							
							load_page(&app);
							draw_page(&app);
						}
				else
					fprintf(stderr, "can't go beyond the last page idiot\n");
				break;
				
				case NUPDF_PREVPAGE:
#ifdef ZIPIT_Z2
		                case SDLK_COMMA:
		                case SDLK_HOME:
#endif
				if(fine_pan[NUPDF_FINEPAN_ENABLE])
				{
					if(app.pageno!=1)
					{
						SDL_BlitSurface(loading, NULL, screen, &desthourglass);
						SDL_Flip(screen);
						if(app.pageno>5)
							app.pageno-=5;
						else
							app.pageno=1;
						check_input=0;
						reset_panning();
						load_page(&app);
						draw_page(&app);
						SDL_PollEvent(&keyevent);
						keystate=SDL_GetKeyState(NULL);
						if(keystate[NUPDF_FINEPAN])
							fine_pan[NUPDF_FINEPAN_ENABLE]=1;	
					}
				}
				else
					if(app.pageno>1)
					   {
							SDL_BlitSurface(loading, NULL, screen, &desthourglass);
							SDL_Flip(screen);
							app.pageno--;
							check_input=0;
							reset_panning();
							load_page(&app);
							draw_page(&app);	
						}
				else
					fprintf(stderr, "can't go beyond the first page idiot\n");
				break;
				
				case NUPDF_ROTATE:
#ifdef ZIPIT_Z2
		                case SDLK_SPACE:
#endif
					if(app.rotate==0)
					{
						SDL_BlitSurface(loading, NULL, screen, &desthourglass);
						SDL_Flip(screen);
						app.rotate=90;
						draw_page(&app);
					}
					else if(app.rotate==90)
					{
						SDL_BlitSurface(loading, NULL, screen, &desthourglass);
						SDL_Flip(screen);
						app.rotate=0;
						draw_page(&app);
					}
				break;
				
				case NUPDF_FINEPAN:
					fine_pan[NUPDF_FINEPAN_ENABLE]=1;
					break;
				
				case SDLK_DOWN:
					fine_pan[NUPDF_FINEPAN_DOWN]=1;
					break;
				case SDLK_UP:
					fine_pan[NUPDF_FINEPAN_UP]=1;
					
					break;
				case SDLK_LEFT:
					fine_pan[NUPDF_FINEPAN_LEFT]=1;
					
					break;
				case SDLK_RIGHT:
					fine_pan[NUPDF_FINEPAN_RIGHT]=1;
					
					break;
					
				case NUPDF_MENU:
#ifdef ZIPIT_Z2
		                case SDLK_TAB:
#endif
					menu_loop();
					break;		
					
				case SDLK_ESCAPE:
				  done=1;
				  break;				  
				default:
				  break;
			  }
			}
			
		if(keyevent.type==SDL_KEYUP)
			{
			   switch(keyevent.key.keysym.sym)
				{
					case NUPDF_FINEPAN:
						fine_pan[NUPDF_FINEPAN_ENABLE]=0;
						break;
					case SDLK_DOWN:
						fine_pan[NUPDF_FINEPAN_DOWN]=0;
						break;
					case SDLK_UP:
						fine_pan[NUPDF_FINEPAN_UP]=0;
						break;
					case SDLK_RIGHT:
						fine_pan[NUPDF_FINEPAN_RIGHT]=0;
						break;
					case SDLK_LEFT:
						fine_pan[NUPDF_FINEPAN_LEFT]=0;
						break;
				
				}
			}
			if(!check_input)/* rename this sometime */
				{
					while(SDL_PollEvent(&keyevent));
					check_input=1;
				}
		}
		
		
		if(fine_pan[NUPDF_FINEPAN_ENABLE])
			{
				if(fine_pan[NUPDF_FINEPAN_DOWN])
					src.y+=2;
				if(fine_pan[NUPDF_FINEPAN_LEFT])
					src.x-=2;
				if(fine_pan[NUPDF_FINEPAN_UP])
					src.y-=2;
				if(fine_pan[NUPDF_FINEPAN_RIGHT])
					src.x+=2;
			}
		else
			{/* rename this damn finepan stuff sometime, it doesn't make sense anymore */
				if(fine_pan[NUPDF_FINEPAN_DOWN])
					if((src.y+240)<app.image->h)
						src.y+=15;
				if(fine_pan[NUPDF_FINEPAN_UP])
					if(src.y>0)
						src.y-=15;
				if(fine_pan[NUPDF_FINEPAN_LEFT])
					if(src.x>0)
						src.x-=15;
				if(fine_pan[NUPDF_FINEPAN_RIGHT])
					if((src.x+320)<app.image->w)
						src.x+=15;
			}
		if((src.y+240)>app.image->h)
			if(app.image->h>240)
				src.y=(app.image->h-240);
			else
				src.y=0;
		if(src.y<0)
			src.y=0;
		if(src.x<0)
			src.x=0;
		if((src.x+320)>app.image->w)
			if(app.image->w>320)
				src.x=(app.image->w-320);
			else
				src.x=0;
	}

	// We really only need to do this if src.x or src.y changed for panning.
	if ((src.x != oldsrc.x) || (src.y != oldsrc.y))
	{
		SDL_FillRect(screen, NULL, SDL_MapRGBA(screen->format, 0, 0, 0, 0));
	
		SDL_BlitSurface(image, &src, screen, &dest);
		SDL_Flip(screen);

		oldsrc.x = src.x;
		oldsrc.y = src.y;
	}
	}	
	
}
	
int menu_loop(void)
{
	SDL_Event keyevent;
	SDL_Surface *text;
	SDL_Color textcolor={255, 255, 255};
	char settingstext[1500];
	char arrows[5][5];
	char onoff[5];
	int arrowposition=1;
	int i=0;
	int done=0;
	int pagenumber=app.pageno;
	
	while(!done)
	{
		if(topreturn)
			sprintf(onoff, "ON");
		else
			sprintf(onoff, "OFF");
		
		     for (i = 0; i < 5; ++i)
            {
                if(i==arrowposition) 
                {
                    strcpy(arrows[i], "<<<");
                }
                else
                {
                    strcpy(arrows[i], "");
                }
	    }


		sprintf(settingstext, "\t\t\tSettings\t%s\n\n"
                        "Jump to page %i\t%s\n\n"
                        "Return\t%s"
                        "\n\n\n\n\n\n"
                        "Up/Down:       select item\n"
                        "Left/Right:    edit item value\n"
#ifdef ZIPIT_Z2		
                        "+/-:           +/-10 to item value\n"
#else
			"zoom+/zoom-:+/-10 to item value\n"
#endif
			, arrows[0], pagenumber, arrows[1], arrows[2]);

		SDL_FillRect(screen, NULL, SDL_MapRGBA(screen->format, 0, 0, 0, 0));
		text=FNT_Render(settingstext, textcolor);
		SDL_BlitSurface(text, NULL, screen, NULL);
		SDL_FreeSurface(text);
		SDL_Flip(screen);
		
	while (SDL_PollEvent(&keyevent))   
	{
		if(keyevent.type==SDL_KEYDOWN)
		{
			switch(keyevent.key.keysym.sym)
			{
			case SDLK_UP:
				if(arrowposition>1)
					arrowposition--;
				break;
			case SDLK_DOWN:
				if(arrowposition<2)
					arrowposition++;
				break;
			case SDLK_LEFT:
				if(arrowposition==1)
					if(pagenumber>1)
						pagenumber--;
				break;
			case SDLK_RIGHT:
				if(arrowposition==1)
					if(pagenumber<app.pagecount)
						pagenumber++;
				break;
			case SDLK_ESCAPE:
#ifdef ZIPIT_Z2
	                case SDLK_TAB: /* On Zipit Tab gets you in/out of menu */
	                case SDLK_BACKSPACE: /* On Zipit BS and ESC also exit menu */
#else
 			case SDLK_RETURN:
#endif
				done=1;
				
				break;
			case NUPDF_ZOOMIN:
#ifdef ZIPIT_Z2
	                case SDLK_PAGEUP:
#endif
				if(arrowposition==1)
					if(pagenumber<(app.pagecount-10))
						pagenumber+=10;
					else
						pagenumber=app.pagecount;
					break;
			case NUPDF_ZOOMOUT:
#ifdef ZIPIT_Z2
		        case SDLK_PAGEDOWN:
#endif
				if(arrowposition==1)
					if(pagenumber>10)
						pagenumber-=10;
					else
						pagenumber=1;
					break;
#ifdef ZIPIT_Z2
			case SDLK_RETURN: /* On Zipit Return or Space accept menu settings.*/
	                case SDLK_SPACE:
#else
 			case NUPDF_FINEPAN:
#endif
				if(arrowposition==1)
				{
					done=1;
					SDL_BlitSurface(loading, NULL, screen, &desthourglass);
					SDL_Flip(screen);
					app.pageno=pagenumber;
					load_page(&app);
					draw_page(&app);
				}			
				if(arrowposition==2)
					done=1;
				break;
			}
		}
	}
		
		
	/* SDL_FreeSurface(text); */ /* Already done above. */
	
	/*  TODO: not working
	 *  save_config(); */	
	}
}
	
int init_config(void)
{

	/* check for config files existence */
	FILE *conf;
	char *confstring;
	size_t bytesread;
	int nbytes=128;
	confstring = (char *) malloc (nbytes + 1);
	int done=0;
	int i=0;
	
#ifdef ZIPIT_Z2
	/* Maybe try $HOME/.config/nupdf/config first? */
	conf=fopen("/usr/share/nupdf/config", "rw");
#else
 	conf=fopen("config", "rw");
#endif
	if(conf==NULL)
	{
		fprintf(stderr, "cannot find config file, quitting...\n");
		return 1;
	}
	else /* parse the options */
	{
		while(!feof(conf))
		{	
			bytesread = getline (&confstring, &nbytes, conf);

			confstring[((int)strlen(confstring))-1]='\0';
			
			fprintf(stderr, "confstring(config_init)=%s\n", confstring);
		
			if(strcmp(confstring, "TOPRETURN")==0)
			{
				bytesread = getline (&confstring, &nbytes, conf);
				confstring[((int)strlen(confstring))-1]='\0';
				if(strcmp(confstring, "1")==0)
				{
					fprintf(stderr, "topreturn is 1\n");
					topreturn=1;
				}
				else
					topreturn=0;
			}
		
		}
			
	}
	
	free(confstring);
	fclose(conf);
	return 0;
}

int save_config(void)
{
	/* TODO: this doesn't work, so isn't being used anymore */
	FILE *conf;
	char *confstring;
	size_t bytesread;
	int nbytes=128;
	confstring = (char *) malloc (nbytes + 1);
	int done=0;
	int i=0;
	
	
#ifdef ZIPIT_Z2
	/* Maybe try $HOME/.config/nupdf/config first? */
	conf=fopen("/usr/local/share/nupdf/config", "rw");
#else
 	conf=fopen("./config", "rw");
#endif
	if(conf==NULL)
	{
		fprintf(stderr, "cannot open config file\n");
		return 1;
	}	
	if(conf==NULL)
	{
		fprintf(stderr, "cannot find config file, settings can't be saved\n");
		return 1;
	}	
	else
	{
		while(!done)
		{	
			bytesread = getline (&confstring, &nbytes, conf);
			confstring[((int)strlen(confstring))-1]='\0';
		
			fprintf(stderr, "confstring=%s\n", confstring);
			fprintf(stderr, "strcmp returns %i\n", strcmp(confstring, "TOPRETURN"));
		
			if(strcmp(confstring, "TOPRETURN")==0)
			{
				char writestring[5];
				sprintf(writestring, "%i", topreturn);
				fprintf(stderr, "topreturn found, saving value\n");
				/*if(fputs(writestring, conf)==EOF)
					fprintf(stderr, "ohshit, failed to save teh config file\n");
				
				if(fprintf(conf, "%i", topreturn)<0)
					fprintf(stderr, "ohshit, failed to save teh config file\n");*/
			
				if(fputc(topreturn, conf)==EOF)
					fprintf(stderr, "ohshit config file write failed\n");
			}
			done=1;
				
		}
	
	}
	
	free(confstring);
	fclose(conf);
	
}	
void reset_panning(void)
{
	int i;
	for(i=0;i<=5;i++)
		fine_pan[i]=0;
}
	
int init_graphics(void)
{
	SDL_Surface *temp_bmp;
		
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
			return 1;
		}
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BPP,SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		return 2;
	}
	
	SDL_ShowCursor(SDL_DISABLE);
	
#ifdef ZIPIT_Z2
	temp_bmp = SDL_LoadBMP("/usr/local/share/nupdf/data/loading.bmp");
#else
	temp_bmp = SDL_LoadBMP("data/loading.bmp");
#endif
	if (temp_bmp == NULL) {
		fprintf(stderr, "Unable to load bitmap: %s\n", SDL_GetError());
		return 3;
	}
		
	loading = SDL_DisplayFormat(temp_bmp);
	if(loading==NULL)
		return 4;
	
	SDL_FreeSurface(temp_bmp);
						
	if(SDL_BlitSurface(loading, NULL, screen, NULL)!=0)
		fprintf(stderr, "loading screen blit failed\n");
	SDL_Flip(screen);
		
	/* load some nice graphics for later (switch from LOADING to hourglass) */
	SDL_FreeSurface(loading);
	
#ifdef ZIPIT_Z2
        temp_bmp = SDL_LoadBMP("/usr/share/nupdf/data/loadingsmall.bmp");
#else
 	temp_bmp = SDL_LoadBMP("data/loadingsmall.bmp");
#endif
	if (temp_bmp == NULL)
	{
		fprintf(stderr, "Unable to load bitmap: %s\n", SDL_GetError());
		return 5;
	}
	
	loading = SDL_DisplayFormat(temp_bmp);
	if(loading==NULL)
		return 6;

	SDL_FreeSurface(temp_bmp);

	return 0;
}
	
/* Borrow simpler code from fbpdf */
void doc_open(pdfapp_t *app, char *path)
{
  fz_accelerate();
  app->cache = fz_new_glyph_cache();
  if (pdf_open_xref(&app->xref, path, NULL)) {
    return;
  }
  if (pdf_load_page_tree(app->xref)) {
    return;
  }
  app->pagecount = pdf_count_pages(app->xref);
  app->rotate = 0;
  app->doctitle = path;
}

static void load_page(pdfapp_t *app)
{
  if (app->image)
    fz_drop_pixmap(app->image);
  app->image = NULL;

  if (image)
    SDL_FreeSurface(image);
  image = NULL;
}

static void draw_page(pdfapp_t *app)
{
  fz_matrix ctm;
  fz_bbox bbox;
  fz_device *dev;
  fz_display_list *list;
  pdf_page *page;
  int pagewidth, pageheight;

  /* fprintf(stderr, "draw_page(%d)\n", app->pageno); */

  if (pdf_load_page(&page, app->xref, app->pageno - 1))
    return;
  list = fz_new_display_list();
  dev = fz_new_list_device(list);
  if (pdf_run_page(app->xref, page, dev, fz_identity))
    return;
  fz_free_device(dev);

  ctm = fz_identity;
  ctm = fz_concat(ctm, fz_translate(0, -page->mediabox.y1));
  ctm = fz_concat(ctm, fz_scale(app->zoom, -app->zoom));    
  ctm = fz_concat (ctm, fz_rotate (app->rotate));
  bbox = fz_round_rect(fz_transform_rect(ctm, page->mediabox));

  app->image = fz_new_pixmap_with_rect(fz_device_rgb, bbox);
  fz_clear_pixmap_with_color(app->image, 0xff);

  dev = fz_new_draw_device(app->cache, app->image);

  /*  fprintf(stderr, "display_list(%p,%p,%p, %d, %d)\n",list,dev,ctm,bbox.x1,bbox.y1); */
  fz_execute_display_list(list, dev, ctm, bbox);
  /* fprintf(stderr, "fz_free_device(%d)\n", dev); */

  fz_free_device(dev);

  /* Copy to SDL surface now? */
  pagewidth  = (int)(bbox.x1 - bbox.x0);
  pageheight = (int)(bbox.y1 - bbox.y0);
  /* colourmask is RGBA, this seems to work properly now, after messing around */
  /* SDL_Create expecte (rmask, gmask, bmask, amask) */
#ifdef ZIPIT_Z2
  image = SDL_CreateRGBSurfaceFrom (app->image->samples, pagewidth, pageheight, 32,
			    pagewidth * 4, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#else
  image = SDL_CreateRGBSurfaceFrom (app->image->samples, pagewidth, pageheight, 32,
			    pagewidth * 4, 0x0000FF00, 0x00FF0000, 0xFF000000, 0x000000FF);
#endif
  SDL_FillRect(screen, NULL, SDL_MapRGBA(screen->format, 0, 0, 0, 0));
  SDL_BlitSurface(image, &src, screen, &dest);
  SDL_Flip(screen);

  //fz_drop_pixmap(app->image); /* Free this instead in load_page() for now. */
  fz_free_display_list(list);
  pdf_free_page(page);
  pdf_age_store(app->xref->store, 3);

}

