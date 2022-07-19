#include "cub.h"

void destroy(t_data *data)
{
    mlx_destroy_image(data->mlx,data->walls);
    mlx_destroy_image(data->mlx,data->plat);
	mlx_destroy_image(data->mlx,data->player);
	mlx_destroy_image(data->mlx,data->coin);
	mlx_destroy_image(data->mlx,data->coin1);
	mlx_destroy_image(data->mlx,data->door_close);
	mlx_destroy_image(data->mlx,data->door_open);
	mlx_destroy_image(data->mlx,data->player_left);
}

void respone2(t_data *data)
{
    data->walls = mlx_xpm_file_to_image(data->mlx, data->walls_path,
			&data->img_width, &data->img_height);
	data->plat = mlx_xpm_file_to_image(data->mlx, data->plat_path,
			&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, data->player_path,
			&data->img_width, &data->img_height);
	data->coin = mlx_xpm_file_to_image(data->mlx, data->coin_path,
			&data->img_width, &data->img_height);
	data->coin1 = mlx_xpm_file_to_image(data->mlx, data->coin_path1,
			&data->img_width, &data->img_height);
	data->door_close = mlx_xpm_file_to_image(data->mlx, data->door_cloce_path,
			&data->img_width, &data->img_height);
	data->door_open = mlx_xpm_file_to_image(data->mlx, data->door_open_path,
			&data->img_width, &data->img_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, data->player_left_path,
			&data->img_width, &data->img_height);
}