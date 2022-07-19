#include "../Includes/cub.h"

void	path(t_data *data)
{
	data->player_path = "./assets/idle01.xpm";
	data->walls_path = "./assets/square2.xpm";
	data->plat_path = "./assets/pack.xpm";
	data->coin_path = "./assets/f1.xpm";
	data->coin_path1 = "./assets/f2.xpm";
	data->door_cloce_path = "./assets/closedoor.xpm";
	data->door_open_path = "./assets/opendoor.xpm";
	data->player_left_path = "./assets/Idle_left.xpm";
	data->dead_path = "./assets/dead.xpm";
	data->hole_path = "./assets/ghost.xpm";
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
	if (y > 19 || x > 36)
	{
		printf("%s\n", "ERROR");
		exit(0);
	}
	data->mlx_win = mlx_new_window(data->mlx, x * 80, y * 80, "so_long");
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
	data->dead = mlx_xpm_file_to_image(data->mlx, data->dead_path,
			&data->img_width, &data->img_height);
	data->hole = mlx_xpm_file_to_image(data->mlx, data->hole_path,
			&data->img_width, &data->img_height);
}
