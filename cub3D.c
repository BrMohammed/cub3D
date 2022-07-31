#include "Includes/cub.h"

int	mouse(void)
{
	exit(0);
	return (0);
}

void	draw_line(t_data *data, int *begin, int *end, int color)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	if (begin[0] < 0)
		begin[0] = 0;
	if (begin[1] < 0)
		begin[1] = 0;
	if (end[0] < 0)
		end[0] = 0;
	if (end[1] < 0)
		end[1] = 0;
	if (begin[0] > WIN_W)
		begin[0] = WIN_W;
	if (begin[1] > WIN_H)
		begin[1] = WIN_H;
	if (end[0] > WIN_W)
		end[0] = WIN_W;
	if (end[1] > WIN_H)
		end[1] = WIN_H;

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels)
	{
		rander_image(&data->img, (t_rect){pixel[0], pixel[1],1, 1, color});
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
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

	if (av[1])
		check_cub(av[1]);
	data.result = check_map(av[1],&data);
	(void) ac;
	if (ac == 2)
	{
		data.lfo9 = 100;
		data.ltet = 100;
		data.demension_hight = 1000;
		data.demintion_with = 1000;
		data.box_high = data.demension_hight / data.result_hight;
		data.box_with = data.demintion_with / data.result_with;
		printf("%f----%f\n",data.box_high,data.box_with);
		respone(&data);
		respone_obj(&data);
		mlx_hook(data.mlx_win, 2, 0, key_down, &data);
		mlx_hook(data.mlx_win, 3, 0, key_up, &data);
		mlx_loop_hook(data.mlx, &movement, &data);
		mlx_hook(data.mlx_win, 17, 0, &mouse, &data);
	    mlx_loop(data.mlx);
		mlx_destroy_image(data.mlx, data.img.mlx_img);
		free(data.mlx);
	}
	return (0);
}
