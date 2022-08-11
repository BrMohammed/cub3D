#include "../Includes/cub.h"

void	img_pix_put(t_img *img, int x, int y, int color,t_data *data)
{
	char    *pixel;

   	color = mlx_get_color_value(data->mlx, color);
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color  + (20 << 24);
}

int rander_image(t_img *img, t_rect rect,t_data *data)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			
			img_pix_put(img, j++, i, rect.color,data);
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