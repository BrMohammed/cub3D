/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colesion_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:51:34 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/25 18:48:07 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	draw_sprite(t_data *data, double *tabl_of_distences,
	int i, t_raycolesion *rc_var)
{
	double			wall_scall;

	if (rc_var->distance > 0 && (data->table_of_spritesx[i][1] > 0
		|| data->table_of_spritesy[i][1] > 0))
	{
		rc_var->distance = ((((rc_var->distance - (data->player_mini_res / 2))
						/ data->mini_map_res) * data->map_res)
				+ (data->mini_map_res / 2));
		rc_var->ray_count = data->table_of_spritesx[i][1];
		if (data->table_of_spritesx[i][1] == 0)
			rc_var->ray_count = data->table_of_spritesy[i][1];
		rc_var->distanceprojplan = ((WIN_W / 2) / tan((M_PI / 6)));
		rc_var->wallHeight = ((data->coin_res / rc_var->distance)
				* rc_var->distanceprojplan);
		wall_scall = rc_var->wallHeight / data->coin_res;
		rc_var->begin[0] = rc_var->ray_count
			- (wall_scall * data->coin_res / 2);
		rc_var->begin[1] = (WIN_H / 2) - (rc_var->wallHeight / 2)
			+ (rc_var->wallHeight / 1.2);
		rc_var->end[0] = rc_var->ray_count - (wall_scall
				* data->coin_res / 2);
		rc_var->end[1] = (WIN_H / 2) + (rc_var->wallHeight / 2)
			+ (rc_var->wallHeight / 1.2);
		draw_linev3(data, rc_var->begin, rc_var->end, wall_scall, tabl_of_distences, rc_var->distance);
	}
}

void	ray_colesion_for_sprite(t_data *data, double *tabl_of_distences)
{
	t_raycolesion	rc_var;
	int				i;

	i = 0;
	while (i < data->counter_of_sprites)
	{
		if ((data->table_of_spritesy[i][0]
			<= data->table_of_spritesx[i][0]
			&& data->table_of_spritesy[i][0] != 0)
				|| data->table_of_spritesx[i][0] == 0)
			rc_var.distance = data->table_of_spritesy[i][0];
		else if ((data->table_of_spritesx[i][0]
			<= data->table_of_spritesy[i][0]
			&& data->table_of_spritesx[i][0] != 0)
			|| data->table_of_spritesy[i][0] == 0)
			rc_var.distance = data->table_of_spritesx[i][0];
		draw_sprite(data, tabl_of_distences, i, &rc_var);
		data->table_of_spritesy[i][0] = 0;
		data->table_of_spritesy[i][1] = 0;
		data->table_of_spritesx[i][0] = 0;
		data->table_of_spritesx[i][1] = 0;
		i++;
	}
}
