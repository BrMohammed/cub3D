#include "../Includes/cub.h"

void	respone(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->result[y])
	{
		while (data->result[0][x])
			x++;
		y++;
	}
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, x * 50, y * 50, "cub3d");
	data->img.mlx_img = mlx_new_image(data->mlx,x * 50, y * 50);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
}
