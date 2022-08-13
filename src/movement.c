#include "../Includes/cub.h"

int	key_down(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if(key == 49)
			data->KEY_SPACE = 1;
	if ((key == 2 || key == 0 || key == 13 || key == 1 ))
	{
		data->ON_KEYDOWN_DERECTION = 1;
		if (key == 2 ) //d
			data->KEY_D = 1;
		else if ( key == 0 )//a
			data->KEY_A = 1;
		if (key == 13 )//w
			data->KEY_W = 1;
		else if (key == 1)//s
			data->KEY_S = 1;
	}
	//126 up
	//125 down
	if(key == 123 || key == 124 || key == 126 || key == 125) 
	{
		data->ON_KEYDOWN_CAMERA = 1;
		if(key == 123) 
			data->KEY_LEFT = 1;
		else if(key == 124)
			data->KEY_WRIGHT = 1;
		if(key == 125) 
			data->KEY_DOWN = 1;
		else if(key == 126)
			data->KEY_UP = 1;
	}
	return(0);
}

int	key_up(int key, t_data *data)
{
	//49 = space
	if ((key == 2 || key == 0 || key == 13 || key == 1 ))
	{
		 data->ON_KEYDOWN_DERECTION = 0;
		if (key == 2) //d
			data->KEY_D = 0;
		else if ( key == 0 )//a
			data->KEY_A = 0;
	    if (key == 13 )//w
			data->KEY_W = 0;
		else if (key == 1)//s
			data->KEY_S = 0;
	}
	if(key == 123 || key == 124 || key == 126 || key == 125) 
	{
		data->ON_KEYDOWN_CAMERA = 0;
		if(key == 123) 
			data->KEY_LEFT = 0;
		else if(key == 124)
			data->KEY_WRIGHT = 0;
		if(key == 125) 
			data->KEY_DOWN = 0;
		else if(key == 126)
			data->KEY_UP = 0;
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
	static int index_of_anim;
	char *path_begin;
	char *path_end;


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
	path_begin = "./assets/YellowCoin/xpm/";
	path_end = ".xpm";
	if(index_of_anim == 0)
		index_of_anim = 1;
	if(i == 30)
	{
		//coin_animation
		data->path_sprite = ft_strjoin(path_begin,ft_itoa(index_of_anim));
		data->path_sprite = ft_strjoin(data->path_sprite,path_end);
		data->img_sprite.mlx_img = mlx_xpm_file_to_image(data->mlx, data->path_sprite,
		&data->p_w, &data->p_h);
		data->img_sprite.addr = mlx_get_data_addr(data->img_sprite.mlx_img, &data->img_sprite.bpp,
		&data->img_sprite.line_len, &data->img_sprite.endian);
		index_of_anim++;
		if(data->KEY_SPACE  == 1)
		{
				// jump;
			if( data->is_jumping_up <= data->gravity && data->is_jumping_down == 0)
			{
				data->lfo9 += data->jump_force;
				data->lte7t -= data->jump_force;
				data->is_jumping_up++;
			}
			if( data->is_jumping_up == data->gravity && data->is_jumping_down >= 0)
			{
				data->lfo9 -= data->jump_force;
				data->lte7t += data->jump_force;
				data->is_jumping_down++;
			}
			if(data->is_jumping_down == data->gravity && data->is_jumping_up == data->gravity)
			{
				data->KEY_SPACE = 0;
				data->is_jumping_up = 0;
				data->is_jumping_down = 0;
			}
			//move_rotated(data);
		}
		if(data->ON_KEYDOWN_DERECTION == 1)
		{
				
			if(data->KEY_W == 1 && ( floor(one_ray(data,NO_P,0)) >= floor((data->player_mini_res*1.7))))
				move(data,( sin(data->pa) * data->speed), (cos(data->pa) * data->speed));
			else if(data->KEY_S == 1 && (floor(one_ray(data,SO_P,0)) >= floor(data->player_mini_res*1.7)))
				move(data, -sin(data->pa) * data->speed, -cos(data->pa) * data->speed);
			if(data->KEY_A == 1 && (floor(one_ray(data,WE_P,0)) >= floor(data->player_mini_res*1.7)))
				move(data,-cos(-data->pa) * data->speed ,-sin(-data->pa) * data->speed);
			else if(data->KEY_D == 1 && (floor(one_ray(data,EA_P,0)) >= floor(data->player_mini_res*1.7)))
				move(data,cos(-data->pa) * data->speed ,-sin(data->pa) * data->speed);
				
		}
		if(data->ON_KEYDOWN_CAMERA == 1)
		{
			if(data->KEY_WRIGHT == 1)
			{
				data->pa += data->angel_speed;
				if(data->pa > 2 * M_PI)
					data->pa -= 2 * M_PI;
			}
			else if(data->KEY_LEFT == 1)
			{
				data->pa -= data->angel_speed;
				if(data->pa < 0)
					data->pa += 2 * M_PI;
			}
			if(data->KEY_UP  == 1)
			{
				
			}
			else if(data->KEY_DOWN == 1)
			{
				
			}
		}
		move_rotated(data);
		i = 0;
	}
	if(index_of_anim == 31)
		index_of_anim = 0;
	i++;
	return (0);
}
