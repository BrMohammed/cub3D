#include "cub.h"

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
	int x = 0;
	int y = 0;
	int faux = 0;
	
	if (key == 53)
	{
		exit(0);
	}
	
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if(data->result[y][x] == 'P' && faux == 0)
			{
				faux = 1;
				g_d = data->result[y][x + 1];
				g_w = data->result[y - 1][x];
				g_a = data->result[y][x - 1];
				g_s = data->result[y + 1][x];
				if (data->win == 0 && (key == 2 || key == 124) && (g_d == '0'
					|| g_d == 'P' || g_d == 'C' || g_d == 'E' || g_d == 'A'))
						move(data, g_d, 0, 1);
				if (data->win == 0 && (key == 0 || key == 123) && (g_a == '0'
					|| g_a == 'P' || g_a == 'C' || g_a == 'E' || g_a == 'A'))
						move(data, g_a, 0, -1);
				if (data->win == 0 && (key == 13 || key == 126) && (g_w == '0'
					|| g_w == 'P' || g_w == 'C' || g_w == 'E' || g_w == 'A'))
						move(data, g_w, -1, 0);
				if (data->win == 0 && (key == 1 || key == 125) && (g_s == '0'
					|| g_s == 'P' || g_s == 'C' || g_s == 'E' || g_s == 'A'))
						move(data, g_s, 1, 0);
				if (data->coin_point == 0)
					door_open(data, 'E');
			}
			x++;
		}
		x = 0;
		y++;
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
				if (data->result[f][t] == 'P' )
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
	//t_data	data;
	//int		fd;
	//int		error;
	//int 	id;
	//char* temp;

	if (av[1])
		check_cub(av[1]);
	check_map(av[1]);
	//error = 1;
	(void) ac;
	// if (ac == 2)
	// {
	// 	fd = open(av[1], O_RDONLY);
	// 	error = read(fd, data.bufer, 1000);
	// 	data.bufer[error] = '\0';
	// 	close(fd);
	// 	data.result = ft_split(data.bufer, '\n');
	// 	error_game(data.result, error, fd, data.bufer);
	// 	respone(&data);
	// 	respone_obj(&data);
	// 	mlx_key_hook(data.mlx_win, &key, &data);
	// 	mlx_mouse_hook (data.mlx_win, &keymouse, &data);
	// 	mlx_hook(data.mlx_win, 17, (1L << 17), &mouse, &data);
	// 	mlx_loop_hook(data.mlx, &hole_move, &data);
	//     mlx_loop(data.mlx);
	// 	free(data.mlx);
	// }
	return (0);
}
