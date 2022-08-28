/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:10:05 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 18:29:17 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	jumping(t_data *data)
{
	if (data->key_select[KEY_SPACE] == 1)
	{
		if (data->is_jumping_up <= data->gravity
			&& data->is_jumping_down == 0)
		{
			data->lfo9 += data->jump_force;
			data->lte7t -= data->jump_force;
			data->is_jumping_up++;
		}
		if (data->is_jumping_up == data->gravity
			&& data->is_jumping_down >= 0)
		{
			data->lfo9 -= data->jump_force;
			data->lte7t += data->jump_force;
			data->is_jumping_down++;
		}
		if (data->is_jumping_down == data->gravity
			&& data->is_jumping_up == data->gravity)
		{
			data->key_select[KEY_SPACE] = 0;
			data->is_jumping_up = 0;
			data->is_jumping_down = 0;
		}
	}
}

void	derection_move(t_data *data, t_movement *var)
{
	if (data->key_down[ON_KEYDOWN_DERECTION] == 1)
	{
		if (data->coin_count == data->counter_of_sprites
			&& data->key_select[KEY_ENTER] == 1)
		{
			while (data->result[var->i1])
			{
				free(data->result[var->i1]);
				data->result[var->i1] = ft_strdup(data->back_up[var->i1]);
				free(data->back_up[var->i1]);
				var->i1++;
			}
			free(data->back_up);
			aloccation_sprites_and_storage(data);
			initial_var(data);
			data->begin_game = 1;
		}
		if_can_move(data);
	}
}

void	camera_move(t_data *data)
{
	if (data->key_down[ON_KEYDOWN_CAMERA] == 1)
	{
		if (data->key_select[KEY_WRIGHT] == 1)
		{
			data->pa += data->angel_speed;
			if (data->pa > 2 * M_PI)
				data->pa -= 2 * M_PI;
		}
		else if (data->key_select[KEY_LEFT] == 1)
		{
			data->pa -= data->angel_speed;
			if (data->pa < 0)
				data->pa += 2 * M_PI;
		}
	}
	move_rotated(data);
}

int	open_door(t_data *data, int is_open)
{
	jumping(data);
	if ((data->key_select[KEY_ENTER] == 1 && data->door_open == -1)
		|| (data->door_close > 0 && is_open == 0))
	{
		data->door_close++;
		if (data->door_close == 20)
		{
			is_open = 1;
			data->door_open = 0;
		}
	}
	if (is_open == 1 && data->is_close_to_door == false)
	{
		data->door_close--;
		if (data->door_close == 0)
			is_open = 0;
	}
	return (is_open);
}

int	movement(t_data *data)
{
	t_movement	var;
	static int	i;
	static int	index_of_anim;
	static int	is_open;

	var.path_begin = ft_strdup("./assets/YellowCoin/xpm/");
	if (i != 50)
		free(var.path_begin);
	var.path_end = ".xpm";
	if (index_of_anim == 0)
		index_of_anim = 1;
	if (data->show_mouse == true)
		mlx_mouse_show();
	else
		mlx_mouse_hide();
	if (i == 50)
	{
		index_of_anim = coin_animation(data, &var, index_of_anim);
		is_open = open_door(data, is_open);
		derection_move(data, &var);
		camera_move(data);
		i = 0;
	}
	i++;
	return (0);
}
