/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:01:09 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/19 21:00:48 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/cub.h"

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
int mouse_move(int x,int y,t_data *data)
{
	data->menu.hover_quit = (150 / 2);
	data->menu.hover_start = (150 / 2);
	data->menu.quit = mlx_xpm_file_to_image(data->mlx,
			data->menu.quit_path, &data->img_width, &data->img_height); 
	data->menu.start = mlx_xpm_file_to_image(data->mlx,
			data->menu.start_path, &data->img_width, &data->img_height);
	if(x > 426 && x < 575 && y > 400 && y < 450 && data->begin_game == 0 && data->color_increment > 40)//start
	{
		data->menu.start = mlx_xpm_file_to_image(data->mlx,
			data->menu.start_hover_path, &data->img_width, &data->img_height); 
		data->menu.hover_start += 15;
	}
	else if(x > 426 && x < 575 && y > 500 && y < 550 && data->begin_game == 0 && data->color_increment > 40)//quit
	{
		data->menu.quit = mlx_xpm_file_to_image(data->mlx,
			data->menu.quit_hover_path, &data->img_width, &data->img_height); 
		data->menu.hover_quit += 15;
	}
	return(0);
}

void *click(void *var)
{
	(void)var;
	system("afplay -v 70 ./assets/sound/click.mp3");
	
	return(0);
}
void *background(void *var)
{
	t_data	*data;

	data = (t_data *)var;
	data->sound_loop = system("while :; do afplay -v 70 ./assets/sound/background2.mp3; done");
	fprintf(stderr, "%d\n",55555);
	return(0);
}

int mouse_down(int button ,int x,int y,t_data *data)
{
	pthread_t			id;
	
	if (button == 1 && data->begin_game == 0 && data->color_increment > 40)
	{
		if(x > 426 && x < 575 && y > 400 && y < 450)//start
		{
			pthread_create(&id, NULL, &click, NULL);
			data->begin_game = 1;
		}
		else if(x > 426 && x < 575 && y > 500 && y < 550)//quit
		{
			pthread_create(&id, NULL, &click, NULL);
			mouse();
		}
			
	}
	return(0);
}
int	main(int ac, char **av)
{
	t_data	data;

	if (av[1])
		check_cub(av[1]);
	data.result = check_map(av[1], &data);
	data.result_back_up = check_map(av[1], &data);
	(void) ac;
	if (ac == 2)
	{
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
	//fix_movment : kolama brekti wnta 7da l7it kolama t3tlti bach trje3
	return (0);
}
