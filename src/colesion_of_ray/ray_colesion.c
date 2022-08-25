/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colesion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:57:05 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/25 02:15:00 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	ray_colesion(t_data *data)
{
	t_raycolesion	rc_var;
	double			betwinenngels;
	double			wall_scall;
	double			tabl_of_distences[WIN_W];
	double			destence_of_door;
	int				y;

	rc_var.angel_move = (M_PI / 3) / (WIN_W);
	rc_var.point_to_break = 0;
	rc_var.ray_count = 0;
	rc_var.rays = data->pa;
	rc_var.rays -= M_PI / 6;
	if (rc_var.rays < 0)
		rc_var.rays += 2 * M_PI;
	while (rc_var.ray_count < WIN_W)
	{
		rc_var.rays += rc_var.angel_move;
		if (rc_var.rays > 2 * M_PI)
			rc_var.rays -= 2 * M_PI;
		rc_var.distance = one_ray(data, rc_var.rays, rc_var.ray_count);
		if (rc_var.distance > 0)
		{
			betwinenngels = data->pa - rc_var.rays;
			if (betwinenngels < 0)
				betwinenngels += 2 * M_PI;
			if (betwinenngels > 2 * M_PI)
				betwinenngels -= 2 * M_PI;
			rc_var.distance = (((((rc_var.distance * cos(betwinenngels))
								- (data->player_mini_res / 2))
							/ data->mini_map_res)) * data->map_res)
				+ (data->mini_map_res / 2);
			rc_var.distanceprojplan = ((WIN_W / 2) * tan((M_PI / 3)));
			rc_var.wallHeight = (data->map_res / rc_var.distance)
				* rc_var.distanceprojplan;
			wall_scall = (rc_var.wallHeight) / data->map_res;
			rc_var.begin[0] = rc_var.ray_count;
			rc_var.begin[1] = 0;
			rc_var.end[0] = rc_var.ray_count;
			rc_var.end[1] = (WIN_H / 2) - ((rc_var.wallHeight / 2));
			if (rc_var.distance > 0)
				draw_line(data, rc_var.begin, rc_var.end, data->ceilling_color);
			rc_var.begin[0] = rc_var.ray_count;
			rc_var.begin[1] = (WIN_H / 2) + ((rc_var.wallHeight / 2));
			rc_var.end[0] = rc_var.ray_count;
			rc_var.end[1] = WIN_H;
			if (rc_var.distance > 0)
				draw_line(data, rc_var.begin, rc_var.end, data->floor_color);
			rc_var.begin[0] = rc_var.ray_count;
			rc_var.begin[1] = (WIN_H / 2) - ((rc_var.wallHeight / 2));
			rc_var.end[0] = rc_var.ray_count;
			rc_var.end[1] = (WIN_H / 2) + ((rc_var.wallHeight / 2));
			y = (data->map_res / 2) - (rc_var.wallHeight / 2);
			if (y < 0)
				y = 0;
			if (data->ray_offset_in_y == 0)
				draw_linev2(data, rc_var.begin, rc_var.end, data->offcet_x1, y, wall_scall, data->img_rander.addr, data->img_rander.line_len);
			else
				draw_linev2(data, rc_var.begin, rc_var.end, data->offcet_x, y, wall_scall, data->img_rander.addr, data->img_rander.line_len);
		}
		tabl_of_distences[rc_var.ray_count] = rc_var.distance;
		destence_of_door = one_ray(data, rc_var.rays, -1);
		if (destence_of_door > 0)
		{
			if (destence_of_door < 15)
				data->door_open = -1;
			if (data->door_close > 0 && data->door_open == -1)
				data->offcet_x1 += data->door_close * 140;
			if (data->door_close * 140 > data->map_res)
				destence_of_door = 0;
		}
		if (destence_of_door > 0)
			destence_of_door = ((((((destence_of_door * cos(betwinenngels))
									- (data->player_mini_res / 2))
								/ data->mini_map_res))
						* data->map_res) + (data->mini_map_res / 2));
		if (destence_of_door > 0 && destence_of_door < rc_var.distance)
		{
			rc_var.distanceprojplan = ((WIN_W / 2) / tan((M_PI / 6)));
			rc_var.wallHeight = ((data->map_res / destence_of_door) * rc_var.distanceprojplan);
			wall_scall = (rc_var.wallHeight) / data->map_res;
			rc_var.begin[0] = rc_var.ray_count;
			rc_var.begin[1] = (WIN_H / 2) - (rc_var.wallHeight / 2);
			rc_var.end[0] = rc_var.ray_count;
			rc_var.end[1] = (WIN_H / 2) + (rc_var.wallHeight / 2);
			y = (data->map_res / 2) - (rc_var.wallHeight / 2);
			if (y < 0)
				y = 0;
			if (data->ray_offset_in_y == 0)
				draw_linev2(data, rc_var.begin, rc_var.end, data->offcet_x1, y, wall_scall,data->door.addr, data->door.line_len);
			else
				draw_linev2(data, rc_var.begin, rc_var.end, data->offcet_x ,y, wall_scall,data->door.addr, data->door.line_len);
		}
		rc_var.ray_count++;
	}
	ray_colesion_for_sprite(data, tabl_of_distences);
}
