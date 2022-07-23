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
}

void	move(t_data *data, int y, int x)
{
	move_show_count(data);
	condetion42(data, y, x);
	move_rotated(data);
}
void	move_rotated(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	destroy(data);
	respone2(data);
	respone_obj(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,data->player_x, data->player_y);
}