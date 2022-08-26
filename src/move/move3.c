/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:26:44 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 18:26:48 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	destroy(data);
	respone_obj(data);
}

int	is_a_door(t_data *data, float x, float y)
{
	t_int_point	p;

	p.x = (int)(x + (data->player_mini_res)) / data->mini_map_res;
	p.y = (int)(y + (data->player_mini_res)) / data->mini_map_res;
	if (data->result[(int)(y / data->mini_map_res)][(int)x
		/ data->mini_map_res] == '5' ||
		data->result[(int)(y / data->mini_map_res)][(int)(x
		+ data->player_mini_res) / data->mini_map_res] == '5' ||
		data->result[(int)(y + data->player_mini_res)
		/ data->mini_map_res][(int)x / data->mini_map_res] == '5' ||
		data->result[p.y][p.x] == '5')
		return (1);
	return (0);
}

int	is_a_wall(t_data *data, float x, float y)
{
	t_int_point	p;

	p.x = (int)(x + (data->player_mini_res)) / data->mini_map_res;
	p.y = (int)(y + (data->player_mini_res)) / data->mini_map_res;
	if (data->result[(int)(y / data->mini_map_res)][(int)x
		/ data->mini_map_res] == '1' ||
		data->result[(int)(y / data->mini_map_res)][(int)(x
		+ data->player_mini_res) / data->mini_map_res] == '1' ||
		data->result[(int)(y + data->player_mini_res)
		/ data->mini_map_res][(int)x / data->mini_map_res] == '1' ||
		data->result[p.y][p.x] == '1')
		return (1);
	return (0);
}

void	move(t_data *data, int y, int x)
{
	if (!is_a_wall (data, data->player_x + x, data->player_y + y)
		&& (!is_a_door(data, data->player_x + x, data->player_y + y)
			|| data->door_close != 0))
	{
		data->player_x = data->player_x + x;
		data->player_y = data->player_y + y;
	}
}
