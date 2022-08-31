/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:54:09 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 18:15:33 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	view_with_mouse(t_data *data, int x)
{
	if (data->show_mouse == false)
	{
		if (x > data->demintion_with / 2 + 10)
		{
			data->pa += data->angel_speed;
			if (data->pa > 2 * M_PI)
				data->pa -= 2 * M_PI;
			mlx_mouse_move(data->mlx_win, data->demintion_with / 2,
				data->demension_hight / 2);
		}
		else if (x < data->demintion_with / 2 - 10)
		{
			data->pa -= data->angel_speed;
			if (data->pa < 0)
				data->pa += 2 * M_PI;
			mlx_mouse_move(data->mlx_win, data->demintion_with / 2,
				data->demension_hight / 2);
		}
	}
}

int	mouse_move(int x, int y, t_data *data)
{		
	view_with_mouse(data, x);
	data->menu.hover_quit = (150 / 2);
	data->menu.hover_start = (150 / 2);
	data->menu.quit = mlx_xpm_file_to_image(data->mlx,
			data->menu.quit_path, &data->img_width, &data->img_height);
	data->menu.start = mlx_xpm_file_to_image(data->mlx,
			data->menu.start_path, &data->img_width, &data->img_height);
	if (x > 426 && x < 575 && y > 400 && y < 450 && data->begin_game == 0
		&& data->color_increment > 40)
	{
		data->menu.start = mlx_xpm_file_to_image(data->mlx,
				data->menu.start_hover_path,
				&data->img_width, &data->img_height);
		data->menu.hover_start += 15;
	}
	else if (x > 426 && x < 575 && y > 500 && y < 550 && data->begin_game == 0
		&& data->color_increment > 40)
	{
		data->menu.quit = mlx_xpm_file_to_image(data->mlx,
				data->menu.quit_hover_path,
				&data->img_width, &data->img_height);
		data->menu.hover_quit += 15;
	}
	return (0);
}

void	*click(void *var)
{
	(void)var;
	system("afplay -v 20 ./assets/sound/click.mp3");
	return (0);
}

void	*background(void *var)
{
	t_data	*data;

	data = (t_data *)var;
	data->sound_loop = system
		("while :; do afplay -v 1 ./assets/sound/background3.mp3; done");
	return (0);
}

int	mouse_down(int button, int x, int y, t_data *data)
{
	pthread_t			id;

	if (button == 1 && data->begin_game == 0 && data->color_increment > 40)
	{
		if (x > 426 && x < 575 && y > 400 && y < 450)
		{
			pthread_create(&id, NULL, &click, NULL);
			data->begin_game = 1;
		}
		else if (x > 426 && x < 575 && y > 500 && y < 550)
		{
			pthread_create(&id, NULL, &click, NULL);
			mouse();
		}
	}
	return (0);
}
