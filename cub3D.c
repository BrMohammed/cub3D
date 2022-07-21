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
		move(data, 0, 5);
		
	}
	if ( key == 0 )//a
	{
		
		move(data, 0, -5);
	}	
	if (key == 13 )//w
	{
		
		move(data, -5, 0);
	}
	if (key == 1)//s
	{
		move(data, 5, 0);
	}
	if(key == 124)
	{
		data->pa -= 0.1;
		if(data->pa < 0)
		{
			data->pa += 2 * pi;
		}
		data->pdy = cos(data->pa) * -data->lenght_of_ray;
		data->pdx = sin(data->pa) * -data->lenght_of_ray;
		move_rotated(data);
	}
	if(key == 123)
	{
		data->pa += 0.1;
		if(data->pa >  2 * pi)
		{
			data->pa -= 2 * pi;
		}
		data->pdy = cos(data->pa) * -data->lenght_of_ray;
		data->pdx = sin(data->pa) * -data->lenght_of_ray;
		move_rotated(data);
	}
	return(0);
}

int key_roted(int key, t_data *data)
{
	if(key == 124)
	{
		data->pa -= 0.1;
		if(data->pa < 0)
		{
			data->pa += 2 * pi;
		}
		data->pdy = cos(data->pa) * -data->lenght_of_ray;
		data->pdx = sin(data->pa) * -data->lenght_of_ray;
		move_rotated(data);
	}
	if(key == 123)
	{
		data->pa += 0.1;
		if(data->pa >  2 * pi)
		{
			data->pa -= 2 * pi;
		}
		data->pdy = cos(data->pa) * -data->lenght_of_ray;
		data->pdx = sin(data->pa) * -data->lenght_of_ray;
		move_rotated(data);
	}
	return (0);
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


int keymouse(int button, int x,int y,t_data *data)
{
	int t = 0;
	int f = 0;
	int v[2] = {y/80,x/80};
	if (button == 1)
	{
		while (data->result[f] != '\0')
		{
			while (data->result[f][t] != '\0')
			{
				if (data->result[f][t] == 'N' )
				{
					if (v[0] != f )
					{
						if(f < v[0])
						{
							key(1,data);
						}
						if(f > v[0])
						{
							key(13,data);
							f = 0;
						}
					}
					if (v[1] != t )
					{
						if(t < v[1])
						{
							key(2,data);
						}
						if(t > v[1])
						{
							key(0,data);
							f = 0;
						}
					}
				}
				t++;
			}
			t = 0;
			f++;
		}
	}
	return(0);
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
		//pixel_of_ray_size = lenght_of_ray * 2
		//data.result_lenght = 2;
		respone(&data);
		respone_obj(&data);
		mlx_hook(data.mlx_win, 2, 1L<<0, key, &data);
		//mlx_hook(data.mlx_win, 2, 1L<<0, key_roted, &data);
		//mlx_key_hook(data.mlx_win, &key, &data);
		mlx_mouse_hook (data.mlx_win, &keymouse, &data);
		mlx_hook(data.mlx_win, 17, (1L << 17), &mouse, &data);
		// mlx_loop_hook(data.mlx, &hole_move, &data);
	    mlx_loop(data.mlx);
		free(data.mlx);
	}
	return (0);
}
