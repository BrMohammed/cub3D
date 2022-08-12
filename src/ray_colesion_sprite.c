#include "../Includes/cub.h"

int y_detect_loop_for_sprite(t_data *data, int y_plus,int x, double *ray_colesion_y,double angel,int ray_count)
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
        tpy =  (((data->player_y + (data->player_mini_res / 2))  - (((y_plus - 1 ) * data->mini_map_res) + ( data->pos_of_sprite_y[i] % data->mini_map_res))));
        tpx =  (tpy / -tan(angel));
        b[1] = floor(data->player_y + (data->player_mini_res / 2) - tpy);
	    b[0] = floor(tpx + data->player_x + (data->player_mini_res / 2));//
        if(b[0] == data->pos_of_sprite_x[i] && b[1] == data->pos_of_sprite_y[i] && b[0] >= x * data->mini_map_res && b[0] < (x + 1) * data->mini_map_res )
        { 
            *ray_colesion_y =   floor(sqrt((tpx*tpx) +(tpy*tpy))) ;
            data->px_y = b[0] ;
            data->py_y =  b[1] ;
			data->table_pos_of_sprite_y[i][0] = *ray_colesion_y;
			data->table_pos_of_sprite_y[i][1] = ray_count;
			
        }
        i++;
    }
    return(0);
}

int x_detect_for_sprite_loop(int x_plus,int y,t_data *data,double *ray_colesion_x,double angel,int ray_count)
{
	double b[2];
    double tpx =0;
    double tpy = 0;
    (void)y;
    int i;

    i = 0;
    while(i < data->counter_of_sprites)
    {
        tpx = (	(data->player_x + (data->player_mini_res / 2)) - ((x_plus - 1) * data->mini_map_res + ( data->pos_of_sprite_x[i] % data->mini_map_res)));
        tpy = ( tpx * tan(angel));
        b[1] = floor((data->player_y +  (data->player_mini_res / 2)) - tpy);//
        b[0] = floor(tpx + data->player_x + (data->player_mini_res / 2));
        if(b[1] == data->pos_of_sprite_y[i] && b[0] == data->pos_of_sprite_x[i] && b[0] >= (x_plus - 1) * data->mini_map_res && b[0] < (x_plus) * data->mini_map_res )
        {
            *ray_colesion_x = floor(sqrt((tpx*tpx) +(tpy*tpy))) ;
            data->px_x = b[0]  ; 
            data->py_x =  b[1];
			data->table_pos_of_sprite_x[i][0] = *ray_colesion_x;
			data->table_pos_of_sprite_x[i][1] = ray_count;
        }
        i++;
    }
    return(0);
}

// int y_detect_for_sprite(t_data *data,t_oneray *oneray_var, int y_plus,double angel)
// {
// 	int x;
   
// 	x = oneray_var->px;
// 	if(oneray_var->left_begin_agrement_x_from_player == 1)
// 	{
// 		while (data->result[oneray_var->y][x])
// 		{
// 				if(y_detect_loop_for_sprite(data,y_plus,x,&oneray_var->ray_colesion_y,angel) == 1)
// 					return(1);
// 			x++;
// 		}
// 	}
// 	else
// 	{
// 		while (x >= 0)
// 		{
// 			   if(y_detect_loop_for_sprite(data,y_plus,x,&oneray_var->ray_colesion_y,angel) == 1)
// 					return(1);
// 			x--;
// 		}
// 	}
// 	return(0);
// }


// int x_detect_for_sprite(t_oneray *oneray_var,t_data *data,double angel)
// {
// 	int x;
// 	int x_plus;

// 	x = 0;
// 	x_plus = 0;
// 	double degre;
// 	degre = (angel / pi) * 180;
// 	if(oneray_var->left_begin_agrement_x_from_player_x == 1)
// 	{
// 		x = oneray_var->px;
// 		while (x >= 0)
// 		{
// 			if((degre >= 270 && degre <= 90 ))
// 			   x_plus = x;
// 			else
// 				x_plus = x + 1;
// 				if(x_detect_for_sprite_loop(x_plus,oneray_var->y,data,&oneray_var->ray_colesion_x,angel) == 1)
// 					return(1);
// 			x--;
// 		}
// 	}
// 	else
// 	{
// 		x = oneray_var->px;
// 		x++;
// 		while (data->result[oneray_var->y][x])
// 		{
// 			if((degre >= 270 && degre <= 90 ))
// 			   x_plus = x + 1;
// 			else
// 				x_plus = x;
// 				if(x_detect_for_sprite_loop(x_plus,oneray_var->y,data,&oneray_var->ray_colesion_x,angel) == 1)
// 					return(1);
// 			x++;
// 		}
// 	}
// 	 return(0);
// }

// double one_ray_for_sprite(t_data *data,double angel)
// {
// 	t_oneray oneray_var;
//     int a[2];
//     int b[2];

