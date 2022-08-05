#include "../Includes/cub.h"

void	respone_obj(t_data *data)
{
	int	x;
	int y;
	int a[2];
	int b[2];

	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
				data->result[y][x] == 'W' || data->result[y][x] == 'E')
			{
				data->player_y = y * data->mini_map_res;
				data->player_x = x * data->mini_map_res;
				data->player_y_for_3d = y * data->map_res;
				data->player_x_for_3d = x * data->map_res;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ray_colesion(data);
	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 49 )
				rander_image(&data->img, (t_rect){x * data->mini_map_res, y * data->mini_map_res,data->mini_map_res, data->mini_map_res, 9524926});
			else if (data->result[y][x] == 48 || data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
					data->result[y][x] == 'W' || data->result[y][x] == 'E')
					rander_image(&data->img, (t_rect){x * data->mini_map_res, y * data->mini_map_res,data->mini_map_res, data->mini_map_res, 11796399});
			// else
			// 	rander_image(&data->img, (t_rect){x * data->mini_map_res, y * data->mini_map_res,data->mini_map_res, data->mini_map_res, 0});
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
				rander_image(&data->img, (t_rect){x * data->mini_map_res, y * data->mini_map_res,data->player_mini_res, data->player_mini_res, 22735});
				data->result[y][x] = '0';
				//mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	a[0] = data->player_x + (data->player_mini_res / 2);
    a[1] = data->player_y + (data->player_mini_res / 2);
    b[0] = a[0] + cos(data->pa) * 7;
    b[1] = a[1] + sin(data->pa) * 7;
   draw_line(data, a, b, 0Xff0000);
	//ray_colesion(data);
}
