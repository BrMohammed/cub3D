/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:13:15 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 00:38:35 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	player_posetion(t_data *data, t_oneray *oneray_var)
{
	while (data->result[oneray_var->y])
	{
		if (data->player_y + (0) >= oneray_var->y
			* data->mini_map_res && data->player_y + (0)
			<= (oneray_var->y + 1) * data->mini_map_res)
			oneray_var->py = oneray_var->y;
		oneray_var->x = 0;
		while (data->result[oneray_var->y][oneray_var->x])
		{
			if (data->player_x + (0) >= oneray_var->x
				* data->mini_map_res
				&& data->player_x + (0)
				<= (oneray_var->x + 1) * data->mini_map_res)
				oneray_var->px = oneray_var->x;
			oneray_var->x++;
		}
		oneray_var->y++;
	}
}

void	choise_textur(t_data *data, t_oneray *oneray_var)
{
	void	*textur;

	textur = NULL;
	if ((oneray_var->ray_colesion_y <= oneray_var->ray_colesion_x
			&& oneray_var->ray_colesion_y != 0)
		|| oneray_var->ray_colesion_x == 0)
	{
		oneray_var->distance = oneray_var->ray_colesion_y;
		if (oneray_var->degre > 180 && oneray_var->degre <= 360)
			textur = data->no_tex.mlx_img;
		else
			textur = data->so_tex.mlx_img;
	}
	else if ((oneray_var->ray_colesion_x <= oneray_var->ray_colesion_y
			&& oneray_var->ray_colesion_x != 0)
		|| oneray_var->ray_colesion_y == 0)
	{
		oneray_var->distance = oneray_var->ray_colesion_x;
		if (oneray_var->degre >= 270 || oneray_var->degre <= 90)
			textur = data->ea_tex.mlx_img;
		else
			textur = data->we_tex.mlx_img;
	}
	data->img_rander.addr = mlx_get_data_addr(textur, &data->img_rander.bpp,
			&data->img_rander.line_len, &data->img_rander.endian);
}

void	view_befor_player(t_data *data, t_oneray *oneray_var, double angel)
{
	oneray_var->y = oneray_var->py;
	if (oneray_var->degre <= 360 && oneray_var->degre > 270)
	{
		oneray_var->left_begin_agrement_x_from_player = 1;
		oneray_var->left_begin_agrement_x_from_player_x = 0;
	}
	if (oneray_var->degre <= 270 && oneray_var->degre > 180)
	{
		oneray_var->left_begin_agrement_x_from_player = 0;
		oneray_var->left_begin_agrement_x_from_player_x = 1;
	}
	while (oneray_var->y >= 0)
	{
		oneray_var->y_plus = oneray_var->y + 1;
		if ((y_detect(data, oneray_var, angel) == 1
				|| x_detect(oneray_var, data, angel) == 1))
			break ;
		oneray_var->y--;
	}
}

void	view_after_player(t_data *data, t_oneray *oneray_var, double angel)
{
	oneray_var->y = oneray_var->py;
	if (oneray_var->degre <= 180 && oneray_var->degre > 90)
	{
		oneray_var->left_begin_agrement_x_from_player = 0;
		oneray_var->left_begin_agrement_x_from_player_x = 1;
	}
	if (oneray_var->degre <= 90 && oneray_var->degre > 0)
	{
		oneray_var->left_begin_agrement_x_from_player = 1;
		oneray_var->left_begin_agrement_x_from_player_x = 0;
	}
	while (data->result[oneray_var->y])
	{
		oneray_var->y_plus = oneray_var->y;
		if (y_detect(data, oneray_var, angel) == 1
			|| x_detect(oneray_var, data, angel) == 1)
			break ;
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
	oneray_var.degre = (angel / M_PI) * 180;
	player_posetion(data, &oneray_var);
	if ((oneray_var.degre <= 360 && oneray_var.degre > 180))
		view_befor_player(data, &oneray_var, angel);
	else
		view_after_player(data, &oneray_var, angel);
	choise_textur(data, &oneray_var);
	return (oneray_var.distance);
}
