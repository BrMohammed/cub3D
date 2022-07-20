#include "../Includes/cub.h"

void	respone_obj(t_data *data)
{
	int	fd;
	int i;

	fd = 0;
	i = 0;
	while (data->result[fd] != '\0')
	{
		while (data->result[fd][i] != '\0')
		{
			if (data->result[fd][i] == 49)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->walls, i * 15, fd * 15);
			}
			else if (data->result[fd][i] == 48)
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->plat, i * 15, fd * 15);
			if (data->result[fd][i] == 'N')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->plat, i * 15, fd * 15);
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,i * 15, fd * 15);
				data->result[fd][i] = '0';
				data->player_x = i * 15;
				data->player_y = fd * 15;
				
			}
			i++;
		}
		i = 0;
		fd++;
	}
}
