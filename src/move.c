#include "../Includes/cub.h"

void	move_show_count(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	destroy(data);
	respone2(data);
	respone_obj(data);
}

static void	condetion42(t_data *data, int y, int x)
{
	data->player_x = x + data->player_x;
	data->player_y = y + data->player_y;
	mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,data->player_x, data->player_y);
}

void	move(t_data *data, int y, int x)
{
	move_show_count(data);
	condetion42(data, y, x);
	ray_colesion(data);
	move_rotated(data);
}
void	move_rotated(t_data *data)
{
	int a[2];
	int b[2];
	mlx_clear_window(data->mlx, data->mlx_win);
	destroy(data);
	respone2(data);
	respone_obj(data);
	data->pdy = cos(data->pa) * -data->lenght_of_ray;
	data->pdx = sin(data->pa) * -data->lenght_of_ray;
	mlx_pixel_put(data->mlx,data->mlx_win,(data->player_x + 7.5) + data->pdx  * data->lenght_of_ray, (data->player_y + 7.5) + data->pdy * data->lenght_of_ray,0Xff0000);
	mlx_pixel_put(data->mlx,data->mlx_win,(data->player_x + 7.5), (data->player_y + 7.5),0Xff0000);
	a[0] = data->player_x + 7.5;
	a[1] = data->player_y + 7.5;
	b[0] = (data->player_x + 7.5) + data->pdx  * data->lenght_of_ray;
	b[1] = (data->player_y + 7.5) + data->pdy * data->lenght_of_ray;
	draw_line(data, a, b, 0Xff0000);
	mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,data->player_x, data->player_y);
	//printf("%f, %f, %f\n",data->pdx,data->pdy,data->pa);
	//printf("%f\n",data->lenght_of_ray);
	
}