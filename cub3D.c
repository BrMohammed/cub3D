/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:01:09 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/24 22:05:50 by brmohamm         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;

	(void) ac;
	if (ac == 2)
	{
		if (av[1])
		check_cub(av[1]);
		check_file(av[1],&data);
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
