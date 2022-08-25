#include "../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	destroy(data);
	//respone2(data);
	respone_obj(data);
}

void	move(t_data *data, int y, int x)
{
	data->player_x = data->player_x + x;
	data->player_y = data->player_y + y;
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
	t = WIN_W/2 - 60;
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
	int game_over;
	static int hover;
	pthread_t			id;

	i = 0;
	game_over = WIN_W - 80 ;
	if(data->color_increment <= 40)
	{
		while(i < WIN_W)
		{
			begin[0] =  i ;
			begin[1] = 0;
			end[0] = i ;
			end[1]= WIN_H;
			draw_line(data,begin,end,18573);
			i++;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->number.logo, WIN_W/2 - (422 / 2), WIN_H/2 - 259/2);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
		data->color_increment++;
	}
	else
	{
		destroy(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->menu.start, WIN_W/2 - data->menu.hover_start, WIN_H/2 - 100);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->menu.quit, WIN_W/2 - data->menu.hover_quit, WIN_H/2 );
	}

	if(data->coin_count != data->counter_of_sprites && data->begin_game == 1 && data->time_up < game_over )
	{   
		pthread_create(&id, NULL, &background, &data);
		data->time_up += data->time_move;
		begin[0] =  (data->player_x) ;
		begin[1] = (data->player_y + (data->player_mini_res));
		end[0] = data->player_x ;
		end[1]= data->player_y ;
		destroy_and_refresh(data);
		draw_linev4_for_static_imgs(data, begin,end,data->player_mini_res,data->img_mini_player.addr,data->img_mini_player.line_len);
		rander_image(&data->img, (t_rect){40,WIN_H - 40,data->time_up, 20, 12580864}, data);
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
		data->color_increment = 500000;
	}
	if(data->coin_count == data->counter_of_sprites)
	{
		data->color_increment += 20;
		mlx_string_put(data->mlx, data->mlx_win,WIN_W/2 - 50,  WIN_H/2 - 40, 16777215 , "conngrats");
		mlx_string_put(data->mlx, data->mlx_win,WIN_W/2 - 100,  WIN_H/2, data->color_increment  , "press enter to retry");
	}
	if (data->color_increment == 16777215)
		data->color_increment = 500000;
	i = 0;
	if(data->time_up >= game_over)
	{
		destroy(data);
		hover++;
		if(hover >= 30 && hover < 60)
		{
			data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
				data->menu.game_over_path_hover, &data->img_width, &data->img_height);
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->menu.game_over,WIN_W/2 - (600 / 2) ,WIN_H/2 - (309 / 2));
		}
		else
		{
			data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
				data->menu.game_over_path, &data->img_width, &data->img_height);
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->menu.game_over,WIN_W/2 - (510 / 2) ,WIN_H/2 - (263 / 2));
		}
			
		if(hover >= 60)
			hover = 0;
		
	}
	
}