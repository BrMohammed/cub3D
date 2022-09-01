/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colesion_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:51:34 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 00:38:35 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	draw_sprite(t_data *data, double *t_distences,
	int i, t_raycolesion *rc_var)
{
	double			wall_scall;

	if (rc_var->distance > 0 && (data->table_of_spritesx[i][1] > 0
		|| data->table_of_spritesy[i][1] > 0))
	{
		rc_var->distance = ((((rc_var->distance - (0))
						/ data->mini_map_res) * data->map_res)
				+ (data->mini_map_res / 2));
		rc_var->ray_count = data->table_of_spritesx[i][1];
		if (data->table_of_spritesx[i][1] == 0)
			rc_var->ray_count = data->table_of_spritesy[i][1];
		rc_var->distprjplan = ((data->demintion_with / 2) / tan((M_PI / 6)));
		rc_var->wall_height = ((data->coin_res / rc_var->distance)
				* rc_var->distprjplan);
		wall_scall = rc_var->wall_height / data->coin_res;
		rc_var->begin[0] = rc_var->ray_count
			- (wall_scall * data->coin_res / 2);
		rc_var->begin[1] = (data->demension_hight / 2)
			- (rc_var->wall_height / 2) + (rc_var->wall_height / 1.2);
		rc_var->end[0] = rc_var->ray_count - (wall_scall * data->coin_res / 2);
		rc_var->end[1] = (data->demension_hight / 2) + (rc_var->wall_height / 2)
			+ (rc_var->wall_height / 1.2);
		draw_linev3(data, (t_draw_linev3){rc_var->begin,
			rc_var->end, wall_scall, t_distences, rc_var->distance});
	}
}

void	ray_colesion_for_sprite(t_data *data, double *t_distences)
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
		draw_sprite(data, t_distences, i, &rc_var);
		data->table_of_spritesy[i][0] = 0;
		data->table_of_spritesy[i][1] = 0;
		data->table_of_spritesx[i][0] = 0;
		data->table_of_spritesx[i][1] = 0;
		i++;
	}
	free(t_distences);
}
