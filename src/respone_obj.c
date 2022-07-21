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
			if (data->result[fd][i] == 49 )
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->walls, i * 50, fd * 50);
			}
			else if (data->result[fd][i] == 48 || data->result[fd][i] == 'N')
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->plat, i * 50, fd * 50);
			i++;
		}
		i = 0;
		fd++;
	}
	fd = 0;
	i = 0;
	while (data->result[fd] != '\0')
	{
		while (data->result[fd][i] != '\0')
		{
			if (data->result[fd][i] == 'N')
			{
				data->player_x = i * 50;
				data->player_y = fd * 50;
				ray_colesion(data);
				data->pdy = cos(data->pa) * -data->lenght_of_ray;
				data->pdx = sin(data->pa) * 0;
				int a[2];
				int b[2];
				mlx_pixel_put(data->mlx,data->mlx_win,(data->player_x + 7.5) + data->pdx  * data->lenght_of_ray, (data->player_y + 7.5) + data->pdy * data->lenght_of_ray,0Xff0000);
				mlx_pixel_put(data->mlx,data->mlx_win,(data->player_x + 7.5), (data->player_y + 7),0Xff0000);
				a[0] = data->player_x + 7.5;
				a[1] = data->player_y + 7.5;
				b[0] = (data->player_x + 7.5) + data->pdx  * data->lenght_of_ray;
				b[1] = (data->player_y + 7.5) + data->pdy * data->lenght_of_ray;
				draw_line(data, a, b, 0Xff0000);
				mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,data->player_x, data->player_y);
				data->result[fd][i] = '0';
				//printf("%f, %f, %f\n",data->pdx,data->pdy,data->pa);
			}
			i++;
		}
		i = 0;
		fd++;
	}
}
