/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:38:45 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/25 03:46:55 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color + (20 << 24);
}

int	rander_image(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	rander_image_for_mini_player(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	get_pixel(t_get_pixel get_pixel_var)
{
	char	*buffer;
	int		color;

	color = 0;
	if (get_pixel_var.y < get_pixel_var.demention && get_pixel_var.y > 0
		&& get_pixel_var.x > 0 && get_pixel_var.x < get_pixel_var.demention)
	{
		buffer = get_pixel_var.addr + (get_pixel_var.y
				* get_pixel_var.line_len + get_pixel_var.x * (4));
		color = *(int *)buffer;
	}
	return (color);
}
