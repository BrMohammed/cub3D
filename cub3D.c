#include "Includes/cub.h"

int	mouse(void)
{
	exit(0);
	return (0);
}

void	draw_linev3(t_data *data, int *begin, int *end,double wall_scall)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	int pixel_color;
	int y = 0;
	double  temp_y = 0;
	int x = 0;
	double  temp_x = 0;

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = (end[0] - begin[0]);
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;

	while(x < 199)
	{
		x =  floor((temp_x ) / wall_scall) ;
		pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
		delta[0] /= pixels;
		delta[1] /= pixels;
		y  = 0;
		temp_y = 0;
		while (pixels)
		{
			
			if(y < 200)
			{
				y =  floor((temp_y ) / wall_scall) ;
				
				pixel_color = get_pixel(data->img_sprite.addr,data->img_sprite.line_len,x,y);
				//printf("x = %d y = %d\n",x,y);
				temp_y++;
			}
			if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H && pixel_color > 0)
			{
				
				rander_image(&data->img, (t_rect){pixel[0], pixel[1],1, 1, pixel_color});
			}	
			pixel[0] += delta[0];
			pixel[1] += delta[1];
			--pixels;
		}
		begin[0]++;
		end[0]++;
		pixel[0] = begin[0];
		pixel[1] = begin[1];
		delta[0] = (end[0] - begin[0]);
		delta[1] = end[1] - begin[1];
		temp_x++;
	}
	
}

void	draw_linev2(t_data *data, int *begin, int *end, int x,double wall_scall)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	int pixel_color;
	int y = 0;
	double  temp_y = 0;
	// if (begin[0] < 0)
	// 	begin[0] = 0;
	// if (begin[1] < 0)
	// 	begin[1] = 0;
	// if (end[0] < 0)
	// 	end[0] = 0;
	// if (end[1] < 0)
	// 	end[1] = 0;
	// if (begin[0] > WIN_W)
	// 	begin[0] = WIN_W;
	// if (begin[1] > WIN_H)
	// 	begin[1] = WIN_H;
	// if (end[0] > WIN_W)
	// 	end[0] = WIN_W;
	// if (end[1] > WIN_H)
	// 	end[1] = WIN_H;

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = (end[0] - begin[0]);
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels)
	{

		if(y < data->map_res)
		{
			y =  floor((temp_y ) / wall_scall) ;
				pixel_color = get_pixel(data->img_rander.addr,data->img_rander.line_len,x,y);
			temp_y++;
		}
		if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H)
			rander_image(&data->img, (t_rect){pixel[0], pixel[1],1, 1, pixel_color});
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
}

void	draw_line(t_data *data, int *begin, int *end, int color)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	

	// if (begin[0] < 0)
	// 	begin[0] = 0;
	// if (begin[1] < 0)
	// 	begin[1] = 0;
	// if (end[0] < 0)
	// 	end[0] = 0;
	// if (end[1] < 0)
	// 	end[1] = 0;
	// if (begin[0] > WIN_W)
	// 	begin[0] = WIN_W;
	// if (begin[1] > WIN_H)
	// 	begin[1] = WIN_H;
	// if (end[0] > WIN_W)
	// 	end[0] = WIN_W;
	// if (end[1] > WIN_H)
	// 	end[1] = WIN_H;

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels)
	{
		if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H)
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
		data.lfo9 = 10;
		data.lte7t = 10;
		data.demension_hight = 1000;
		data.demintion_with = 1000;
		if((data.demension_hight / data.result_hight) < (data.demintion_with / data.result_with) )
			data.mini_map_res = (data.demension_hight / data.result_hight) / 3;
		else
			data.mini_map_res = (data.demintion_with / data.result_with) / 3;
		data.map_res = 1000;
		data.player_mini_res = data.mini_map_res / 2;
		data.speed = 4;
		data.angel_speed = 0.15707963267;
		data.is_jumping_up = 0;
		data.is_jumping_down = 0;
		data.jump_force = 40;
		data.gravity = 3;
		respone(&data);

			data.img_rander.mlx_img = mlx_xpm_file_to_image(data.mlx, data.NO_PATH,
		&data.map_res, &data.map_res);
	data.img_rander.addr = mlx_get_data_addr(data.img_rander.mlx_img, &data.img_rander.bpp,
		&data.img_rander.line_len, &data.img_rander.endian);

		data.test_path = "./assets/point.xpm";
		data.test = mlx_xpm_file_to_image(data.mlx, data.test_path,
		&data.p_w, &data.p_h);

		data.path_sprite = "./assets/sprite.xpm";
		data.img_sprite.mlx_img = mlx_xpm_file_to_image(data.mlx, data.path_sprite,
		&data.p_w, &data.p_h);
		data.img_sprite.addr = mlx_get_data_addr(data.img_sprite.mlx_img, &data.img_sprite.bpp,
		&data.img_sprite.line_len, &data.img_sprite.endian);
		
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
