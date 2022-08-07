#include "../Includes/cub.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
		{
			*pixel++ = (color >> i) & 0xFF;
		}
			
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
	
}

int rander_image(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			
			img_pix_put(img, j++, i, rect.color);
		}
		++i;
	}
	return (0);
}

int get_pixel(char *addr,int line_len,int x, int y)
{
	char    *buffer2;
	int color;

	buffer2 = addr + (y * line_len + x * (4));
	color = *(int*)buffer2;
	return (color);
}