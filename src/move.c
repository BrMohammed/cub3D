#include "../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	destroy(data);
	respone2(data);
	respone_obj(data);
}

void	move(t_data *data, int y, int x)
{
	data->player_x += x;
	data->player_y += y ;
	data->player_y_for_3d += y;
	data->player_x_for_3d += x;
	//move_rotated(data);
}
void	move_rotated(t_data *data)
{
	destroy_and_refresh(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->point_map, data->player_x - (data->player_mini_res / 1.7),  data->player_y - (data->player_mini_res / 1.7));
}