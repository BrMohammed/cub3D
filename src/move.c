#include "../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	destroy(data);
	//respone2(data);
	respone_obj(data);
}

void	move(t_data *data, int y, int x)
{
	data->player_x += x;
	data->player_y += y ;
	data->player_y_for_3d += y;
	data->player_x_for_3d += x;
}
static void	condetion_number(t_data *data, int *t, char *c, int *i)
{
	if (c[*i] == '0')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->number.number0, *t, 20);
		if (c[*i] == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->number.number1, *t, 20);
	if (c[*i] == '2')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number2, *t, 20);
	if (c[*i] == '3')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number3, *t, 20);
	if (c[*i] == '4')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number4, *t, 20);
	if (c[*i] == '5')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number5, *t, 20);
	if (c[*i] == '6')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number6, *t, 20);
	if (c[*i] == '7')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number7, *t, 20);
	if (c[*i] == '8')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number8, *t, 20);
	if (c[*i] == '9')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number9, *t, 20);
}
void	move_show_count(t_data *data)
{
	char	*c;
	int		i;
	int		t;

	i = 0;
	t = WIN_W/2 - 80;
	c = ft_itoa(data->counter_of_sprites);
	while(c[i] != '\0')
	{
		condetion_number(data, &t, c, &i);
		t += 40;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.slash, t, 20);
	t += 40;
	free(c);
	c = ft_itoa(data->coin_count);
	i = 0;
	while (c[i] != '\0')
	{	
		condetion_number(data, &t, c, &i);
		t += 40;
		i++;
	}
	free(c);
}
void	move_rotated(t_data *data)
{
	int begin[2];
	int end[2];
	int i;
	static int color_increment;

	
	i = 0;
	if(data->begin_game == 0)
	{
		while(i < WIN_W)
		{
			begin[0] =  i ;
			begin[1] = WIN_H;
			end[0] = i ;
			end[1]= 0;
			draw_line(data,begin,end,18573);
			i++;
		}
		//mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->number.logo, WIN_W/2 - (422 / 2), WIN_H/2 - 259/2);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
		if(color_increment > 40)
			data->begin_game = 1;
		color_increment++;
	}

	if(data->coin_count != data->counter_of_sprites && data->begin_game == 1)
	{   
		begin[0] =  (data->player_x) ;
		begin[1] = (data->player_y + (data->player_mini_res));
		end[0] = data->player_x ;
		end[1]= data->player_y ;
		destroy_and_refresh(data);
		draw_linev4_for_static_imgs(data, begin,end,data->player_mini_res,data->img_mini_player.addr,data->img_mini_player.line_len);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	}
	i = 0;
	while(i < data->counter_of_sprites)
	{
		if(data->pos_of_sprite_y[i] + (data->mini_map_res - (data->mini_map_res / 3)) > data->player_y && data->pos_of_sprite_y[i] - (data->mini_map_res + (data->mini_map_res / 3)) < data->player_y
			&& data->pos_of_sprite_x[i] + (data->mini_map_res - (data->mini_map_res / 3)) > data->player_x && data->pos_of_sprite_x[i] - (data->mini_map_res + (data->mini_map_res / 3)) < data->player_x)
		{
			data->result[(data->pos_of_sprite_y[i] -(( data->pos_of_sprite_y[i] % data->mini_map_res))) / 10][(data->pos_of_sprite_x[i] -(( data->pos_of_sprite_x[i] % data->mini_map_res))) / 10] = '0';
			data->pos_of_sprite_y[i] = 0;
			data->pos_of_sprite_x[i] = 0;
			data->coin_count++;
		}
		if(data->coin_count == data->counter_of_sprites)
			destroy(data);
		i++;
	}
	if(data->coin_count != data->counter_of_sprites && data->begin_game == 1)
	{
		move_show_count(data);
		color_increment = 500000;
	}
	if(data->coin_count == data->counter_of_sprites)
	{
		color_increment += 20;
		mlx_string_put(data->mlx, data->mlx_win,WIN_W/2 - 50,  WIN_H/2 - 40, 16777215 , "conngrats");
		mlx_string_put(data->mlx, data->mlx_win,WIN_W/2 - 100,  WIN_H/2, color_increment , "press enter to retry");
	}
	if (color_increment == 16777215)
		color_increment = 500000;
	
}