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
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}


int get_pixel(t_data *data,int x, int y)
{
	//char    *buffer;
	char    *buffer2;
	//int pixel;
	int color;

	// buffer = data->img_rander.addr;
	buffer2 = data->img_rander.addr + (y * data->img_rander.line_len + x * (4));
	// pixel = (y * data->img_rander.line_len + x * (4));

    // if (data->img_rander.endian != 0)        // Most significant (Alpha) byte first
    // {
    //     buffer[pixel + 0] = ((*(int*)buffer2) >> 24);
    //     buffer[pixel + 1] = ((*(int*)buffer2) >> 16) & 0xFF;
    //     buffer[pixel + 2] = ((*(int*)buffer2) >> 8) & 0xFF;
    //     buffer[pixel + 3] = ((*(int*)buffer2)) & 0xFF;
    // }
    // else   // Least significant (Blue) byte first
    // {
		
    //     buffer[pixel + 0] = ((*(int*)buffer2)) & 0xFF;
    //     buffer[pixel + 1] = ((*(int*)buffer2) >> 8) & 0xFF;
    //     buffer[pixel + 2] = ((*(int*)buffer2) >> 16) & 0xFF;
    //     buffer[pixel + 3] = ((*(int*)buffer2) >> 24);
    // }
	color = *(int*)buffer2;
	return (color);
}
