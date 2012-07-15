/*
 * Utility object for handling a pdf application / view
 * Takes care of PDF loading and displaying and navigation,
 * uses a number of callbacks to the GUI app.
 */

typedef struct pdfapp_s pdfapp_t;

struct pdfapp_s
{
	/* current document params */
	char *filename;
	char *doctitle;
	pdf_xref *xref;
#if 0	
	/*pdf_outline *outline;*/
	fz_renderer *rast;

	int pagecount;
#else
	pdf_outline *outline;

	int pagecount;
	fz_glyph_cache *cache;
#endif

	/* current view params */
	float zoom;
	int rotate;
	fz_pixmap *image;

#if 0
	/* current page params */
	int pageno;
	pdf_page *page;
#else
	/* current page params */
	int pageno;
	fz_rect page_bbox;
	float page_rotate;
	fz_display_list *page_list;
	fz_text_span *page_text;
	pdf_link *page_links;
#endif

	/* window system sizes */
	int scrw, scrh;
};

void pdfapp_init(pdfapp_t *app);
void pdfapp_open(pdfapp_t *app, char *filename);
void pdfapp_close(pdfapp_t *app);

