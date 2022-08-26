/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:46 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 21:05:18 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	init_var_from_map(t_data *data, t_pars pars)
{
	data->result = pars.data.result;
	data->no_tex_path = pars.data.no_tex_path;
	data->so_tex_path = pars.data.so_tex_path;
	data->we_tex_path = pars.data.we_tex_path;
	data->ea_tex_path = pars.data.ea_tex_path;
	data->floor_color = pars.data.floor_color;
	data->ceilling_color = pars.data.ceilling_color;
}

void	initvar_2(t_data *data)
{
	data->map_res = 1000;
	data->player_mini_res = data->mini_map_res / 2;
	data->speed = 3;
	data->angel_speed = 0.15707963267 ;
	data->is_jumping_up = 0;
	data->is_jumping_down = 0;
	data->jump_force = 40;
	data->gravity = 3;
	data->coin_res = 400;
	data->begin_game = 0;
	data->coin_count = 0;
	data->colutsion = 1;
	data->color_increment = 0;
	data->time_up = 10;
	data->time_move = 2;
	data->door_open = 0;
	data->show_mouse = true;
}

void	initial_var(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->result[y])
	{
		while (data->result[0][x])
			x++;
		y++;
	}
	data->result_hight = y;
	data->result_with = x;
	data->lfo9 = 10;
	data->lte7t = 10;
	data->demension_hight = 1000;
	data->demintion_with = 1000;
	if ((data->demension_hight / data->result_hight)
		< (data->demintion_with / data->result_with))
		data->mini_map_res = (data->demension_hight / data->result_hight) / 3;
	else
		data->mini_map_res = (data->demintion_with / data->result_with) / 3;
	initvar_2(data);
}

void	initsial_path_1(t_data *data)
{
	data->point_map_path = "./assets/point.xpm";
	data->point_map = mlx_xpm_file_to_image(data->mlx, data->point_map_path,
			&data->p_w, &data->p_h);
	data->no_tex.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->no_tex_path,
			&data->p_h, &data->p_h);
	data->no_tex.addr = mlx_get_data_addr(data->no_tex.mlx_img,
			&data->no_tex.bpp,
			&data->no_tex.line_len, &data->no_tex.endian);
	data->so_tex.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->so_tex_path,
			&data->p_h, &data->p_h);
	data->so_tex.addr = mlx_get_data_addr(data->so_tex.mlx_img,
			&data->so_tex.bpp,
			&data->so_tex.line_len, &data->so_tex.endian);
	data->we_tex.mlx_img = mlx_xpm_file_to_image(data->mlx, data->we_tex_path,
			&data->p_h, &data->p_h);
	data->we_tex.addr = mlx_get_data_addr(data->we_tex.mlx_img,
			&data->so_tex.bpp,
			&data->we_tex.line_len, &data->we_tex.endian);
	data->ea_tex.mlx_img = mlx_xpm_file_to_image(data->mlx, data->ea_tex_path,
			&data->p_h, &data->p_h);
	data->ea_tex.addr = mlx_get_data_addr(data->ea_tex.mlx_img,
			&data->so_tex.bpp,
			&data->ea_tex.line_len, &data->ea_tex.endian);
}

void	inisial_path(t_data *data)
{
	initsial_path_1(data);
	data->door.mlx_img = mlx_xpm_file_to_image(data->mlx, "./assets/door.xpm",
			&data->p_h, &data->p_h);
	data->door.addr = mlx_get_data_addr(data->door.mlx_img, &data->door.bpp,
			&data->door.line_len, &data->door.endian);
	data->path_sprite = "./assets/YellowCoin/xpm/1.xpm";
	data->img_sprite.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->path_sprite,
			&data->p_w, &data->p_h);
	data->img_sprite.addr = mlx_get_data_addr(data->img_sprite.mlx_img,
			&data->img_sprite.bpp,
			&data->img_sprite.line_len, &data->img_sprite.endian);
	data->menu.quit_path = "./assets/quit.xpm";
	data->menu.start_path = "./assets/start.xpm";
	data->menu.quit_hover_path = "./assets/quit_hover.xpm";
	data->menu.start_hover_path = "./assets/start_hover.xpm";
	data->menu.game_over_path = "./assets/game_over.xpm";
	data->menu.game_over_path_hover = "./assets/game_over_hover.xpm";
	number_b(data);
}
