/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:07:31 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 20:55:52 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	get_color_and_rander_for_draw_linev2(t_data *data,
	t_draw_linev2 *line_var, double pixel[2], double *temp_y)
{
	int		pixel_color;

	if (line_var->y < data->map_res)
	{
		line_var->y = floor((*temp_y) / line_var->wall_scall);
		if (line_var->y < data->map_res && line_var->x < data->map_res
			&& line_var->y >= 0 && line_var->x >= 0)
			pixel_color = get_pixel((t_get_pixel){line_var->addr,
					line_var->line_len, line_var->x,
					line_var->y, data->map_res});
		if (pixel[0] > 0 && pixel[0] < WIN_H && pixel[1] > 0
			&& pixel[1] < WIN_H && pixel_color > 0)
			rander_image(&data->img, (t_rect){pixel[0],
				pixel[1], 1, 1, pixel_color});
		*temp_y = *temp_y + 1;
	}
}

void	draw_linev2(t_data *data, t_draw_linev2 line_var)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	double	temp_y;

	pixel[0] = line_var.begin[0];
	pixel[1] = line_var.begin[1];
	delta[0] = (line_var.end[0] - line_var.begin[0]);
	delta[1] = line_var.end[1] - line_var.begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	temp_y = 0;
	while (pixels && line_var.x < data->map_res)
	{
		get_color_and_rander_for_draw_linev2(data, &line_var, pixel, &temp_y);
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
}

void	draw_line(t_data *data, int *begin, int *end, int color)
{
	double		delta[2];
	int			pixels;
	double		pixel[2];
	int			i;

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	i = 0;
	while (pixels)
	{
		if (pixel[0] >= 0 && pixel[0] < WIN_H && pixel[1]
			>= 0 && pixel[1] < WIN_H)
			rander_image(&data->img, (t_rect){pixel[0], pixel[1], 1, 1, color});
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
}
