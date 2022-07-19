#include "../Includes/cub.h"

void	move_show_count(t_data *data)
{
	char	*c;
	
	c = ft_itoa(data->player_count);
	mlx_clear_window(data->mlx, data->mlx_win);
	destroy(data);
	respone2(data);
	respone_obj(data);
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFFFF, c);
	free(c);
}

static void	condetion42(char v, t_data *data, int y, int x)
{
	if (v == '0' || v == 'C' || v == 'P')
	{
		int t = 0;
		int f = 0;
		while (data->result[f] != '\0')
		{
			while (data->result[f][t] != '\0')
			{
				if (data->result[f][t] == 'P')
				{
					data->result[f][t] = '0';
					t += x;
					f += y;
					data->result[f][t] = 'P';
				}
				t++;
			}
			t = 0;
			f++;
		}
	}
}

void	move(t_data *data, char v, int y, int x)
{
	int f= 0;
	int t = 0;
	data->player_count++;
	
	if (v == 'E' && data->coin_point == 0)
	{
		exit(0);
	}
		
	condetion42(v, data, y, x);
	move_show_count(data);
	if (v == 'A')
	{
		while (data->result[f] != '\0')
		{
			while (data->result[f][t] != '\0')
			{
				if (data->result[f][t] == 'A')
				{
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->plat,
						(t - x )* 80, (f - y) * 80);
					
					mlx_put_image_to_window(data->mlx, data->mlx_win, data->dead,
						t * 80, f * 80);
					data->win = 1;
				}
				t++;
			}
			t = 0;
			f++;
		}
	}
}