/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_and_y_colesion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:43:48 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/27 17:31:03 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	if_found_the_pixel_y(t_data *data, int x, t_loop_for_sprite	*sprite_var,
	t_oneray *one_ray)
{
	if (data->pos_of_sprite_y[sprite_var->i] != 0
		&& data->pos_of_sprite_x[sprite_var->i] != 0)
	{
		sprite_var->tpy = ((data->player_y + (data->player_mini_res / 2))
				- (((one_ray->y_plus) * data->mini_map_res)
					+ (data->pos_of_sprite_y[sprite_var->i]
						% data->mini_map_res)));
		sprite_var->tpx = (sprite_var->tpy / -tan(sprite_var->angel));
		sprite_var->b[1] = floor(((one_ray->y_plus) * data->mini_map_res
					+ (data->pos_of_sprite_y[sprite_var->i]
						% data->mini_map_res)));
		sprite_var->b[0] = floor(sprite_var->tpx + data->player_x
				+ (data->player_mini_res / 2));
		if (sprite_var->b[0] == data->pos_of_sprite_x[sprite_var->i]
			&& sprite_var->b[1]
			== data->pos_of_sprite_y[sprite_var->i] && sprite_var->b[0] >= x
			* data->mini_map_res && sprite_var->b[0]
			< (x + 1) * data->mini_map_res)
		{
			data->table_of_spritesy[sprite_var->i][0]
				= floor(sqrt((sprite_var->tpx * sprite_var->tpx)
						+ (sprite_var->tpy * sprite_var->tpy)));
			
			data->table_of_spritesy[sprite_var->i][1] = one_ray->ray_count;
			//printf("data->table_of_spritesy[sprite_var->i][0] = %d  data->table_of_spritesy[sprite_var->i][1] = %d\n",data->table_of_spritesy[sprite_var->i][0],data->table_of_spritesy[sprite_var->i][1]);
		}
	}
}

int	y_detect_loop_for_sprite(t_data *data, int x, double angel,
	t_oneray *one_ray)
{
	t_loop_for_sprite	sprite_var;

	sprite_var.i = 0;
	sprite_var.angel = angel;
	while (sprite_var.i < data->counter_of_sprites)
	{
		if_found_the_pixel_y(data, x, &sprite_var, one_ray);
		sprite_var.i++;
	}
	return (0);
}

void	if_found_pixel_x(t_data *data, t_loop_for_sprite	*sprite_var,
	t_oneray *one_ray)
{
	sprite_var->tpx = (data->player_x + (data->player_mini_res / 2))
		- ((one_ray->x_plus) * data->mini_map_res
			+ (data->pos_of_sprite_x[sprite_var->i] % data->mini_map_res));
	sprite_var->tpy = (sprite_var->tpx * tan(sprite_var->angel));
	sprite_var->b[1] = floor((data->player_y
				+ (data->player_mini_res / 2)) - sprite_var->tpy);
	sprite_var->b[0] = floor(((one_ray->x_plus) * data->mini_map_res
				+ (data->pos_of_sprite_x[sprite_var->i] % data->mini_map_res)));
	if (sprite_var->b[1] == data->pos_of_sprite_y[sprite_var->i]
		&& sprite_var->b[0] == data->pos_of_sprite_x[sprite_var->i]
		&& floor(sprite_var->b[1] / data->mini_map_res) == one_ray->y
		&& floor(sprite_var->b[0] / data->mini_map_res) == one_ray->x_plus)
	{
		data->table_of_spritesx[sprite_var->i][0]
			= floor(sqrt((sprite_var->tpx * sprite_var->tpx)
					+ (sprite_var->tpy * sprite_var->tpy)));
		data->table_of_spritesx[sprite_var->i][1]
			= one_ray->ray_count;
	}
}

int	x_detect_for_sprite_loop(t_data *data, double angel, t_oneray *one_ray)
{
	t_loop_for_sprite	sprite_var;

	sprite_var.i = 0;
	sprite_var.angel = angel;
	while (sprite_var.i < data->counter_of_sprites)
	{
		if_found_pixel_x(data, &sprite_var, one_ray);
		sprite_var.i++;
	}
	return (0);
}
