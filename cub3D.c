#include "Includes/cub.h"

char	g_d;
char	g_w;
char	g_a;
char	g_s;

void	door_open(t_data *data, char temp)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (data->result[i] != '\0')
	{
		while (data->result[i][t] != '\0')
		{
			if (data->result[i][t] == temp)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->door_close, t * 80, i * 80);
			}
			t++;
		}
		t = 0;
		i++;
	}
}

int	mouse(void)
{
	exit(0);
	return (0);
}

int	key(int key, t_data *data)
{
	
	if (key == 53)
	{
		exit(0);
	}
	
	if (data->win == 0 && (key == 2 || key == 124))
			move(data, g_d, 0, 5);
	if (data->win == 0 && (key == 0 || key == 123))
			move(data, g_a, 0, -5);
	if (data->win == 0 && (key == 13 || key == 126) )
			move(data, g_w, -5, 0);
	if (data->win == 0 && (key == 1 || key == 125))
			move(data, g_s, 5, 0);
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
	data.result = check_map(av[1]);
	(void) ac;
	if (ac == 2)
	{
		respone(&data);
		respone_obj(&data);
		mlx_hook(data.mlx_win, 2, 1L<<0, key, &data);
		//mlx_key_hook(data.mlx_win, &key, &data);
		mlx_mouse_hook (data.mlx_win, &keymouse, &data);
		mlx_hook(data.mlx_win, 17, (1L << 17), &mouse, &data);
		// mlx_loop_hook(data.mlx, &hole_move, &data);
	    mlx_loop(data.mlx);
		free(data.mlx);
	}
	return (0);
}
