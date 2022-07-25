#include "Includes/cub.h"

int	mouse(void)
{
	exit(0);
	return (0);
}

void	draw_line(t_data *game, int *begin, int *end, int color)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	//printf("%d \n",pixels);
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, pixel[0], pixel[1], color);
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
}

int	key(int key, t_data *data)
{
	
	if (key == 53)
	{
		exit(0);
	}
	
	if (key == 2) //d
	{
		move(data,cos(-data->pa) * 5 ,-sin(data->pa) * 5);
		ray_colesion(data);
	}
	if ( key == 0 )//a
	{
		move(data,-cos(-data->pa) * 5 ,-sin(-data->pa) * 5);
		ray_colesion(data);
	}	
	if (key == 13 )//w
	{
		move(data, sin(data->pa) * 5, cos(data->pa) * 5);
		ray_colesion(data);
	}
	if (key == 1)//s
	{
		move(data, -sin(data->pa) * 5, -cos(data->pa) * 5);
		ray_colesion(data);
	}
	if(key == 123)
	{
		data->pa -= 0.02;
		if(data->pa < 0)
			data->pa += 2 * M_PI;
		move_rotated(data);
		ray_colesion(data);
	}
	if(key == 124)
	{
		data->pa += 0.02;
		if(data->pa > 2 * M_PI)
			data->pa -= 2 * M_PI;
		move_rotated(data);
		ray_colesion(data);
	}
	return(0);
}

void	check_cub(char *str)
{
	int		i;
	char	*cub;
	int		l;

	cub = "buc.";
	i = 0;
	while (str[i])
			i++;
	i--;
	l = 0;
	while (cub[l] != '\0')
	{
		if (cub[l] != str[i])
			exit(0);
		l++;
		i--;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (av[1])
		check_cub(av[1]);
	data.result = check_map(av[1],&data);
	(void) ac;
	if (ac == 2)
	{
		respone(&data);
		respone_obj(&data);
		mlx_hook(data.mlx_win, 2, 1L<<0, key, &data);
		mlx_hook(data.mlx_win, 17, (1L << 17), &mouse, &data);
	    mlx_loop(data.mlx);
		free(data.mlx);
	}
	return (0);
}
