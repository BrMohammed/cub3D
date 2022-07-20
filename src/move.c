#include "../Includes/cub.h"

void	move_show_count(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	destroy(data);
	respone2(data);
	respone_obj(data);
}

static void	condetion42(char v, t_data *data, int y, int x)
{
	if (v == '0' || v == 'N')
	{
		int t = 0;
		int f = 0;
		while (data->result[f] != '\0')
		{
			while (data->result[f][t] != '\0')
			{
				if (data->result[f][t] == 'N')
				{
					data->result[f][t] = '0';
					t += x;
					f += y;
					data->result[f][t] = 'N';
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
	data->player_count++;
		
	condetion42(v, data, y, x);
	move_show_count(data);
}