#include "../Includes/cub.h"


void	respone(t_data *data)
{
	int	x;
	int	y;
	int i = 0;


	x = 0;
	y = 0;
	while (data->result[y])
	{
		while (data->result[0][x])
			x++;
		y++;
	}
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->demintion_with, data->demension_hight, "cub3d");
	data->img.mlx_img = mlx_new_image(data->mlx,data->demintion_with, data->demension_hight);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	x = 0;
	y = 0;
	i = 0;

	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 50)
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	y = 0;
	data->counter_of_sprites = i;
	data->pos_of_sprite_x = malloc(sizeof(int) * (i));
	data->pos_of_sprite_y = malloc(sizeof(int) * (i));	
	i = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 50)
			{
				data->pos_of_sprite_x[i] = (x * 10) + 5;
				data->pos_of_sprite_y[i] = (y * 10) + 5;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
