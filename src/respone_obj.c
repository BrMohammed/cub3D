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
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->walls, x * 50, y * 50);
			}
			else if (data->result[y][x] == 48 || data->result[y][x] == 'N')
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->plat, x * 50, y * 50);
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
			if (data->result[y][x] == 'N')
			{
				data->player_y = y * 50;
				data->player_x = x * 50;
				ray_colesion(data);
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,data->player_x, data->player_y);
				data->result[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
}
