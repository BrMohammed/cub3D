/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colesion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:57:05 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/25 01:56:29 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void player_posetion(t_data *data, t_oneray *oneray_var)
{
	while (data->result[oneray_var->y])
	{
		if (data->player_y + (data->player_mini_res / 2) >= oneray_var->y
			* data->mini_map_res && data->player_y + (data->player_mini_res / 2)
			<= (oneray_var->y + 1) * data->mini_map_res)
			oneray_var->py = oneray_var->y;
		oneray_var->x = 0;
		while (data->result[oneray_var->y][oneray_var->x])
		{
			if (data->player_x + (data->player_mini_res / 2) >= oneray_var->x
				* data->mini_map_res
				&& data->player_x + (data->player_mini_res / 2)
				<= (oneray_var->x + 1) * data->mini_map_res)
				oneray_var->px = oneray_var->x;
			oneray_var->x++;
		}
		oneray_var->y++;
	}
}

double	one_ray(t_data *data, double angel, int ray_count)
{
	t_oneray	oneray_var;

	oneray_var.y = 0;
	oneray_var.x = 0;
	oneray_var.ray_colesion_y = 0;
	oneray_var.ray_colesion_x = 0;
	oneray_var.distance = 0;
	oneray_var.ray_count = ray_count;
	oneray_var.degre = (angel / pi) * 180;
	player_posetion(data, &oneray_var);
	if ((oneray_var.degre <= 360 && oneray_var.degre > 180))
	{
		oneray_var.y = oneray_var.py;
		if (oneray_var.degre <= 360 && oneray_var.degre > 270)
		{
			oneray_var.left_begin_agrement_x_from_player = 1;
			oneray_var.left_begin_agrement_x_from_player_x = 0;
		}
		if (oneray_var.degre <= 270 && oneray_var.degre > 180)
		{
			oneray_var.left_begin_agrement_x_from_player = 0;
			oneray_var.left_begin_agrement_x_from_player_x = 1;
		}
		while (oneray_var.y >= 0)
		{
			oneray_var.y_plus = oneray_var.y + 1;
			if ((y_detect(data, &oneray_var, angel) == 1
					|| x_detect(&oneray_var, data, angel) == 1))
				break ;
			oneray_var.y--;
		}
	}
	else
	{
		oneray_var.y = oneray_var.py;
		if (oneray_var.degre <= 180 && oneray_var.degre > 90)
		{
			oneray_var.left_begin_agrement_x_from_player = 0;
			oneray_var.left_begin_agrement_x_from_player_x = 1;
		}
		if (oneray_var.degre <= 90 && oneray_var.degre > 0)
		{
			oneray_var.left_begin_agrement_x_from_player = 1;
			oneray_var.left_begin_agrement_x_from_player_x = 0;
		}
		while (data->result[oneray_var.y])
		{
			oneray_var.y_plus = oneray_var.y;
			if (y_detect(data, &oneray_var, angel) == 1
				|| x_detect(&oneray_var, data, angel) == 1)
				break ;
			oneray_var.y++;
		}
	}
	if ((oneray_var.ray_colesion_y <= oneray_var.ray_colesion_x
			&& oneray_var.ray_colesion_y != 0)
		|| oneray_var.ray_colesion_x == 0)
	{
		oneray_var.distance = oneray_var.ray_colesion_y;
		if (oneray_var.degre > 180 && oneray_var.degre <= 360)
		{
			data->img_rander.addr = data->no_tex.addr;
			data->img_rander.line_len = data->no_tex.line_len;
		}
		else
		{
			data->img_rander.addr = data->so_tex.addr;
			data->img_rander.line_len = data->so_tex.line_len;
		}
	}
	else if ((oneray_var.ray_colesion_x <= oneray_var.ray_colesion_y
			&& oneray_var.ray_colesion_x != 0)
		|| oneray_var.ray_colesion_y == 0)
	{
		oneray_var.distance = oneray_var.ray_colesion_x;
		if (oneray_var.degre >= 270 || oneray_var.degre <= 90)
		{
			data->img_rander.addr = data->ea_tex.addr;
			data->img_rander.line_len = data->ea_tex.line_len;
		}
		else
		{
			data->img_rander.addr = data->we_tex.addr;
			data->img_rander.line_len = data->we_tex.line_len;
		}	
	}
	return (oneray_var.distance);
}

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
