/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:10:05 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 17:27:57 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	jumping(t_data *data)
{
	if (data->KEY_SPACE == 1)
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
			data->KEY_SPACE = 0;
			data->is_jumping_up = 0;
			data->is_jumping_down = 0;
		}
	}
}

void	derection_move(t_data *data, t_movement *var)
{
	if (data->ON_KEYDOWN_DERECTION == 1)
	{
		if (data->coin_count == data->counter_of_sprites
			&& data->KEY_ENTER == 1)
		{
			while (data->result[var->i1])
			{
				free(data->result[var->i1]);
				data->result[var->i1] = ft_strdup(data->back_up[var->i1]);
				var->i1++;
			}
			aloccation_sprites_and_storage(data);
			initial_var(data);
			data->begin_game = 1;
		}
		if (data->KEY_W == 1)
			move(data, (sin(data->pa) * data->speed),
				(cos(data->pa) * data->speed));
		else if (data->KEY_S == 1)
			move(data, -sin(data->pa) * 2, -cos(data->pa) * 2);
		else if (data->KEY_A == 1)
			move(data, -cos(-data->pa) * 2, -sin(-data->pa) * 2);
		else if (data->KEY_D == 1)
			move(data, cos(-data->pa) * 2, -sin(data->pa) * 2);
	}
}

void	camera_move(t_data *data)
{
	if (data->ON_KEYDOWN_CAMERA == 1)
	{
		if (data->KEY_WRIGHT == 1)
		{
			data->pa += data->angel_speed;
			if (data->pa > 2 * M_PI)
				data->pa -= 2 * M_PI;
		}
		else if (data->KEY_LEFT == 1)
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
	if ((data->KEY_ENTER == 1 && data->door_open == -1)
		|| (data->door_close > 0 && is_open == 0))
	{
		data->door_close++;
		if (data->door_close == 25)
		{
			is_open = 1;
			data->door_open = 0;
		}
	}
	if (is_open == 1)
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

	var.path_begin = "./assets/YellowCoin/xpm/";
	var.path_end = ".xpm";
	if (index_of_anim == 0)
		index_of_anim = 1;
	if (data->show_mouse == true)
		mlx_mouse_show();
	else
		mlx_mouse_hide();
	if (i == 30)
	{
		index_of_anim = coin_animation(data, &var, index_of_anim);
		is_open = open_door(data, is_open);
		derection_move(data, &var);
		camera_move(data);
		i = 0;
	}
	if (index_of_anim == 31)
		index_of_anim = 0;
	i++;
	return (0);
}
