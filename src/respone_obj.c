#include "../Includes/cub.h"

void	respone_obj(t_data *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 49 )
			{
				rander_image(&data->img, (t_rect){x * 50, y * 50,50, 50, 9524926});
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
			}
			else if (data->result[y][x] == 48 || data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
					data->result[y][x] == 'W' || data->result[y][x] == 'E')
				{
					rander_image(&data->img, (t_rect){x * 50, y * 50,50, 50, 11796399});
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
				}
				
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
				data->result[y][x] == 'W' || data->result[y][x] == 'E')
			{
				if(data->result[y][x] == 'N')
					data->pa = (3 * M_PI) / 2;
				if(data->result[y][x] == 'S')
					data->pa = (M_PI) / 2;
				if(data->result[y][x] == 'E')
					data->pa = 0;
				if(data->result[y][x] == 'W')
					data->pa = (M_PI);
				data->player_y = y * 50;
				data->player_x = x * 50;
				ray_colesion(data);
				rander_image(&data->img, (t_rect){data->player_x, data->player_y,15, 15, 20963});
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
				data->result[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
}
