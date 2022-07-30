#include "../Includes/cub.h"

int y_detect_loop(t_data *data, int y_plus,int x, double *ray_colesion_y,double angel)
{
	double b[2];
    double tpx = 0;
    double tpy = 0;

   // double  m;
    tpy =  ((data->player_y + 2) - (((y_plus ) * 10)));
    tpx =  (tpy / -tan(angel));
    b[1] = (((y_plus) * 10));
    b[0] = floor(tpx + data->player_x + 2);
   
    if(b[0] >= x * 10 && b[0] <= (x + 1) * 10)
    { 
        *ray_colesion_y =  fabs((tpy / sin(angel))) ;
        // printf("x = %f y = %f\n\n",b[0],b[1]);
         //*ray_colesion_y =   sqrt((tpx*tpx) +(tpy*tpy));
        // printf("x = %f y = %f\n",b[0],b[1]);
        // printf("destins_bw_x = %f ----\n",b[0] - data->px_y);
        // m = tpy / tpx; 
        // printf("m = %f\n----\n",m);
        // printf("c_y = %f\n----\n",*ray_colesion_y);
        // m = tpy - (((data->player_y + 2) - (((y_plus  -1 ) * 10)))); 
        // printf("m2 = %f\n----\n",m);
        // printf("data->player_y = %f (y) =  %d \n----\n",(data->player_y + 2) , ((y_plus ) * 10));
       
        data->px_y = b[0];
        data->py_y =  b[1];
        return(1);
    }
    return(0);
}

int x_detect_loop(int x_plus,int y,t_data *data,double *ray_colesion_x,double angel)
{
	double b[2];
    double tpx =0;
    double tpy = 0;
    tpx = ((data->player_x + 2) - (((x_plus) * 10)));
    tpy = tpx * tan(angel);
    b[1] = (data->player_y +  2) - tpy;
    b[0] = (((x_plus) * 10));
    if(b[1] >= y * 10 && b[1] <= (y + 1) * 10)
    {
        *ray_colesion_x =  sqrt(pow(tpx,2) + pow(tpy,2));
        // printf("x = %f y = %f\n",b[0],b[1]);
        // printf("destins_bw_y = %f ----\n",b[1] - data->py_x);
        // printf("c_x = %f\n----\n",*ray_colesion_x);
        data->px_x = b[0];
        data->py_x =  b[1];
        return(1);
    }
    return(0);
}

int y_detect(t_data *data,int y, int y_plus,int px,int left_begin_agrement_x_from_player, double *ray_colesion_y,double angel)
{
    int x;
   
    x = px;
    if(left_begin_agrement_x_from_player == 1)
    {
        while (data->result[y][x])
        {
            if(data->result[y][x] == '1') //wall detect posetion
            {
                if(y_detect_loop(data,y_plus,x,ray_colesion_y,angel) == 1)
                    return(1);
            }
            x++;
        }
    }
    else
    {
        while (x >= 0)
        {
            if(data->result[y][x] == '1') //wall detect posetion
            {
               if(y_detect_loop(data,y_plus,x,ray_colesion_y,angel) == 1)
                    return(1);
            }
            x--;
        }
    }
    return(0);
}



int x_detect(int left_begin_agrement_x_from_player_x,int px,int y,t_data *data,double *ray_colesion_x,double angel)
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
            
            if(data->result[y][x] == '1') //wall detect posetion
            {
                if(x_detect_loop(x_plus,y,data,ray_colesion_x,angel) == 1)
                    return(1);
            }
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
            if(data->result[y][x] == '1') //wall detect posetion
            {
                if(x_detect_loop(x_plus,y,data,ray_colesion_x,angel) == 1)
                    return(1);
            }
            x++;
        }
    }
     return(0);
}

