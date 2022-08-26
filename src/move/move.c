/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:29:35 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 18:25:30 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	move_time_and__mini_player_show(t_data *data, int game_over)
{
	pthread_t	id;
	int			begin[2];
	int			end[2];

	if (data->coin_count != data->counter_of_sprites
		&& data->begin_game == 1 && data->time_up < game_over)
	{
		pthread_create(&id, NULL, &background, &data);
		data->time_up += data->time_move;
		begin[0] = (data->player_x);
		begin[1] = (data->player_y + (data->player_mini_res));
		end[0] = data->player_x;
		end[1] = data->player_y;
		destroy_and_refresh(data);
		rander_image(&data->img, (t_rect){40, WIN_H - 40,
			data->time_up, 20, 12580864});
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.mlx_img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->point_map,
			data->player_x - (data->player_mini_res / 1.7),
			data->player_y - (data->player_mini_res / 1.7));
	}
}

void	counter_of_sprite(t_data *data, int i)
{
	while (i < data->counter_of_sprites)
	{
		if (data->pos_of_sprite_y[i] + (data->mini_map_res
				- data->mini_map_res / 3) > data->player_y
			&& data->pos_of_sprite_y[i] - (data->mini_map_res
				+ (data->mini_map_res / 3)) < data->player_y
			&& data->pos_of_sprite_x[i] + (data->mini_map_res
				- (data->mini_map_res / 3)) > data->player_x
			&& data->pos_of_sprite_x[i] - (data->mini_map_res
				+ (data->mini_map_res / 3)) < data->player_x)
		{
			data->result[(data->pos_of_sprite_y[i] - ((data->pos_of_sprite_y[i]
							% data->mini_map_res)))
				/ 10][(data->pos_of_sprite_x[i] - ((data->pos_of_sprite_x[i]
							% data->mini_map_res))) / 10] = '0';
			data->pos_of_sprite_y[i] = 0;
			data->pos_of_sprite_x[i] = 0;
			data->coin_count++;
		}
		if (data->coin_count == data->counter_of_sprites)
			destroy(data);
		i++;
	}
}

void	wining(t_data *data)
{
	if (data->coin_count != data->counter_of_sprites && data->begin_game == 1)
	{
		move_show_count(data);
		data->color_increment = 500000;
	}
	if (data->coin_count == data->counter_of_sprites)
	{
		data->color_increment += 20;
		mlx_string_put(data->mlx, data->mlx_win, WIN_W / 2 - 50,
			WIN_H / 2 - 40, 16777215, "conngrats");
		mlx_string_put(data->mlx, data->mlx_win, WIN_W / 2 - 100,
			WIN_H / 2, data->color_increment, "press enter to retry");
	}
	if (data->color_increment == 16777215)
		data->color_increment = 500000;
}

void	gameover(t_data *data, int game_over, int *hover)
{
	if (data->time_up >= game_over)
	{
		destroy(data);
		*hover = *hover + 1;
		if (*hover >= 30 && *hover < 60)
		{
			data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
					data->menu.game_over_path_hover,
					&data->img_width, &data->img_height);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->menu.game_over, WIN_W / 2 - (600 / 2),
				WIN_H / 2 - (309 / 2));
		}
		else
		{
			data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
					data->menu.game_over_path,
					&data->img_width, &data->img_height);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->menu.game_over, WIN_W / 2 - (510 / 2),
				WIN_H / 2 - (263 / 2));
		}
		if (*hover >= 60)
			*hover = 0;
	}
}

void	move_rotated(t_data *data)
{
	int			i;
	int			game_over;
	static int	hover;

	i = 0;
	game_over = WIN_W - 80 ;
	start_game_and_menue(data);
	move_time_and__mini_player_show(data, game_over);
	counter_of_sprite(data, i);
	wining(data);
	gameover(data, game_over, &hover);
}
