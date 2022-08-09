#include "../Includes/cub.h"

int y_detect_loop_for_sprite(t_data *data, int y_plus,int x, double *ray_colesion_y,double angel)
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
        if(b[0] == data->pos_of_sprite_x[i] && b[1] == data->pos_of_sprite_y[i] && b[0] >= x * data->mini_map_res && b[0] < (x + 1) * data->mini_map_res && b[1] >= (y_plus - 1) * data->mini_map_res && b[1] < (y_plus) * data->mini_map_res)
        { 
            *ray_colesion_y =   floor(sqrt((tpx*tpx) +(tpy*tpy))) ;
           //printf("b[1] = %f y = %d *ray_colesion_x = %f\n ",b[1],data->pos_of_sprite_y[i],*ray_colesion_y);
            data->px_y = b[0] ;
            data->py_y =  b[1] ; 
            return(1);
        }
        i++;
    }
    return(0);
}

int x_detect_for_sprite_loop(int x_plus,int y,t_data *data,double *ray_colesion_x,double angel)
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
        if(b[1] == data->pos_of_sprite_y[i] && b[0] == data->pos_of_sprite_x[i] && b[0] >= (x_plus - 1) * data->mini_map_res && b[0] < (x_plus) * data->mini_map_res && b[1] >= (y) * data->mini_map_res && b[1] < (y + 1) * data->mini_map_res)
        {
            *ray_colesion_x = floor(sqrt((tpx*tpx) +(tpy*tpy))) ;
            data->px_x = b[0]  ; 
            data->py_x =  b[1]; 
            return(1);
        }
        i++;
    }
    return(0);
}

int y_detect_for_sprite(t_data *data,int y, int y_plus,int px,int left_begin_agrement_x_from_player, double *ray_colesion_y,double angel)
{
    int x;
   
    x = px;
    if(left_begin_agrement_x_from_player == 1)
    {
        while (data->result[y][x])
        {
                if(y_detect_loop_for_sprite(data,y_plus,x,ray_colesion_y,angel) == 1)
                    return(1);
            x++;
        }
    }
    else
    {
        while (x >= 0)
        {
               if(y_detect_loop_for_sprite(data,y_plus,x,ray_colesion_y,angel) == 1)
                    return(1);
            x--;
        }
    }
    return(0);
}



int x_detect_for_sprite(int left_begin_agrement_x_from_player_x,int px,int y,t_data *data,double *ray_colesion_x,double angel)
{
    int x;
    int x_plus;

    x = 0;
    x_plus = 0;
    double degre;
    degre = (angel / pi) * 180;
    if(left_begin_agrement_x_from_player_x == 1)
    {
        x = px;
        while (x >= 0)
        {
            if((degre >= 270 && degre <= 90 ))
               x_plus = x;
            else
                x_plus = x + 1;
            
                if(x_detect_for_sprite_loop(x_plus,y,data,ray_colesion_x,angel) == 1)
                    return(1);
            x--;
        }
    }
    else
    {
        x = px;
        x++;
        while (data->result[y][x])
        {
            if((degre >= 270 && degre <= 90 ))
               x_plus = x + 1;
            else
                x_plus = x;
            
                if(x_detect_for_sprite_loop(x_plus,y,data,ray_colesion_x,angel) == 1)
                    return(1);
            x++;
        }
    }
     return(0);
}

