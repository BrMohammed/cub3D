#include "../Includes/cub.h"



void	respone_obj(t_data *data)
{
	int	x;
	int y;
	int a[2];
	int b[2];

	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
				data->result[y][x] == 'W' || data->result[y][x] == 'E')
			{
				data->player_y = y * data->mini_map_res;
				data->player_x = x * data->mini_map_res;
				data->player_y_for_3d = y * data->map_res;
				data->player_x_for_3d = x * data->map_res;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ray_colesion(data);
	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 49 )
				rander_image(&data->img, (t_rect){x * data->mini_map_res, y * data->mini_map_res,data->mini_map_res, data->mini_map_res, 9524926});
			else if (data->result[y][x] == 48 || data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
					data->result[y][x] == 'W' || data->result[y][x] == 'E')
					rander_image(&data->img, (t_rect){x * data->mini_map_res, y * data->mini_map_res,data->mini_map_res, data->mini_map_res, 11796399});
			else if (data->result[y][x] == 50 )
			{
				rander_image(&data->img, (t_rect){x * 10, y * 10,10, 10, 13422336});
			}
			x++;
		}
		x = 0;
		y++;
	}
	
	x = 0;
	y = 0;
	while (data->result[y] != '\0')
	{
		while (data->result[y][x] != '\0')
		{
			if (data->result[y][x] == 'N' || data->result[y][x] == 'S' ||
				data->result[y][x] == 'W' || data->result[y][x] == 'E')
			{
				if(data->result[y][x] == 'N')
					data->pa = (3 * M_PI) / 2;
				if(data->result[y][x] == 'S')
					data->pa = (M_PI) / 2;
				if(data->result[y][x] == 'E')
					data->pa = 0;
				if(data->result[y][x] == 'W')
					data->pa = (M_PI);
				data->result[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	  //arow
	a[0] = data->player_x + (data->player_mini_res / 2);
    a[1] = data->player_y + (data->player_mini_res / 2);
	int a0 = a[0];
	int a1 = a[1];
	double point;
    b[0] = a[0] + cos(data->pa) * 6;
    b[1] = a[1] + sin(data->pa) * 6;
   	draw_line(data, a, b, 0Xff0000);
	point = data->pa + M_PI/3.5;
	if(point > 2 * M_PI)
			point -= 2 * M_PI;
	a[0] =  a0  + (cos(point) * 3);
    a[1] = a1  + (sin(point) * 3);
   	draw_line(data, a, b, 0Xff0000);
	point = data->pa + M_PI/2.5;
	if(point > 2 * M_PI)
			point -= 2 * M_PI;
	a[0] =  a0  + (cos(point) * 3);
    a[1] = a1  + (sin(point) * 3);
   	draw_line(data, a, b, 0Xff0000);
	point = data->pa - M_PI/3.5;
    if(point < 0 )
        point += 2*M_PI;
	a[0] = a0 + (cos(point) * 3);
    a[1] = a1 + (sin(point) * 3);
   	draw_line(data, a, b, 0Xff0000);
	point = data->pa - M_PI/4;
    if(point < 0 )
        point += 2*M_PI;
	a[0] = a0 + (cos(point) * 3);
    a[1] = a1 + (sin(point) * 3);
   	draw_line(data, a, b, 0Xff0000);
	//ray_colesion(data);
}
