/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_colesion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:57:02 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 00:38:35 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

int	y_detect_loop(t_data *data, int x, t_oneray *one_ray, double angel)
{
	double	b[2];
	double	tpx;
	double	tpy;

	tpx = 0;
	tpy = 0;
	tpy = (data->player_y + (0))
		- ((one_ray->y_plus * data->mini_map_res));
	tpx = (tpy / -tan(angel));
	b[1] = (((one_ray->y_plus) * data->mini_map_res));
	b[0] = (tpx + data->player_x + (0));
	if (b[0] >= x * data->mini_map_res && b[0] < (x + 1) * data->mini_map_res)
	{
		one_ray->ray_colesion_y = sqrt((tpx * tpx) +(tpy * tpy));
		b[0] = ((b[0] - (x * data->mini_map_res))
				/ data->mini_map_res) * data->map_res;
		data->offcet_x1 = (int)b[0] % data->map_res;
		data->ray_offset_in_y = 0;
		return (1);
	}
	return (0);
}

int	y_detect_in_while(t_data *data, t_oneray *oneray_var, double angel, int x)
{
	if (oneray_var->ray_count == -1)
	{
		if (data->result[oneray_var->y][x] == '5')
		{
			if (y_detect_loop(data, x, oneray_var, angel) == 1)
				return (1);
		}
	}
	else
	{
		y_detect_loop_for_sprite(data, x, angel, oneray_var);
		if (data->result[oneray_var->y][x] == '1')
		{
			if (y_detect_loop(data, x, oneray_var, angel) == 1)
				return (1);
		}
	}
	return (0);
}

int	y_detect(t_data *data, t_oneray *oneray_var, double angel)
{
	int	x;

	x = oneray_var->px;
	if (oneray_var->left_begin_agrement_x_from_player == 1)
	{
		while (data->result[oneray_var->y][x])
		{
			if (y_detect_in_while(data, oneray_var, angel, x) == 1)
				return (1);
			x++;
		}
	}
	else
	{
		while (x >= 0)
		{
			if (y_detect_in_while(data, oneray_var, angel, x) == 1)
				return (1);
			x--;
		}
	}
	return (0);
}
