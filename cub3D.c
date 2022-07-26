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

int	key_down(int key, t_data *data)
{
	// if (key == 53)
	// {
	// 		exit(0);
	// }
	
	if (key == 2) //d
	{
		data->ON_KEYDOWN_DERECTION = 1;
		data->KEY_D = 1;
	}
	if ( key == 0 )//a
	{
		data->ON_KEYDOWN_DERECTION = 1;
		data->KEY_A = 1;
	}	
	if (key == 13 )//w
	{
		data->ON_KEYDOWN_DERECTION = 1;
		data->KEY_W = 1;
	}
	if (key == 1)//s
	{
		data->ON_KEYDOWN_DERECTION = 1;
		data->KEY_S = 1;
	}
	if(key == 123)
	{

	}
	if(key == 124)
	{
		data->ON_KEYDOWN_CAMERA = 1;
		data->KEY_WRIGHT = 1;
	}
	return(0);
}

int	key_up(int key, t_data *data)
{
	
	// if (key == 53)
	// {
	// 	exit(0);
	// }
	
	if (key == 2) //d
	{
		data->ON_KEYUP_DERECTION = 0;
		data->KEY_D = 0;
	}
	if ( key == 0 )//a
	{
		
	}	
	if (key == 13 )//w
	{
		
	}
	if (key == 1)//s
	{
		
	}
	if(key == 123)
	{
		
	}
	if(key == 124)
	{
		data->ON_KEYUP_CAMERA = 0;
		data->KEY_WRIGHT = 0;
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

int	movement(t_data *data)
{

	static int i;

	if(i == 200)
	{
		if(data->ON_KEYDOWN_DERECTION == 1)
		{
			if(data->KEY_D == 1)
			{
				move(data,cos(-data->pa) * 5 ,-sin(data->pa) * 5);
				ray_colesion(data);
			}
		}
		if(data->ON_KEYDOWN_CAMERA == 1)
		{
			if(data->KEY_WRIGHT == 1)
			{
				data->pa += 0.02;
				if(data->pa > 2 * M_PI)
					data->pa -= 2 * M_PI;
				move_rotated(data);
				ray_colesion(data);
			}
		}
		i=0;
	}
	i++;
	return (0);
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
		mlx_hook(data.mlx_win, 2, 0, key_down, &data);
		mlx_hook(data.mlx_win, 3, 0, key_up, &data);
		mlx_loop_hook(data.mlx, &movement, &data);
		mlx_hook(data.mlx_win, 17, (1L << 17), &mouse, &data);
	    mlx_loop(data.mlx);
		free(data.mlx);
	}
	return (0);
}
