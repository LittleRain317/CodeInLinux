#include "mysetbuf.h"

void mysetbuf(FILE *stream, char *buf)
{
	if (NULL == buf)
	{
		setvbuf(stream, NULL, _IONBF, 0U);
	}
	else
	{
		if (stream->_flags & _IO_LINE_BUF)
		{
			setvbuf(stream, buf, _IOLBF, BUFSIZ);
		}
		else if (stream->_flags & _IO_UNBUFFERED)
		{
			setvbuf(stream, buf, _IOFBF, BUFSIZ);
		}
		else 
		{
			setvbuf(stream, buf, _IOFBF, BUFSIZ);
		}
	}
}

