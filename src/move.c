#include "../Includes/cub.h"

void	move_show_count(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	destroy(data);
	respone2(data);
	respone_obj(data);
}

static void	condetion42(char v, t_data *data, int y, int x)
{
	(void)v;
	data->player_x = x + data->player_x;
	data->player_y = y + data->player_y;
	printf("%d\n",data->player_x);
	mlx_put_image_to_window(data->mlx, data->mlx_win,data->player,data->player_x, data->player_y);
}

void	move(t_data *data, char v, int y, int x)
{
	(void)v;
	data->player_count++;
	move_show_count(data);
	condetion42(v, data, y, x);
}