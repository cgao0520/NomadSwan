/////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "log.h"
#include <3ds.h>
#include "font8.h"
#include <string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
// static global variables
/////////////////////////////////////////////////////////////////////////////////////////////////
static FILE* log_stream = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////
int log_init(const char* path)
{
	return 1;
	/*
  if (log_stream != NULL)
    log_done();

  return ((log_stream = fopen(path, "wrt")) == NULL ? 0 : 1);*///c_gao
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////


int log_write(const char* format, ...) {
	return 1;
	/*
		static CRGBA text_clr(0,255,0,0);
		static CRGBA bk_clr(0,0,0,0);
		CFont8 font(_fbb,text_clr,bk_clr);
		static char slog[300];
		static int i=0;

memset(slog,0,300);
  va_list ap;
  int     result;

  va_start(ap, format);
  result = vsprintf(slog, format, ap);
  va_end(ap);		
		
	font.DrawString(i++,0,slog);
	if(i>=200) i=0;
		
		return 1;*/
/*
  if (log_stream == NULL)
    return 0;

  va_list ap;
  int     result;

  va_start(ap, format);
  result = vfprintf(log_stream, format, ap);
  va_end(ap);

  return (result < 0 ? 0 : 1);*///c_gao
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////
void log_done(void)
{/*
  fclose(log_stream);
  log_stream = NULL;*///c_gao
}
