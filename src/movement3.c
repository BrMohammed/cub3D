/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:29:48 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 18:30:27 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	if_can_move(t_data *data)
{
	if (data->key_select[KEY_W] == 1)
		move(data, (sin(data->pa) * data->speed),
			(cos(data->pa) * data->speed));
	else if (data->key_select[KEY_S] == 1)
		move(data, -sin(data->pa) * 2, -cos(data->pa) * 2);
	else if (data->key_select[KEY_A] == 1)
		move(data, -cos(-data->pa) * 2, -sin(-data->pa) * 2);
	else if (data->key_select[KEY_D] == 1)
		move(data, cos(-data->pa) * 2, -sin(data->pa) * 2);
}
