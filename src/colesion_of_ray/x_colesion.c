/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_colesion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:42:44 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/25 18:01:43 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

int	x_detect_loop(int x_plus, t_data *data, t_oneray *one_ray, double angel)
{
	double	b[2];
	double	tpx;
	double	tpy;

	tpx = 0;
	tpy = 0;
	tpx = ((data->player_x + (data->player_mini_res / 2))
			- (((x_plus) * data->mini_map_res)));
	tpy = (tpx * tan(angel));
	b[1] = ((data->player_y + (data->player_mini_res / 2)) - tpy);
	b[0] = (((x_plus) * data->mini_map_res));
	if (b[1] >= one_ray->y * data->mini_map_res && b[1]
		< (one_ray->y + 1) * data->mini_map_res)
	{
		one_ray->ray_colesion_x = sqrt((tpx * tpx) +(tpy * tpy));
		b[1] = ((b[1] - (one_ray->y * data->mini_map_res))
				/ data->mini_map_res) * data->map_res;
		data->offcet_x = (int)b[1] % data->map_res;
		data->ray_offset_in_y = 1;
		return (1);
	}
	return (0);
}

int	x_detect_int_while(t_oneray *oneray_var, t_data *data, double angel, int x)
{
	if (oneray_var->ray_count == -1)
	{
		if (data->result[oneray_var->y][x] == '5')
		{
			if (x_detect_loop(oneray_var->x_plus, data, oneray_var, angel) == 1)
				return (1);
		}
	}
	else
	{
		x_detect_for_sprite_loop(data, angel, oneray_var);
		if (data->result[oneray_var->y][x] == '1')
		{
			if (x_detect_loop(oneray_var->x_plus, data, oneray_var, angel) == 1)
				return (1);
		}
	}
	return (0);
}

int	x_detect_contenue(t_oneray *oneray_var, t_data *data, double angel)
{
	int		x;
	double	degre;

	degre = (angel / pi) * 180;
	x = oneray_var->px;
	x++;
	while (data->result[oneray_var->y][x])
	{
		if ((degre >= 270 && degre <= 90))
			oneray_var->x_plus = x + 1;
		else
			oneray_var->x_plus = x;
		if (x_detect_int_while(oneray_var, data, angel, x) == 1)
			return (1);
		x++;
	}
	return (0);
}

int	x_detect(t_oneray *oneray_var, t_data *data, double angel)
{
	int		x;
	double	degre;

	x = 0;
	degre = (angel / pi) * 180;
	if (oneray_var->left_begin_agrement_x_from_player_x == 1)
	{
		x = oneray_var->px;
		while (x >= 0)
		{
			if ((degre >= 270 && degre <= 90))
				oneray_var->x_plus = x;
			else
				oneray_var->x_plus = x + 1;
			if (x_detect_int_while(oneray_var, data, angel, x) == 1)
				return (1);
			x--;
		}
	}
	else
	{
		if (x_detect_contenue(oneray_var, data, angel) == 1)
			return (1);
	}
	return (0);
}
