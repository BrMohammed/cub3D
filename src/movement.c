#include "../Includes/cub.h"

int	key_down(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (key == 2 || key == 0 || key == 13 || key == 1)
	{
		data->ON_KEYDOWN_DERECTION = 1;
		if (key == 2) //d
			data->KEY_D = 1;
		else if ( key == 0 )//a
			data->KEY_A = 1;
		else if (key == 13 )//w
			data->KEY_W = 1;
		else if (key == 1)//s
			data->KEY_S = 1;
	}
	if(key == 123 || key == 124) 
	{
		data->ON_KEYDOWN_CAMERA = 1;
		if(key == 123) 
			data->KEY_LEFT = 1;
		else if(key == 124)
			data->KEY_WRIGHT = 1;
	}
	return(0);
}

int	key_up(int key, t_data *data)
{
	if ((key == 2 || key == 0 || key == 13 || key == 1 ))
	{
		data->ON_KEYDOWN_DERECTION = 0;
		if (key == 2) //d
			data->KEY_D = 0;
		else if ( key == 0 )//a
			data->KEY_A = 0;
		else if (key == 13 )//w
			data->KEY_W = 0;
		else if (key == 1)//s
			data->KEY_S = 0;
	}
	if(key == 123 || key == 124) 
	{
		data->ON_KEYDOWN_CAMERA = 0;
		if(key == 123) 
			data->KEY_LEFT = 0;
		else if(key == 124)
			data->KEY_WRIGHT = 0;
	}
	return(0);
}

int	movement(t_data *data)
{
	if(data->ON_KEYDOWN_DERECTION == 1)
	{
		if(data->KEY_W == 1)
			move(data, sin(data->pa) * 5, cos(data->pa) * 5);
		else if(data->KEY_S == 1)
			move(data, -sin(data->pa) * 5, -cos(data->pa) * 5);
		else if(data->KEY_A == 1)
			move(data,-cos(-data->pa) * 5 ,-sin(-data->pa) * 5);
		else if(data->KEY_D == 1)
			move(data,cos(-data->pa) * 5 ,-sin(data->pa) * 5);
		ray_colesion(data);
	}
	if(data->ON_KEYDOWN_CAMERA == 1)
	{
		if(data->KEY_WRIGHT == 1)
		{
			data->pa += 0.02;
			if(data->pa > 2 * M_PI)
				data->pa -= 2 * M_PI;
		}
		if(data->KEY_LEFT == 1)
		{
			data->pa -= 0.02;
			if(data->pa < 0)
				data->pa += 2 * M_PI;
		}
		move_rotated(data);
		ray_colesion(data);
	}
	return (0);
}
