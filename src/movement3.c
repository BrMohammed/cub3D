/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:29:48 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 17:21:30 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	if_can_move(t_data *data)
{
	if (data->key_select[KEY_W] == 1)
		move(data, (sin(data->pa) * data->speed),
			(cos(data->pa) * data->speed), data->pa - (M_PI / 12));
	else if (data->key_select[KEY_S] == 1)
		move(data, -sin(data->pa) * data->speed,
			-cos(data->pa) * data->speed, data->pa - (M_PI + (M_PI / 12)));
	else if (data->key_select[KEY_A] == 1)
		move(data, -cos(-data->pa) * data->speed,
			-sin(-data->pa) * data->speed, data->pa - ((M_PI / 2) + M_PI / 12));
	else if (data->key_select[KEY_D] == 1)
		move(data, cos(-data->pa) * data->speed,
			-sin(data->pa) * data->speed, data->pa
			- (((3 * M_PI) / 2) + M_PI / 12));
}