double one_ray_for_sprite(t_data *data,double angel)
{
    int y = 0;
    int x = 0;
    int px = 0;
    int py = 0;
    int left_begin_agrement_x_from_player = 0;
    int left_begin_agrement_x_from_player_x = 0;
    int a[2];
	int b[2];
    double degre;
    double ray_colesion_y;
    double ray_colesion_x;
    double end_ray = 0;

    
    degre = (angel / pi) * 180;
    ray_colesion_y = 0;
    ray_colesion_x = 0;
    while(data->result[y]) //know position of player in map
    {
        if(data->player_y + 2 >= y * 10 && data->player_y + 2 <= (y + 1) * 10) // player posetion y
            py = y;
        x = 0;
        while(data->result[y][x])
        {
            if(data->player_x + 2 >= x * 10 && data->player_x + 2 <= (x + 1) * 10) //player posetion x
                px = x;
            x++;
        }
        y++;
    }
    if((degre <= 360 && degre > 180))
    {
        y = py;
        if(degre <= 360 && degre > 270)
        {
            left_begin_agrement_x_from_player = 1;
            left_begin_agrement_x_from_player_x = 0;
        }
        if(degre <= 270 && degre > 180)
        {
            left_begin_agrement_x_from_player = 0;
            left_begin_agrement_x_from_player_x = 1;
        }
            
        while(y >= 0)
        {
            if((y_detect_for_sprite(data,y,y + 1,px,left_begin_agrement_x_from_player,&ray_colesion_y,angel) == 1 ||
                 x_detect_for_sprite(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,angel) == 1) )
                break;
            y--;
        }
     }
    else
    {
        y = py;
        if(degre <= 180 && degre > 90)
        {
            left_begin_agrement_x_from_player = 0;
            left_begin_agrement_x_from_player_x = 1;
        }
            
        if(degre <= 90 && degre > 0)
        {
            left_begin_agrement_x_from_player = 1;
            left_begin_agrement_x_from_player_x = 0;
        } 
        while(data->result[y])
        {
            if((y_detect_for_sprite(data,y,y,px,left_begin_agrement_x_from_player,&ray_colesion_y,angel) == 1 ||
                x_detect_for_sprite(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,angel) == 1))
                break;
            y++;
        }
    }

    a[0] = data->player_x + 2;
    a[1] = data->player_y + 2;
    if ((ray_colesion_y <= ray_colesion_x && ray_colesion_y != 0 ) || ray_colesion_x == 0)
    {
        b[0] = data->px_y;
        b[1] = data->py_y ;
        end_ray = ray_colesion_y;
        data->color = 15722729;
        if(end_ray != 0)
         draw_line(data, a, b, 0Xff0000);
    }
    else if( (ray_colesion_x <= ray_colesion_y && ray_colesion_x != 0 ) || ray_colesion_y == 0)
    {
        b[0] = data->px_x;
        b[1] = data->py_x ;
        end_ray = ray_colesion_x ;
         data->color = 15722729;
        if(end_ray != 0)
         draw_line(data, a, b, 0Xff0000);
    }
    
    return(end_ray);
}

double ray_colesion_for_sprite(t_data *data,double *tabl_of_distences)
{
    t_raycolesion rc_var;
    double wall_scall;
    int image_size;
    double large;
    double betwinenngels;
    double dest_temp;

    rc_var.angel_move = (M_PI/3) / WIN_W;
    rc_var.rays =  data->pa;
    rc_var.rays -= M_PI/6 + 0.2;
	if(rc_var.rays < 0)
		rc_var.rays += 2 * M_PI;
    rc_var.ray_count = -200;
    image_size = 0;
    large = 0;
    betwinenngels = 0;
    while(large < M_PI/3 + 0.4)
    {
        rc_var.rays += rc_var.angel_move;
        if(rc_var.rays > 2 * M_PI)
			rc_var.rays -= 2 * M_PI;
        rc_var.distance = one_ray_for_sprite(data,rc_var.rays);
        dest_temp = rc_var.distance;
        betwinenngels = data->pa - rc_var.rays;
        if(betwinenngels < 0 )
            betwinenngels += 2*M_PI;
        if(betwinenngels > 2*M_PI)
            betwinenngels -= 2*M_PI;
        rc_var.distance = ((((((rc_var.distance )) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2) ;
        rc_var.distanceprojplan = ((WIN_W / 2) / tan((M_PI/6)));
        rc_var.wallHeight = (((data->map_res ) / (rc_var.distance)) * rc_var.distanceprojplan);
        // //WALL
        wall_scall = rc_var.wallHeight / data->map_res;
        rc_var.begin[0] = rc_var.ray_count - (wall_scall * data->map_res/2);
        rc_var.begin[1] = (WIN_H / 2) - (rc_var.wallHeight / 2);
        rc_var.end[0] = rc_var.ray_count - (wall_scall * data->map_res/2);
        rc_var.end[1] = (WIN_H / 2) + (rc_var.wallHeight / 2);
        if(rc_var.distance > 0 && image_size != dest_temp && image_size != dest_temp + 1 & image_size != dest_temp - 1)
        {
            printf("dest_temp = %f\n",dest_temp);
            image_size = dest_temp;
            draw_linev3(data, rc_var.begin, rc_var.end,wall_scall,tabl_of_distences,rc_var.distance);
        }
        large += rc_var.angel_move;
        rc_var.ray_count++;
    }
    return(dest_temp);
}