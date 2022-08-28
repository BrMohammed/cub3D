/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:24:24 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 18:15:18 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub.h"

void	condetion_number02(t_data *data, int *t, char *c, int *i)
{
	if (c[*i] == '5')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number5, *t, 20);
	if (c[*i] == '6')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number6, *t, 20);
	if (c[*i] == '7')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number7, *t, 20);
	if (c[*i] == '8')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number8, *t, 20);
	if (c[*i] == '9')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number9, *t, 20);
}

static void	condetion_number(t_data *data, int *t, char *c, int *i)
{
	if (c[*i] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number0, *t, 20);
	if (c[*i] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number1, *t, 20);
	if (c[*i] == '2')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number2, *t, 20);
	if (c[*i] == '3')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number3, *t, 20);
	if (c[*i] == '4')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.number4, *t, 20);
	condetion_number02(data, t, c, i);
}

void	move_show_count(t_data *data)
{
	char	*c;
	int		i;
	int		t;

	i = -1;
	t = data->demintion_with / 2 - 60;
	c = ft_itoa(data->counter_of_sprites);
	while (c[++i] != '\0')
	{
		condetion_number(data, &t, c, &i);
		t += 40;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->number.slash, t, 20);
	t += 40;
	free(c);
	c = NULL;
	c = ft_itoa(data->coin_count);
	i = -1;
	while (c[++i] != '\0')
	{	
		condetion_number(data, &t, c, &i);
		t += 40;
	}
	free(c);
}

void	start_game_and_menue(t_data *data)
{
	if (data->color_increment <= 40)
	{
		rander_image(&data->img, (t_rect){0, 0, data->demension_hight,
			data->demintion_with, 18573});
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->img.mlx_img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->number.logo, data->demintion_with / 2 - (422 / 2),
			data->demension_hight / 2 - 259 / 2);
		data->color_increment++;
	}
	else
	{
		destroy(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->menu.start, data->demintion_with / 2
			- data->menu.hover_start, data->demension_hight / 2 - 100);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->menu.quit, data->demintion_with / 2 - data->menu.hover_quit,
			data->demension_hight / 2);
	}
}
