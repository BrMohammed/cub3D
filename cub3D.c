/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:01:09 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/26 20:40:10 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/cub.h"

int	error(char *msg, t_pars *pars)
{
	printf("Error\n %s\n", msg);
	if (pars)
		close(pars->fd);
	exit(0);
}

int	mouse(void)
{
	kill(0, SIGKILL);
	exit(0);
	return (0);
}

void	check_cub(char *str)
{
	int		i;
	char	*cub;
	int		l;

	cub = "buc.";
	i = 0;
	while (str[i])
			i++;
	i--;
	l = 0;
	while (cub[l] != '\0')
	{
		if (cub[l] != str[i])
			exit(0);
		l++;
		i--;
	}
}

void	back_up(t_data *data)
{
	int	y;

	y = 0;
	while (data->result[y])
		y++;
	y++;
	data->back_up = (char **)malloc(sizeof(char *) * y);
	data->back_up[y - 1] = NULL;
	y = 0;
	while (data->back_up[y])
	{
		data->back_up[y] = ft_strdup(data->result[y]);
		y++;
	}
}
void	free_data(t_data *data)
{
	int	i;

	free(data->no_tex_path);
	free(data->so_tex_path);
	free(data->we_tex_path);
	free(data->ea_tex_path);
	i = 0;
	while (data->result[i])
	{
		free(data->result[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	(void) ac;
	if (ac == 2)
	{
		check_cub(av[1]);
		check_file(av[1], &data);
		back_up(&data);
		initial_var(&data);
		respone(&data);
		inisial_path(&data);
		respone_obj(&data);
		mlx_hook(data.mlx_win, 2, 0, key_down, &data);
		mlx_hook(data.mlx_win, 3, 0, key_up, &data);
		mlx_hook(data.mlx_win, 6, 0, mouse_move, &data);
		mlx_hook(data.mlx_win, 4, 0, mouse_down, &data);
		mlx_loop_hook(data.mlx, &movement, &data);
		mlx_hook(data.mlx_win, 17, 0, &mouse, &data);
		mlx_loop(data.mlx);
		mlx_destroy_image(data.mlx, data.img.mlx_img);
		free(data.mlx);
	}
	return (0);
}
