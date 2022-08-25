/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:18:54 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/25 20:19:47 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	draw_line_of_drawline_v3(t_data *data, t_draw_linev3 *line_var,
	t_draw_linev3_var	*var)
{
	while (var->pixels)
	{
		if (var->y < data->coin_res - 1)
		{
			var->y = floor((var->temp_y) / line_var->wall_scall);
			if (var->y < data->coin_res && var->x < data->coin_res
				&& var->y >= 0 && var->x >= 0)
				var->pixel_color = get_pixel((t_get_pixel)
					{data->img_sprite.addr,
						data->img_sprite.line_len,
						var->x, var->y, data->coin_res});
			if (var->pixel[0] > 0 && var->pixel[0] < WIN_H && var->pixel[1] > 0
				&& var->pixel[1] < WIN_H && var->pixel_color > 0)
			{
				if (line_var->distence
					<= line_var->tabl_of_distences[line_var->begin[0]])
					rander_image(&data->img, (t_rect)
					{var->pixel[0], var->pixel[1], 1, 1, var->pixel_color});
			}	
			var->temp_y++;
		}
		var->pixel[0] += var->delta[0];
		var->pixel[1] += var->delta[1];
		--var->pixels;
	}
}

void	init_var_draw_linev3(t_draw_linev3 *line_var, t_draw_linev3_var *var)
{
	var->pixel[0] = line_var->begin[0];
	var->pixel[1] = line_var->begin[1];
	var->delta[0] = ((line_var->end[0]) - line_var->begin[0]);
	var->delta[1] = line_var->end[1] - line_var->begin[1];
	var->pixels = sqrt((var->delta[0] * var->delta[0])
			+ (var->delta[1] * var->delta[1]));
	var->delta[0] /= var->pixels;
	var->delta[1] /= var->pixels;
	var->x = 0;
	var->temp_x = 0;
}

void	draw_linev3(t_data *data, t_draw_linev3 line_var)
{
	t_draw_linev3_var	var;

	init_var_draw_linev3(&line_var, &var);
	while (var.x < data->coin_res - 1)
	{
		var.x = floor(var.temp_x / line_var.wall_scall);
		var.pixels = sqrt((var.delta[0] * var.delta[0])
				+ (var.delta[1] * var.delta[1]));
		var.delta[0] /= var.pixels;
		var.delta[1] /= var.pixels;
		var.y = 0;
		var.temp_y = 0;
		draw_line_of_drawline_v3(data, &line_var, &var);
		line_var.begin[0]++;
		line_var.end[0]++;
		var.pixel[0] = line_var.begin[0];
		var.pixel[1] = line_var.begin[1];
		var.delta[0] = (line_var.end[0] - line_var.begin[0]);
		var.delta[1] = line_var.end[1] - line_var.begin[1];
		var.temp_x++;
	}
}
