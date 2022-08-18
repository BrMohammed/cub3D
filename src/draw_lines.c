#include "../Includes/cub.h"

void	draw_linev4_for_static_imgs(t_data *data, int *begin, int *end,int high,char *addr,int line_len)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	int pixel_color;
	int y = 0;
	int x = 0;
	double p0;
	double p1;
	double new_ang;

	pixel[0] = begin[0] ;
	pixel[1] = begin[1] ;
	delta[0] = ((end[0]) - begin[0]);
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;

	while(x < high)
	{
		pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
		delta[0] /= pixels;
		delta[1] /= pixels;
		y  = high - 1;
		while (pixels)
		{
			if(y > 0)
			{
				pixel_color = get_pixel(addr,line_len,x ,y,high);
				new_ang = data->pa + M_PI/2;
				if(new_ang > M_PI*2)
					new_ang -= M_PI*2;
				p0 = (((pixel[0] - (data->player_x + (data->player_mini_res / 2))) * 
							cos(new_ang)) - (sin(new_ang) * (pixel[1] - (data->player_y + (data->player_mini_res / 2)))))  +  (data->player_x + (data->player_mini_res / 2));
				p1 = (((pixel[0] - (data->player_x + (data->player_mini_res / 2))) * 
							sin(new_ang)) + (cos(new_ang) * (pixel[1] -  (data->player_y + (data->player_mini_res / 2))))) +  (data->player_y + (data->player_mini_res / 2)) ;
				if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H && pixel_color > 0 )
					rander_image(&data->img, (t_rect){p0 ,p1 ,1, 1, pixel_color},data);
				y--;
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
		x++;
	}
}

void	draw_linev3(t_data *data, int *begin, int *end,double wall_scall,double *tabl_of_distences,double distence)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	int pixel_color;
	int y = 0;
	double  temp_y = 0;
	int x = 0;
	double  temp_x = 0;

	pixel[0] = begin[0] ;
	pixel[1] = begin[1] ;
	delta[0] = ((end[0]) - begin[0]);
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;


	while(x < data->coin_res - 1)
	{
		x =  floor((temp_x ) / wall_scall) ;
		pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
		delta[0] /= pixels;
		delta[1] /= pixels;
		y  = 0;
		temp_y = 0;
		while (pixels)
		{
			if(y < data->coin_res - 1)
			{
				y =  floor((temp_y ) / wall_scall) ;
				if(y < data->coin_res && x < data->coin_res)
					pixel_color = get_pixel(data->img_sprite.addr,data->img_sprite.line_len,x,y,data->coin_res);
				if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H && pixel_color > 0 )
				{
					if(distence <= tabl_of_distences[begin[0]])
					{
						rander_image(&data->img, (t_rect){pixel[0], pixel[1],1, 1, pixel_color},data);
					}
				}	
				temp_y++;
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

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = (end[0] - begin[0]);
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels && x < data->map_res)
	{

		if(y < data->map_res)
		{
			y =  floor((temp_y ) / wall_scall) ;
			if(y < data->map_res && x < data->map_res)
				pixel_color = get_pixel(data->img_rander.addr,data->img_rander.line_len,x,y,data->map_res);
			if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H && pixel_color > 0)
				rander_image(&data->img, (t_rect){pixel[0], pixel[1],1, 1, pixel_color},data);
			temp_y++;
		}
		
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
	static int i  = 0;

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels)
	{
		if(data->begin_game == 0)
		{
			color +=  (i << 24);
			i +=7;
		}
		if(pixel[0] > 0  && pixel[0] <  WIN_H && pixel[1] > 0  && pixel[1] <  WIN_H )
			rander_image(&data->img, (t_rect){pixel[0], pixel[1],1, 1, color},data);
		if(data->begin_game == 0)
		{
			color +=  (i << 24);
			i -= 2;
		}
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
}