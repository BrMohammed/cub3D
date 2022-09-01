/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:34:22 by brmohamm          #+#    #+#             */
/*   Updated: 2022/09/01 18:18:02 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	number_b_2(t_data *data)
{
	data->number.slash = mlx_xpm_file_to_image(data->mlx,
			"./assets/slash.xpm", &data->img_width, &data->img_height);
	data->number.logo = mlx_xpm_file_to_image(data->mlx,
			"./assets/logo.xpm", &data->img_width, &data->img_height);
	data->menu.quit = mlx_xpm_file_to_image(data->mlx,
			"./assets/quit.xpm", &data->img_width, &data->img_height);
	data->menu.start = mlx_xpm_file_to_image(data->mlx,
			"./assets/start.xpm", &data->img_width, &data->img_height);
	data->menu.game_over = mlx_xpm_file_to_image(data->mlx,
			"./assets/game_over.xpm", &data->img_width, &data->img_height);
	data->menu.winn = mlx_xpm_file_to_image(data->mlx,
			"./assets/win.xpm", &data->img_width, &data->img_height);
	data->menu.winn_p_h = "./assets/win_hover.xpm";
	data->menu.winn_path = "./assets/win.xpm";
}

void	number_b(t_data *data)
{
	data->number.number0 = mlx_xpm_file_to_image(data->mlx,
			"./assets/0.xpm", &data->p_h, &data->img_height);
	data->number.number1 = mlx_xpm_file_to_image(data->mlx,
			"./assets/1.xpm", &data->img_width, &data->img_height);
	data->number.number2 = mlx_xpm_file_to_image(data->mlx,
			"./assets/2.xpm", &data->img_width, &data->img_height);
	data->number.number3 = mlx_xpm_file_to_image(data->mlx,
			"./assets/3.xpm", &data->img_width, &data->img_height);
	data->number.number4 = mlx_xpm_file_to_image(data->mlx,
			"./assets/4.xpm", &data->img_width, &data->img_height);
	data->number.number5 = mlx_xpm_file_to_image(data->mlx,
			"./assets/5.xpm", &data->img_width, &data->img_height);
	data->number.number6 = mlx_xpm_file_to_image(data->mlx,
			"./assets/6.xpm", &data->img_width, &data->img_height);
	data->number.number7 = mlx_xpm_file_to_image(data->mlx,
			"./assets/7.xpm", &data->img_width, &data->img_height);
	data->number.number8 = mlx_xpm_file_to_image(data->mlx,
			"./assets/8.xpm", &data->img_width, &data->img_height);
	data->number.number9 = mlx_xpm_file_to_image(data->mlx,
			"./assets/9.xpm", &data->img_width, &data->img_height);
	number_b_2 (data);
}

void	destroy(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
}
