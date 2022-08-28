/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:39:53 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 18:47:53 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

int	check_condition(t_pars *pars, int i)
{
	if (pars->line[i] == '1' || pars->line[i] == '0'
		|| pars->line[i] == 'N' || pars->line[i] == 'S'
		|| pars->line[i] == 'W' || pars->line[i] == 'E'
		|| pars->line[i] == '\n' || pars->line[i] == ' '
		||pars->line[i] == '2' || pars->line[i] == '5')
	{
		if (pars->line[i] == '2')
			pars->coin_flag = 1;
		return (1);
	}
	return (0);
}
