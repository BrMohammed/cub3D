/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:26:44 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 18:05:50 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	hoover(t_data *data, int *hover)
{
	if (*hover >= 30 && *hover < 60)
	{
		data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
				data->menu.game_over_path_hover,
				&data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->menu.game_over, data->demintion_with / 2 - (600 / 2),
			data->demension_hight / 2 - (309 / 2));
	}
	else
	{
		data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
				data->menu.game_over_path,
				&data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->menu.game_over, data->demintion_with / 2 - (510 / 2),
			data->demension_hight / 2 - (263 / 2));
	}
}

void	destroy_and_refresh(t_data *data)
{
	destroy(data);
	respone_obj(data);
}

int	is_colession(t_data *data, double angel, int target)
{
	double	angel_move;
	int		i;
	double	distence;
	double	betwinenngels;

	angel_move = (M_PI / 6) / 6;
	i = 0;
	while (i < 6)
	{
		betwinenngels = data->pa - angel;
		if (betwinenngels < 0)
			betwinenngels += 2 * M_PI;
		if (betwinenngels > 2 * M_PI)
			betwinenngels -= 2 * M_PI;
		distence = one_ray(data, angel, target);
		if (distence < 7 && distence != 0)
			return (1);
		angel += angel_move;
		if (angel > 2 * M_PI)
			angel -= 2 * M_PI;
		i++;
	}
	return (0);
}

void	move(t_data *data, int y, int x, double angel)
{
	if (angel < 0)
		angel += 2 * M_PI;
	if (!is_colession(data, angel, 0)
		&& (!is_colession(data, angel, -1)
			|| data->door_close != 0))
	{
		data->player_x = data->player_x + x;
		data->player_y = data->player_y + y;
	}
}
