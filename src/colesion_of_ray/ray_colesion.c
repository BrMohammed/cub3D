/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colesion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:57:05 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 21:37:34 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	draw_celling_and_floor(t_raycolesion *rc_var, double *betwinenngels,
	t_data *data, double *wall_scall)
{
	*betwinenngels = data->pa - rc_var->rays;
	if (*betwinenngels < 0)
		*betwinenngels += 2 * M_PI;
	if (*betwinenngels > 2 * M_PI)
		*betwinenngels -= 2 * M_PI;
	rc_var->distance = (((((rc_var->distance * cos(*betwinenngels))
						- (data->player_mini_res / 2))
					/ data->mini_map_res)) * data->map_res)
		+ (data->mini_map_res / 2);
	rc_var->distprjplan = ((data->demintion_with / 2) / tan((M_PI / 6)));
	rc_var->wall_height = (data->map_res / rc_var->distance)
		* rc_var->distprjplan;
	*wall_scall = (rc_var->wall_height) / data->map_res;
	rc_var->begin[0] = rc_var->ray_count;
	rc_var->begin[1] = 0;
	rc_var->end[0] = rc_var->ray_count;
	rc_var->end[1] = (data->demension_hight / 2) - ((rc_var->wall_height / 2));
	draw_line(data, rc_var->begin, rc_var->end, data->ceilling_color);
	rc_var->begin[0] = rc_var->ray_count;
	rc_var->begin[1] = (data->demension_hight / 2)
		+ ((rc_var->wall_height / 2));
	rc_var->end[0] = rc_var->ray_count;
	rc_var->end[1] = data->demension_hight;
	draw_line(data, rc_var->begin, rc_var->end, data->floor_color);
}

void	draw_wall(t_raycolesion *rc_var,
	t_data *data, double wall_scall)
{
	rc_var->begin[0] = rc_var->ray_count;
	rc_var->begin[1] = (data->demension_hight / 2)
		- ((rc_var->wall_height / 2));
	rc_var->end[0] = rc_var->ray_count;
	rc_var->end[1] = (data->demension_hight / 2) + ((rc_var->wall_height / 2));
	rc_var->y = (data->map_res / 2) - (rc_var->wall_height / 2);
	if (rc_var->y < 0)
		rc_var->y = 0;
	if (data->ray_offset_in_y == 0)
		rc_var->offcet = data->offcet_x1;
	else
		rc_var->offcet = data->offcet_x;
	draw_linev2(data, (t_draw_linev2){rc_var->begin, rc_var->end,
		rc_var->offcet, rc_var->y, wall_scall,
		data->img_rander.addr, data->img_rander.line_len});
}

double	door_animation( t_data *data, double betwinenngels, double rays)
{
	double	destence_of_door;

	destence_of_door = one_ray(data, rays, -1);
	if (destence_of_door > 0)
	{
		if (destence_of_door < 30)
			data->door_open = -1;
		if (data->door_close > 0 && data->door_open == -1)
			data->offcet_x1 += data->door_close * 200;
		if (destence_of_door < 5)
			data->is_close_to_door = true;
		else
			data->is_close_to_door = false;
	}
	if (destence_of_door > 0)
	{
		destence_of_door = ((((((destence_of_door * cos(betwinenngels))
								- (data->player_mini_res / 2))
							/ data->mini_map_res))
					* data->map_res) + (data->mini_map_res / 2));
	}
	return (destence_of_door);
}

void	door_draw(double destence_of_door, t_raycolesion *rc_var,
	t_data *data, double wall_scall)
{
	if (destence_of_door > 0 && destence_of_door < rc_var->distance)
	{
		rc_var->distprjplan = ((data->demintion_with
					/ 2) / tan((M_PI / 6)));
		rc_var->wall_height = ((data->map_res / destence_of_door)
				* rc_var->distprjplan);
		wall_scall = (rc_var->wall_height) / data->map_res;
		rc_var->begin[0] = rc_var->ray_count;
		rc_var->begin[1] = (data->demension_hight
				/ 2) - (rc_var->wall_height / 2);
		rc_var->end[0] = rc_var->ray_count;
		rc_var->end[1] = (data->demension_hight
				/ 2) + (rc_var->wall_height / 2);
		rc_var->y = (data->map_res / 2) - (rc_var->wall_height / 2);
		if (rc_var->y < 0)
			rc_var->y = 0;
		if (data->ray_offset_in_y == 0)
			rc_var->offcet = data->offcet_x1;
		else
			rc_var->offcet = data->offcet_x;
		draw_linev2(data, (t_draw_linev2){rc_var->begin, rc_var->end,
			rc_var->offcet, rc_var->y, wall_scall,
			data->door.addr, data->door.line_len});
	}
}

void	ray_colesion(t_data *data)
{
	t_raycolesion	rc_var;
	double			betwinenngels;
	double			wall_scall;
	double			*t_distences;
	double			destence_of_door;

	init_var(&rc_var, &betwinenngels, &destence_of_door, data);
	t_distences = malloc(sizeof(double ) * data->demintion_with);
	while (rc_var.ray_count < data->demintion_with)
	{
		rc_var.rays += rc_var.angel_move;
		if (rc_var.rays > 2 * M_PI)
			rc_var.rays -= 2 * M_PI;
		rc_var.distance = one_ray(data, rc_var.rays, rc_var.ray_count);
		if (rc_var.distance > 0)
		{
			draw_celling_and_floor(&rc_var, &betwinenngels, data, &wall_scall);
			draw_wall(&rc_var, data, wall_scall);
		}
		destence_of_door = door_animation(data, betwinenngels, rc_var.rays);
		door_draw(destence_of_door, &rc_var, data, wall_scall);
		t_distences = door_sprite(rc_var, t_distences, destence_of_door, data);
		rc_var.ray_count++;
	}
	ray_colesion_for_sprite(data, t_distences);
}
