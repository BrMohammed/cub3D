/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_for_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:36:25 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 20:55:02 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	init_var(t_raycolesion *rc_var, double *betwinenngels,
		double *destence_of_door, t_data *data)
{
	rc_var->angel_move = (M_PI / 3) / (WIN_W);
	rc_var->point_to_break = 0;
	rc_var->ray_count = 0;
	rc_var->rays = data->pa;
	rc_var->rays -= M_PI / 6;
	*betwinenngels = 0;
	destence_of_door = 0;
	if (rc_var->rays < 0)
		rc_var->rays += 2 * M_PI;
}
