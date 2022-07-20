#include "../Includes/cub.h"

void	path(t_data *data)
{
	data->player_path = "./assets/player.xpm";
	data->walls_path = "./assets/wall.xpm";
	data->plat_path = "./assets/plat.xpm";
}

void	x_y(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[0][x] != '\0')
			x++;
		y++;
	}
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, x * 15, y * 15, "cub3d");
}

void	respone(t_data *data)
{
	x_y(data);
	path(data);
	data->walls = mlx_xpm_file_to_image(data->mlx, data->walls_path,
			&data->img_width, &data->img_height);
	data->plat = mlx_xpm_file_to_image(data->mlx, data->plat_path,
			&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, data->player_path,
			&data->img_width, &data->img_height);
}