double one_ray(t_data *data,double angel)
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

      //// ----  y   ------

    // if((degre <= 360 && degre > 180))
    // {
    //     y = py;
    //     if(degre <= 360 && degre > 270)
    //         left_begin_agrement_x_from_player = 1;
    //     if(degre <= 270 && degre > 180)
    //         left_begin_agrement_x_from_player = 0;
    //     while(y >= 0)
    //     {
    //         if(y_detect(data,y,y + 1,px,left_begin_agrement_x_from_player,&ray_colesion_y,angel) == 1)
    //             break;
    //         y--;
    //     }
    //  }
    // else
    // {
    //     y = py;
    //     if(degre <= 180 && degre > 90)
    //         left_begin_agrement_x_from_player = 0;
    //     if(degre <= 90 && degre > 0)
    //         left_begin_agrement_x_from_player = 1;
    //     while(data->result[y])
    //     {
    //         if(y_detect(data,y,y,px,left_begin_agrement_x_from_player,&ray_colesion_y,angel) == 1)
    //             break;
    //         y++;
    //     }
    // }
    // //////// ----------- x --------------- just x betwin 270 and 90

    // if(degre >= 0 && degre <= 180)
    // {
    //     y = py;
    //     if(degre >= 0 && degre < 90)
    //         left_begin_agrement_x_from_player_x = 0;
    //     else
    //         left_begin_agrement_x_from_player_x = 1;
    //     while(data->result[y])
    //     {
    //         if (x_detect(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,angel) == 1)
    //             break; 
    //         y++;
    //     }
    // }
    // else if(degre <= 360 && degre > 180)
    // {
        
    //     y = py;
    //     if(degre <= 270 && degre > 180)
    //         left_begin_agrement_x_from_player_x = 1;
    //     else
    //         left_begin_agrement_x_from_player_x = 0;
    //     while(y >= 0)
    //     {
    //         if (x_detect(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,angel) == 1)
    //             break; 
    //         y--;
    //     }
    // }
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
            if((y_detect(data,y,y + 1,px,left_begin_agrement_x_from_player,&ray_colesion_y,angel) == 1 ||
                 x_detect(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,angel) == 1) )
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
            if((y_detect(data,y,y,px,left_begin_agrement_x_from_player,&ray_colesion_y,angel) == 1 ||
                x_detect(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,angel) == 1))
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
    }
    else if( (ray_colesion_x <= ray_colesion_y && ray_colesion_x != 0 ) || ray_colesion_y == 0)
    {
        b[0] = data->px_x;
        b[1] = data->py_x ;
        end_ray = ray_colesion_x;
         data->color = 16777215;
    }
    
    draw_line(data, a, b, 0Xff0000);
    return(end_ray);
}

void ray_colesion(t_data *data)
{
    double rays;
    double angel_move = 0;
    double point_to_break;
    int a[2];
	int b[2];
    double distance;
    double wallHeight;
    int ray_count;

    angel_move = (M_PI/3) / ((data->result_with) * 50);
    rays =  data->pa;
    rays -= M_PI/6;		
	if(rays < 0)
		rays += 2 * M_PI; 
    point_to_break = 0;	
    ray_count = 0;
    while(ray_count < ((data->result_with) * 50))
    {
        rays += angel_move;
        if(rays > 2 * M_PI)
			rays -= 2 * M_PI;
        distance = one_ray(data,rays);
        double ca = data->pa - rays;
        if(ca < 0 )
            ca += 2*M_PI;
        if(ca > 2*M_PI)
            ca -= 2*M_PI;
        distance = (((((distance - 2) / 10)) * 50) + 7.5) * fabs(cos(ca));
        wallHeight = floor(((((WIN_H / 2) * 50 ) / (distance ))) * tan((M_PI)/3)) ;
         printf("%f ---- %f\n" , wallHeight,distance);
        //sma
        a[0] = ray_count;
        a[1] = 0;
        b[0] = ray_count;
        b[1] = (WIN_H  / 2) - (wallHeight - 200);
        if(distance > 0)
            draw_line(data, a, b, 39679);
        //l2ard
        a[0] = ray_count;
        a[1] = (WIN_H  / 2) + (wallHeight - 200);
        b[0] = ray_count;
        b[1] = WIN_H ;
        if(distance > 0)
            draw_line(data, a, b, 16711935);
        
        //WALL
        a[0] = ray_count;
        a[1] = (WIN_H  / 2) - (wallHeight  + 200);
        b[0] = ray_count;
        b[1] = (WIN_H  / 2) + (wallHeight - 200);
        if(distance > 0)
            draw_line(data, a, b, data->color);
        ray_count++;
    }
    one_ray(data,data->pa);
    a[0] = data->player_x + 2;
    a[1] = data->player_y + 2;
    b[0] = a[0] + cos(data->pa) * 7;
    b[1] = a[1] + sin(data->pa) * 7;
    draw_line(data, a, b, 0Xffffff);
   
}
