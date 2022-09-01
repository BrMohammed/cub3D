/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:29:35 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 18:10:23 by brmohamm         ###   ########.fr       */
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
		rander_image(&data->img, (t_rect){40, data->demension_hight - 40,
			data->time_up, 20, 12580864});
		rander_image(&data->img, (t_rect){(data->player_x - 3),
			(data->player_y - 3), 6, 6, 16713472});
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img.mlx_img, 0, 0);
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

void	wining(t_data *data, int *hover)
{
	if (data->coin_count != data->counter_of_sprites && data->begin_game == 1)
		move_show_count(data);
	if (data->coin_count == data->counter_of_sprites)
	{
		destroy(data);
		*hover = *hover + 1;
		if (*hover >= 30 && *hover < 60)
		{
			data->menu.winn = mlx_xpm_file_to_image(data->mlx,
					data->menu.winn_path, &data->img_width, &data->img_height);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->menu.winn, data->demintion_with / 2 - (426 / 2),
				data->demension_hight / 2 - (172 / 2));
		}
		else
		{
			data->menu.winn = mlx_xpm_file_to_image(data->mlx,
					data->menu.winn_p_h, &data->img_width, &data->img_height);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->menu.winn, data->demintion_with / 2 - (501 / 2),
				data->demension_hight / 2 - (202 / 2));
		}
		if (*hover >= 60)
			*hover = 0;
	}
}

void	gameover(t_data *data, int game_over, int *hover)
{
	if (data->time_up >= game_over)
	{
		data->color_increment += 20;
		destroy(data);
		mlx_string_put(data->mlx, data->mlx_win, data->demintion_with / 2 - 60,
			data->demension_hight - 250,
			data->color_increment, "press enter to retry");
		*hover = *hover + 1;
		hoover(data, hover);
		if (*hover >= 60)
			*hover = 0;
		if (data->color_increment == 16777215)
			data->color_increment = 500000;
	}
}

void	move_rotated(t_data *data)
{
	int			i;
	static int	hover;

	i = 0;
	data->time_over = data->demintion_with - 80 ;
	start_game_and_menue(data);
	move_time_and__mini_player_show(data, data->time_over);
	counter_of_sprite(data, i);
	wining(data, &hover);
	gameover(data, data->time_over, &hover);
}
