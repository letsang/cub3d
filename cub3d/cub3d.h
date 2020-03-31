#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <X11/X.h>
#include "./mlx/mlx.h"

#ifndef	HAVE_STRLCAT
size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = strlen(dst);
	size -= dstlen + 1;

	if (!size)
		return (dstlen);
	srclen = strlen(src);
	if (srclen > size)
		srclen = size;
	memcpy(dst + dstlen, src, srclen);
	dst[dstlen + srclen] = '\0';
	return (dstlen + srclen);
}
#endif /* !HAVE_STRLCAT */

#ifndef HAVE_STRLCPY
size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	size--;
	srclen = strlen(src);
	if (srclen > size)
		srclen = size;
	memcpy(dst, src, srclen);
	dst[srclen]	= '\0';
	return (srclen);
}
#endif /* !HAVE_STRLCPY */

#define WIDTH	640
#define HEIGHT	480

#define PI	3.1415926535

#define	ESC	65307
#define	Z	122
#define	Q	113
#define	S	115
#define	D	100

#define RED	0xFF0000
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define YELLOW	0xFFFF00

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

#endif /* CUB3D_H */
