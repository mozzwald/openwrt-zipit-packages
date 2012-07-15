#include "fitz.h"
#include "mupdf.h"
#include "pdfapp.h"


static void pdfapp_warn(pdfapp_t *app, const char *fmt, ...)
{
	fprintf(stderr, "this warning function was eaten by a grue,"
					"but feel better knowing that something"
					"went wrong, and it wasn't your fault\n");
}

static void pdfapp_error(pdfapp_t *app, fz_error error)
{
	fprintf(stderr, "this error module was eaten by a grue,"
					"but feel better knowing that something"
					"went wrong, and it wasn't your fault\n");
}


void pdfapp_init(pdfapp_t *app)
{
#if 0
	fz_error error;
	memset(app, 0, sizeof(pdfapp_t));
	error = fz_newrenderer(&app->rast, pdf_devicergb, 0, 1024 * 512);
	if (error)
		pdfapp_error(app, error);
#else
	memset(app, 0, sizeof(pdfapp_t));
#endif
}

void pdfapp_open(pdfapp_t *app, char *filename)
{
#if 0
	fz_error error;
	fz_obj *obj;
	char *password = "";
#else
	fz_error error;
	fz_stream *file;
	char *password = "";
	fz_obj *obj;
	fz_obj *info;

	int fd;
	fd = open(filename, O_BINARY | O_RDONLY, 0666);
	if (fd < 0)
		fprintf(stderr, "error, file %s does not exist\n", filename);
#endif

	/*
	 * Open PDF and load xref table
	 */

	app->filename = filename;

#if 0
	app->xref = pdf_newxref();
	error = pdf_loadxref(app->xref, filename);
	if (error)
	{
		fz_catch(error, "trying to air");
		error = pdf_repairxref(app->xref, filename);
		if (error)
			pdfapp_error(app, error);
	}

	error = pdf_decryptxref(app->xref);
	if (error)
		pdfapp_error(app, error);
#else
	file = fz_open_fd(fd);
	error = pdf_open_xref_with_stream(&app->xref, file, NULL);
	if (error)
		pdfapp_error(app, fz_rethrow(error, "cannot open document '%s'", filename));
	fz_close(file);
#endif

	/*
	 * Handle encrypted PDF files
	 */

	if (pdf_needs_password(app->xref))
	{
		int okay = pdf_authenticate_password(app->xref, password);
		while (!okay)
		{	
		        //password = winpassword(app, filename);
			if (!password)
				exit(1);
			okay = pdf_authenticate_password(app->xref, password);
			if (!okay)
				pdfapp_warn(app, "Invalid password.");
		}
	}

	/*
	 * Load meta information
	 * TODO: move this into mupdf library
	 */

#if 0
	obj = fz_dictgets(app->xref->trailer, "Root");
	app->xref->root = fz_resolveindirect(obj);
	if (!app->xref->root)
		pdfapp_error(app, fz_throw("syntaxerror: missing Root object"));
	fz_keepobj(app->xref->root);

	obj = fz_dictgets(app->xref->trailer, "Info");
	app->xref->info = fz_resolveindirect(obj);
	if (!app->xref->info)
		pdfapp_warn(app, "Could not load PDF meta information.");
	if (app->xref->info)
		fz_keepobj(app->xref->info);

	/*app->outline = pdf_loadoutline(app->xref);*/

	app->doctitle = filename;
	if (strrchr(app->doctitle, '\\'))
		app->doctitle = strrchr(app->doctitle, '\\') + 1;
	if (strrchr(app->doctitle, '/'))
		app->doctitle = strrchr(app->doctitle, '/') + 1;
	if (app->xref->info)
	{
		obj = fz_dictgets(app->xref->info, "Title");
		if (obj)
		{
			app->doctitle = pdf_toutf8(obj);
		}
	}
#else
	app->outline = pdf_load_outline(app->xref);

	app->doctitle = filename;
	if (strrchr(app->doctitle, '\\'))
		app->doctitle = strrchr(app->doctitle, '\\') + 1;
	if (strrchr(app->doctitle, '/'))
		app->doctitle = strrchr(app->doctitle, '/') + 1;
	info = fz_dict_gets(app->xref->trailer, "Info");
	if (info)
	{
		obj = fz_dict_gets(info, "Title");
		if (obj)
			app->doctitle = pdf_to_utf8(obj);
	}
#endif

	/*
	 * Start at first page
	 */

#if 0
	app->pagecount = pdf_getpagecount(app->xref);
#else
	error = pdf_load_page_tree(app->xref);
	if (error)
		pdfapp_error(app, fz_rethrow(error, "cannot load page tree"));

	app->pagecount = pdf_count_pages(app->xref);
#endif
	
	app->rotate = 0;
	
}

void pdfapp_close(pdfapp_t *app)
{
#if 0
	if (app->page)
		pdf_droppage(app->page);
	app->page = nil;

	if (app->image)
		fz_droppixmap(app->image);
	app->image = nil;

/*	if (app->outline)
		pdf_dropoutline(app->outline);
	app->outline = nil;*/

	if (app->xref->store)
		pdf_dropstore(app->xref->store);
	app->xref->store = nil;

	pdf_closexref(app->xref);
	app->xref = nil;
#else
	if (app->cache)
		fz_free_glyph_cache(app->cache);
	app->cache = NULL;

	if (app->image)
		fz_drop_pixmap(app->image);
	app->image = NULL;

	if (app->outline)
		pdf_free_outline(app->outline);
	app->outline = NULL;

	if (app->xref)
	{
		if (app->xref->store)
			pdf_free_store(app->xref->store);
		app->xref->store = NULL;

		pdf_free_xref(app->xref);
		app->xref = NULL;
	}

	fz_flush_warnings();
#endif

}



