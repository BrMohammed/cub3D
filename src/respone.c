/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:01:42 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/19 16:41:22 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	continue_alocation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->counter_of_sprites)
	{
		data->table_formation_of_spritesy[i] = malloc(sizeof(int) * 2);
		data->table_formation_of_spritesy[i][0] = 0;
		data->table_formation_of_spritesy[i][1] = 0;
		data->table_formation_of_spritesx[i] = malloc(sizeof(int) * 2);
		data->table_formation_of_spritesx[i][0] = 0;
		data->table_formation_of_spritesx[i][1] = 0;
		i++;
	}
}

void	aloccation_sprites(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 50)
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	data->counter_of_sprites = i;
	data->table_formation_of_spritesy = (int **)malloc(sizeof(int *) * (i));
	data->table_formation_of_spritesx = (int **)malloc(sizeof(int *) * (i));
	data->pos_of_sprite_x = malloc(sizeof(int) * (i));
	data->pos_of_sprite_y = malloc(sizeof(int) * (i));
	continue_alocation(data);
}

void	aloccation_sprites_and_storage(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 50)
			{
				data->pos_of_sprite_x[i] = (x * 10) + 5;
				data->pos_of_sprite_y[i] = (y * 10) + 5;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	respone(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->result[y])
	{
		while (data->result[0][x])
			x++;
		y++;
	}
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->demintion_with,
			data->demension_hight, "cub3d");
	data->img.mlx_img = mlx_new_image(data->mlx, data->demintion_with,
			data->demension_hight);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	aloccation_sprites(data);
	aloccation_sprites_and_storage(data);
	
}
