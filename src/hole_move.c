#include "../Includes/cub.h"

static int	g_temp;
int			g_x;
int			g_y;

void	hole_b(t_data *data, char v, int move)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->plat, g_x * 80, g_y * 80);
	data->result[g_y][g_x] = '0';
	if (move == 1)
		g_y += 1;
	if (move == 2)
		g_y -= 1;
	if (move == 3)
		g_x -= 1;
	if (move == 4)
		g_x += 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->hole, g_x * 80, g_y * 80);
	data->result[g_y][g_x] = 'A';
	if (v == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->plat, g_x * 80, g_y * 80);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hole, g_x * 80, g_y * 80);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->dead, g_x * 80, g_y * 80);
		data->win = 1;
	}
}

void	conditions(t_data *data)
{
	char		d;
	char		w;
	char		a;
	char		s;

	d = data->result[g_y][g_x + 1];
	w = data->result[g_y - 1][g_x];
	a = data->result[g_y][g_x - 1];
	s = data->result[g_y + 1][g_x];
	if (w == '1' || w == 'C' || w == 'E' || w == 'A')
		g_temp = 1;
	if (s == '1' || s == 'C' || s == 'E' || s == 'A')
		g_temp = 0;
	if (a == '1' || a == 'C' || a == 'E' || a == 'A')
		g_temp = 2;
	if (d == '1' || d == 'C' || d == 'E' || d == 'A')
		g_temp = 3;
	if ((s == '0' && g_temp == 1) || (s == 'P' && g_temp == 1))
		hole_b(data, s, 1);
	if ((w == '0' && g_temp == 0) || (w == 'P' && g_temp == 0))
		hole_b(data, w, 2);
	if ((a == '0' && g_temp == 3) || (a == 'P' && g_temp == 3))
		hole_b(data, a, 3);
	if ((d == '0' && g_temp == 2) || (d == 'P' && g_temp == 2))
		hole_b(data, d, 4);
}

void	flower(t_data *data)
{
	g_x = 0;
	g_y = 0;
	while (data->result[g_y] != '\0')
	{
		while (data->result[g_y][g_x] != '\0')
		{
			if (data->result[g_y][g_x] == 'C')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->coin1, g_x * 80, g_y * 80);
			g_x++;
		}
		g_x = 0;
		g_y++;
	}
}

void	just25_2(t_data *data)
{
	g_x = 0;
	g_y = 0;
	while (data->result[g_y] != '\0')
	{
		while (data->result[g_y][g_x] != '\0')
		{
			if (data->result[g_y][g_x] == 'A')
				conditions(data);
			if (data->result[g_y][g_x] == 'C')
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->coin, g_x * 80, g_y * 80);
			g_x++;
		}
		g_x = 0;
		g_y++;
	}
}

int	hole_move(t_data *data)
{
	static int	i;

	if (i == 3000)
		flower(data);
	if (i == 6000 && data->win != 1)
	{
		just25_2(data);
		i = 0;
	}
	i++;
	return (0);
}
