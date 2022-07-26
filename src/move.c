#include "../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	respone2(data);
	respone_obj(data);
}

static void	condetion42(t_data *data, int y, int x)
{
	data->player_x = x + data->player_x;
	data->player_y = y + data->player_y;
}

void	move(t_data *data, int y, int x)
{
	destroy_and_refresh(data);
	condetion42(data, y, x);
	move_rotated(data);
}
void	move_rotated(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	respone2(data);
	respone_obj(data);
	rander_image(&data->img, (t_rect){data->player_x, data->player_y,15, 15, 20963});
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
}