/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:26:38 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 17:26:42 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	key_down_for_leters(t_data *data, int key)
{
	if (key == 46)
			data->show_mouse = !data->show_mouse;
	if (key == 49)
			data->KEY_SPACE = 1;
	if ((key == 2 || key == 0 || key == 13 || key == 1
			|| key == 36 || key == 46))
	{
		data->ON_KEYDOWN_DERECTION = 1;
		if (key == 2)
			data->KEY_D = 1;
		else if (key == 0)
			data->KEY_A = 1;
		if (key == 13)
			data->KEY_W = 1;
		else if (key == 1)
			data->KEY_S = 1;
		if (key == 36)
			data->KEY_ENTER = 1;
	}
}

int	key_down(int key, t_data *data)
{
	if (key == 53)
	{
		kill(0, SIGKILL);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	key_down_for_leters(data, key);
	if (key == 123 || key == 124 || key == 126 || key == 125)
	{
		data->ON_KEYDOWN_CAMERA = 1;
		if (key == 123)
			data->KEY_LEFT = 1;
		else if (key == 124)
			data->KEY_WRIGHT = 1;
		if (key == 125)
			data->KEY_DOWN = 1;
		else if (key == 126)
			data->KEY_UP = 1;
	}
	return (0);
}

void	key_up_for_leters(t_data *data, int key)
{
	if ((key == 2 || key == 0 || key == 13 || key == 1 || key == 36))
	{
		data->ON_KEYDOWN_DERECTION = 0;
		if (key == 2)
			data->KEY_D = 0;
		else if (key == 0)
			data->KEY_A = 0;
		if (key == 13)
			data->KEY_W = 0;
		else if (key == 1)
			data->KEY_S = 0;
		if (key == 36)
			data->KEY_ENTER = 0;
	}
}

int	key_up(int key, t_data *data)
{
	key_up_for_leters(data, key);
	if (key == 123 || key == 124 || key == 126 || key == 125)
	{
		data->ON_KEYDOWN_CAMERA = 0;
		if (key == 123)
			data->KEY_LEFT = 0;
		else if (key == 124)
			data->KEY_WRIGHT = 0;
		if (key == 125)
			data->KEY_DOWN = 0;
		else if (key == 126)
			data->KEY_UP = 0;
	}
	return (0);
}

int	coin_animation(t_data *data, t_movement *var, int index_of_anim)
{
	data->path_sprite = ft_strjoin(var->path_begin, ft_itoa(index_of_anim));
	data->path_sprite = ft_strjoin(data->path_sprite, var->path_end);
	data->img_sprite.mlx_img
		= mlx_xpm_file_to_image(data->mlx, data->path_sprite,
			&data->p_w, &data->p_h);
	data->img_sprite.addr = mlx_get_data_addr(data->img_sprite.mlx_img,
			&data->img_sprite.bpp,
			&data->img_sprite.line_len, &data->img_sprite.endian);
	index_of_anim++;
	var->i1 = 0;
	return (index_of_anim);
}
