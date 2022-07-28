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
		if (key == 2 ) //d
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
 	double NO_P;
	double WE_P;
	double EA_P;
	double SO_P;
	static int i;
	NO_P = data->pa;
	EA_P = data->pa - (3*M_PI)/2;
	SO_P = data->pa + M_PI;
	WE_P = data->pa - M_PI/2;

	 if(EA_P < 0)
		EA_P += 2 * M_PI;
	if (SO_P > 2 * M_PI)
		SO_P -= 2 * M_PI;
	else if (WE_P < 0)
		WE_P += 2 * M_PI;
	if(i == 50)
	{
		if(data->ON_KEYDOWN_DERECTION == 1)
		{
			if(data->KEY_W == 1 && one_ray(data,NO_P) > 2)
			move(data, sin(data->pa) * 2, cos(data->pa) * 2);
		else if(data->KEY_S == 1 && one_ray(data,SO_P) > 2)
			move(data, -sin(data->pa) * 2, -cos(data->pa) * 2);
		else if(data->KEY_A == 1 && one_ray(data,WE_P) > 2)
			move(data,-cos(-data->pa) * 2 ,-sin(-data->pa) * 2);
		else if(data->KEY_D == 1 && one_ray(data,EA_P) > 2)
			move(data,cos(-data->pa) * 2 ,-sin(data->pa) * 2);
		}
		if(data->ON_KEYDOWN_CAMERA == 1)
		{
			if(data->KEY_WRIGHT == 1)
			{
				data->pa += 0.05;
				if(data->pa > 2 * M_PI)
					data->pa -= 2 * M_PI;
			}
			if(data->KEY_LEFT == 1)
			{
				data->pa -= 0.05;
				if(data->pa < 0)
					data->pa += 2 * M_PI;
			}
			move_rotated(data);
		}
		i = 0;
	}
	i++;
	return (0);
}
