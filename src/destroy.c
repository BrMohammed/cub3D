#include "../Includes/cub.h"

void destroy(t_data *data)
{
    mlx_destroy_image(data->mlx,data->walls);
    mlx_destroy_image(data->mlx,data->plat);
	mlx_destroy_image(data->mlx,data->player);
}

void respone2(t_data *data)
{
    data->walls = mlx_xpm_file_to_image(data->mlx, data->walls_path,
			&data->img_width, &data->img_height);
	data->plat = mlx_xpm_file_to_image(data->mlx, data->plat_path,
			&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, data->player_path,
			&data->img_width, &data->img_height);
}