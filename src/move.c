#include "../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	//destroy(data);
	respone2(data);
	respone_obj(data);
}

void	move(t_data *data, int y, int x)
{
	data->player_x += x;
	data->player_y += y ;
	data->player_y_for_3d += y;
	data->player_x_for_3d += x;
	//move_rotated(data);
}
static void	condetion_number(t_data *data, int *t, char *c, int *i)
{
	if (c[*i] == '2')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number2, *t, 0);
	if (c[*i] == '3')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number3, *t, 0);
	if (c[*i] == '4')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number4, *t, 0);
	if (c[*i] == '5')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number5, *t, 0);
	if (c[*i] == '6')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number6, *t, 0);
	if (c[*i] == '7')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number7, *t, 0);
	if (c[*i] == '8')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number8, *t, 0);
	if (c[*i] == '9')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number9, *t, 0);
}
void	move_show_count(t_data *data)
{
	char	*c;
	int		i;
	int		t;
	int		v;

	i = 0;
	t = 0;
	v = 0;
	c = ft_itoa(data->coin_count);
	while (c[i] != '\0')
	{	
		if (c[i] == '0')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->number.number0, t, 0);
		if (c[i] == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->number.number1, t, 0);
		condetion_number(data, &t, c, &i);
		t += 40;
		i++;
		v += 80;
	}
	free(c);
}
void	move_rotated(t_data *data)
{
	int begin[2];
	int end[2];
	int i;
	destroy_and_refresh(data);
	begin[0] =  (data->player_x) ;
	begin[1] = (data->player_y + (data->player_mini_res));
	end[0] = data->player_x ;
	end[1]= data->player_y ;
	draw_linev4_for_static_imgs(data, begin,end,data->player_mini_res,data->img_mini_player.addr,data->img_mini_player.line_len);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	i = 0;
	while(i < data->counter_of_sprites)
	{
		if(data->pos_of_sprite_y[i] + (data->mini_map_res / 2) > data->player_y && data->pos_of_sprite_y[i] - (data->mini_map_res / 2) < data->player_y
			&& data->pos_of_sprite_x[i] + (data->mini_map_res / 2) > data->player_x && data->pos_of_sprite_x[i] - (data->mini_map_res / 2) < data->player_x)
		{
			data->result[(data->pos_of_sprite_y[i] -(( data->pos_of_sprite_y[i] % data->mini_map_res))) / 10][(data->pos_of_sprite_x[i] -(( data->pos_of_sprite_x[i] % data->mini_map_res))) / 10] = '0';
			data->pos_of_sprite_y[i] = 0;
			data->pos_of_sprite_x[i] = 0;
			data->coin_count++;
		}
		i++;
	}
	move_show_count(data);
}