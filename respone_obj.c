#include "cub.h"

void	respone_obj(t_data *data)
{
	int	fd;
	int i;

	fd = 0;
	i = 0;
	data->coin_point = 0;
	while (data->result[fd] != '\0')
	{
		while (data->result[fd][i] != '\0')
		{
			if (data->result[fd][i] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->walls, i * 80, fd * 80);
			}
			else if (data->result[fd][i] == '0' || data->result[fd][i] == 'P'
				|| data->result[fd][i] == 'C'
				||data->result[fd][i] == 'E' || data->result[fd][i] == 'A')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->plat, i * 80, fd * 80);
				if (data->result[fd][i] == 'P')
				{
					mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->player,i * 80, fd * 80);
				}
				if (data->result[fd][i] == 'C')
				{
					mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->coin, i * 80, fd * 80);
					data->coin_point++;
				}
				if (data->result[fd][i] == 'A')
				{
					mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->hole, i * 80, fd * 80);
				}
				if (data->result[fd][i] == 'E')
				{
					mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->door_open,i * 80, fd * 80);
				}
			i++;
		}
		i = 0;
		fd++;
	}
}