// 	oneray_var.y = 0;
// 	oneray_var.x = 0;
// 	oneray_var.ray_colesion_y = 0;
// 	oneray_var.ray_colesion_x = 0;
// 	oneray_var.degre = (angel / pi) * 180;
// 	while(data->result[ oneray_var.y]) //know position of player in map
// 	{
// 		if(data->player_y + (data->player_mini_res / 2) >=  oneray_var.y * data->mini_map_res && data->player_y + (data->player_mini_res / 2) <= ( oneray_var.y + 1) * data->mini_map_res) // player posetion y
// 			 oneray_var.py =  oneray_var.y;
// 		 oneray_var.x = 0;
// 		while(data->result[ oneray_var.y][ oneray_var.x])
// 		{
// 			if(data->player_x + (data->player_mini_res / 2) >=  oneray_var.x * data->mini_map_res && data->player_x + (data->player_mini_res / 2) <= ( oneray_var.x + 1) * data->mini_map_res) //player posetion x
// 				 oneray_var.px =  oneray_var.x;
// 			 oneray_var.x++;
// 		}
// 		 oneray_var.y++;
// 	}
// 	if(( oneray_var.degre <= 360 &&  oneray_var.degre > 180))
// 	{
// 		 oneray_var.y =  oneray_var.py;
// 		if( oneray_var.degre <= 360 &&  oneray_var.degre > 270)
// 		{
// 			 oneray_var.left_begin_agrement_x_from_player = 1;
// 			 oneray_var.left_begin_agrement_x_from_player_x = 0;
// 		}
// 		if( oneray_var.degre <= 270 &&  oneray_var.degre > 180)
// 		{
// 			oneray_var.left_begin_agrement_x_from_player = 0;
// 			oneray_var.left_begin_agrement_x_from_player_x = 1;
// 		}
			
// 		while( oneray_var.y >= 0)
// 		{
// 			if((y_detect_for_sprite(data, &oneray_var, oneray_var.y + 1,angel) == 1 ||
// 				 x_detect_for_sprite(&oneray_var,data,angel) == 1) )
// 				break;
// 			 oneray_var.y--;
// 		}
// 	 }
// 	else
// 	{
// 		 oneray_var.y =  oneray_var.py;
// 		if( oneray_var.degre <= 180 &&  oneray_var.degre > 90)
// 		{
// 			 oneray_var.left_begin_agrement_x_from_player = 0;
// 			 oneray_var.left_begin_agrement_x_from_player_x = 1;
// 		}
			
// 		if( oneray_var.degre <= 90 &&  oneray_var.degre > 0)
// 		{
// 			 oneray_var.left_begin_agrement_x_from_player = 1;
// 			 oneray_var.left_begin_agrement_x_from_player_x = 0;
// 		} 
// 		while(data->result[ oneray_var.y])
// 		{
// 			if(y_detect_for_sprite(data, &oneray_var, oneray_var.y,angel) == 1 ||
// 				x_detect_for_sprite(&oneray_var,data,angel) == 1)
// 				break;
// 			 oneray_var.y++;
// 		}
// 	}

//     a[0] = data->player_x + 2;
//     a[1] = data->player_y + 2;
//     if (( oneray_var.ray_colesion_y <=  oneray_var.ray_colesion_x &&  oneray_var.ray_colesion_y != 0 ) ||  oneray_var.ray_colesion_x == 0)
// 	{
//         b[0] = data->px_y;
//         b[1] = data->py_y ;
//         oneray_var.distance = oneray_var.ray_colesion_y;
//         data->color = 15722729;
//         if(oneray_var.distance != 0)
//          draw_line(data, a, b, 0Xff0000);
//     }
//     else if( (oneray_var.ray_colesion_x <= oneray_var.ray_colesion_y && oneray_var.ray_colesion_x != 0 ) || oneray_var.ray_colesion_y == 0)
//     {
//         b[0] = data->px_x;
//         b[1] = data->py_x ;
//         oneray_var.distance = oneray_var.ray_colesion_x ;
//          data->color = 15722729;
//         if(oneray_var.distance != 0)
//          draw_line(data, a, b, 0Xff0000);
//     }
    
//     return(oneray_var.distance);
// }

double ray_colesion_for_sprite(t_data *data,double *tabl_of_distences)
{
    t_raycolesion rc_var;
   double wall_scall;
	(void)tabl_of_distences;

	int i = 0;

    while(i < data->counter_of_sprites)
    {
			 if ((data->table_pos_of_sprite_y[i][0] <=  data->table_pos_of_sprite_x[i][0] &&  data->table_pos_of_sprite_y[i][0] != 0 ) ||  data->table_pos_of_sprite_x[i][0] == 0)
				rc_var.distance = data->table_pos_of_sprite_y[i][0];
			else if( (data->table_pos_of_sprite_x[i][0] <= data->table_pos_of_sprite_y[i][0] && data->table_pos_of_sprite_x[i][0] != 0 ) || data->table_pos_of_sprite_y[i][0] == 0)
				rc_var.distance = data->table_pos_of_sprite_x[i][0] ;
			rc_var.distance = ((((((rc_var.distance ) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2)) ;
			rc_var.ray_count = data->table_pos_of_sprite_y[i][1];
			rc_var.distanceprojplan = ((WIN_W / 2) / tan((M_PI/6)));
			rc_var.wallHeight = (((data->coin_res ) / (rc_var.distance)) * rc_var.distanceprojplan);
			// //WALL
			wall_scall = rc_var.wallHeight / data->coin_res;
			rc_var.begin[0] = rc_var.ray_count - (wall_scall * data->coin_res/2);
			rc_var.begin[1] = (WIN_H / 2) - (rc_var.wallHeight / 2) + (rc_var.wallHeight/1.2);
			rc_var.end[0] = rc_var.ray_count - (wall_scall * data->coin_res/2);
			rc_var.end[1] = (WIN_H / 2) + (rc_var.wallHeight / 2) + (rc_var.wallHeight/1.2);
			if(rc_var.distance > 0 && rc_var.ray_count < WIN_W - 1 && rc_var.ray_count > 50)
				draw_linev3(data, rc_var.begin, rc_var.end,wall_scall,tabl_of_distences,rc_var.distance);
		   
		i++;
	}
    return(rc_var.distance);
}