#include "../Includes/cub.h"

int y_detect_loop_for_sprite(t_data *data, int y_plus,int x,double angel,int ray_count)
{
	double b[2];
	double tpx = 0;
	double tpy = 0;
	(void)x;
	(void)y_plus;
	int i;

   // double  m;
	i = 0;
	while(i < data->counter_of_sprites)
	{  
		tpy =  (((data->player_y + (data->player_mini_res / 2))  - (((y_plus) * data->mini_map_res) + ( data->pos_of_sprite_y[i] % data->mini_map_res))));
		tpx =  (tpy / -tan(angel));
		b[1] = floor(data->player_y + (data->player_mini_res / 2) - tpy);
		b[0] = floor(tpx + data->player_x + (data->player_mini_res / 2));//
		if(b[0] == data->pos_of_sprite_x[i] && b[1] == data->pos_of_sprite_y[i] && b[0] >= x * data->mini_map_res && b[0] < (x + 1) * data->mini_map_res )
		{  
			data->px_y = b[0] ;
			data->py_y =  b[1] ;
			data->table_formation_of_spritesy[i][0] = floor(sqrt((tpx*tpx) +(tpy*tpy))) ;
			data->table_formation_of_spritesy[i][1] = ray_count;
		}
		i++;
	}
	return(0);
}

int x_detect_for_sprite_loop(int x_plus,int y,t_data *data,double angel,int ray_count)
{
	double b[2];
	double tpx =0;
	double tpy = 0;
	(void)y;
	int i;

	i = 0;
	while(i < data->counter_of_sprites)
	{
		tpx = (	(data->player_x + (data->player_mini_res / 2)) - ((x_plus) * data->mini_map_res + ( data->pos_of_sprite_x[i] % data->mini_map_res)));
		tpy = ( tpx * tan(angel));
		b[1] = floor((data->player_y +  (data->player_mini_res / 2)) - tpy);//
		b[0] = floor(((x_plus) * data->mini_map_res + ( data->pos_of_sprite_x[i] % data->mini_map_res)));
		if (b[1] == data->pos_of_sprite_y[i] && b[0] == data->pos_of_sprite_x[i] &&  
			floor(b[1] / data->mini_map_res) == y  && floor(b[0] / data->mini_map_res) == x_plus )
		{
			data->px_x = b[0]; 
			data->py_x =  b[1];
			data->table_formation_of_spritesx[i][0] = floor(sqrt((tpx*tpx) +(tpy*tpy)));
			data->table_formation_of_spritesx[i][1] = ray_count;
		}
		i++;
	}
	return(0);
}

double ray_colesion_for_sprite(t_data *data,double *tabl_of_distences)
{
	t_raycolesion rc_var;
   double wall_scall;
	(void)tabl_of_distences;

	int i = 0;

	while(i < data->counter_of_sprites)
	{
		if ((data->table_formation_of_spritesy[i][0] <=  data->table_formation_of_spritesx[i][0] &&  data->table_formation_of_spritesy[i][0] != 0 ) ||  data->table_formation_of_spritesx[i][0] == 0)
			rc_var.distance = data->table_formation_of_spritesy[i][0];
		else if( (data->table_formation_of_spritesx[i][0] <= data->table_formation_of_spritesy[i][0] && data->table_formation_of_spritesx[i][0] != 0 ) || data->table_formation_of_spritesy[i][0] == 0)
			rc_var.distance = data->table_formation_of_spritesx[i][0] ;
		if(rc_var.distance > 0)
		{
			rc_var.distance = ((((((rc_var.distance ) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2)) ;
			rc_var.ray_count = data->table_formation_of_spritesy[i][1]; 
			if(data->table_formation_of_spritesy[i][1] == 0)
				rc_var.ray_count = data->table_formation_of_spritesx[i][1]; 
			rc_var.distanceprojplan = ((WIN_W / 2) / tan((M_PI/6)));
			rc_var.wallHeight = (((data->coin_res ) / (rc_var.distance)) * rc_var.distanceprojplan);
			// //WALL
			wall_scall = rc_var.wallHeight / data->coin_res;
			rc_var.begin[0] = rc_var.ray_count - (wall_scall * data->coin_res/2);
			rc_var.begin[1] = (WIN_H / 2) - (rc_var.wallHeight / 2) + (rc_var.wallHeight/1.2);
			rc_var.end[0] = rc_var.ray_count - (wall_scall * data->coin_res/2);
			rc_var.end[1] = (WIN_H / 2) + (rc_var.wallHeight / 2) + (rc_var.wallHeight/1.2);
			draw_linev3(data, rc_var.begin, rc_var.end,wall_scall,tabl_of_distences,rc_var.distance);
		}
		data->table_formation_of_spritesy[i][0] = 0;
		data->table_formation_of_spritesy[i][1] = 0;
		data->table_formation_of_spritesx[i][0] = 0;
		data->table_formation_of_spritesx[i][1] = 0;
		i++;
	}
	return(rc_var.distance);
}