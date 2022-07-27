#include "../Includes/cub.h"

void	respone_obj(t_data *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	rander_image(&data->img, (t_rect){0, data->result_hight/2 * 50,data->result_with   * 50,   data->result_hight/2 * 50, 16777121});
	rander_image(&data->img, (t_rect){0, 0 * 50,data->result_with   * 50,   data->result_hight/2 * 50, 56831});
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 49 )
				rander_image(&data->img, (t_rect){x * 10, y * 10,10, 10, 9524926});
			else if (data->result[y][x] == 48 || data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
					data->result[y][x] == 'W' || data->result[y][x] == 'E')
					rander_image(&data->img, (t_rect){x * 10, y * 10,10, 10, 11796399});
			else
				rander_image(&data->img, (t_rect){x * 10, y * 10,10, 10, 0});
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
				data->player_y = y * 10;
				data->player_x = x * 10;
				rander_image(&data->img, (t_rect){data->player_x, data->player_y,4, 4, 20963});
				data->result[y][x] = '0';
				ray_colesion(data);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if(data->result[y] == '\0')
		ray_colesion(data);
}
