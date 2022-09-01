/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respone_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:04:12 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 01:15:02 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	initial_player_posetion(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->result[y] != '\0' )
	{
		while (data->result[y][x] != '\0')
		{
			if (ft_strchr("NWSE", data->result[y][x]))
			{
				data->player_y = (y * data->mini_map_res)
					+ data->mini_map_res/2;
				data->player_x = (x * data->mini_map_res)
					+ data->mini_map_res/2;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ray_colesion(data);
}

void	rander_mimimap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->result[y] != '\0')
	{
		x = 0;
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 49)
			{
				rander_image(&data->img, (t_rect){x * data->mini_map_res,
					y * data->mini_map_res,
					data->mini_map_res, data->mini_map_res, 9524926});
			}
			else if (ft_strchr("NWSE025", data->result[y][x]))
				rander_image(&data->img, (t_rect){x * data->mini_map_res,
					y * data->mini_map_res, data->mini_map_res,
					data->mini_map_res, 11796399});
			x++;
		}
		y++;
	}
}

void	camera_posetion(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->result[y] != '\0')
	{
		x = 0;
		while (data->result[y][x] != '\0')
		{
			if (ft_strchr("NWSE", data->result[y][x]))
			{
				if (data->result[y][x] == 'N')
					data->pa = (3 * M_PI) / 2;
				if (data->result[y][x] == 'S')
					data->pa = (M_PI) / 2;
				if (data->result[y][x] == 'E')
					data->pa = 0;
				if (data->result[y][x] == 'W')
					data->pa = M_PI;
				data->result[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	respone_obj(t_data *data)
{
	initial_player_posetion(data);
	camera_posetion(data);
	rander_mimimap(data);
}
