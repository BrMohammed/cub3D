#include "../Includes/cub.h"

int y_detect_loop_for_sprite(t_data *data, int y_plus,int x, double *ray_colesion_y,double angel)
{
	double b[2];
    double tpx = 0;
    double tpy = 0;

   // double  m;
    tpy =  ((data->player_y + 2) - (((y_plus ) * 10)));
    tpx =  (tpy / -tan(angel));
    b[1] = (((y_plus) * 10));
    b[0] = floor(tpx + data->player_x + 2);
   
    if(b[0] >= x * 10 && b[0] < (x + 1) * 10)
    { 
        // tpx += ( (( x ) * 10) - b[1])  / 2;
        // tpy += ( (( x ) * 10) - b[1])  / 2;
        *ray_colesion_y =   sqrt((tpx*tpx) +(tpy*tpy)) ;
         //*ray_colesion_y +=( ( ((x ) * 10)- b[0]) /2 );
        data->px_y = b[0] ;//+ ( ( ((x ) * 10) - b[0]) /2 )
        data->py_y =  b[1] ; //+ ( ( ((x ) * 10) - b[0]) /2 )
        return(1);
    }
    return(0);
}

int x_detect_for_sprite_loop(int x_plus,int y,t_data *data,double *ray_colesion_x,double angel)
{
	double b[2];
    double tpx =0;
    double tpy = 0;
    tpx = ((data->player_x + 2) - (((x_plus) * 10)));
    tpy = tpx * tan(angel);
    b[1] = (data->player_y +  2) - tpy;
    b[0] = (((x_plus) * 10));
    if(b[1] >= y * 10 && b[1] < (y + 1) * 10)
    {
        // tpx += ( (( y ) * 10) - b[1])  / 2;
        // tpy += ( (( y ) * 10) - b[1])  / 2;
        *ray_colesion_x =  sqrt((tpx*tpx) +(tpy*tpy)) ;
          //*ray_colesion_x +=( (( y ) * 10) - b[1])  / 2;
        data->px_x = b[0]  ; //+ ( (( y ) * 10) - b[1])  / 2
        data->py_x =  b[1]; //+ ( (( y ) * 10) - b[1])  / 2
        return(1);
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
            if(data->result[y][x] == '2') //wall detect posetion
            {
                if(y_detect_loop_for_sprite(data,y_plus,x,ray_colesion_y,angel) == 1)
                    return(1);
            }
            x++;
        }
    }
    else
    {
        while (x >= 0)
        {
            if(data->result[y][x] == '2') //wall detect posetion
            {
               if(y_detect_loop_for_sprite(data,y_plus,x,ray_colesion_y,angel) == 1)
                    return(1);
            }
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
            
            if(data->result[y][x] == '2') //sprite detect posetion
            {
                if(x_detect_for_sprite_loop(x_plus,y,data,ray_colesion_x,angel) == 1)
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
            if(data->result[y][x] == '2') //wall detect posetion
            {
                if(x_detect_for_sprite_loop(x_plus,y,data,ray_colesion_x,angel) == 1)
                    return(1);
            }
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
        end_ray = ray_colesion_y * cos(angel - data->pa);
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

void ray_colesion_for_sprite(t_data *data)
{
    double rays;
    double angel_move = 0;
    double point_to_break;
    int a[2];
	int b[2];
    double distance;
    double wallHeight;
    int ray_count;
    static double dest_temp;
    static int last_px ;
    static int last_py ;
    static int loop_break;

    angel_move = (M_PI/3) / WIN_W;
    rays =  data->pa;
    rays -= M_PI/6;		
	if(rays < 0)
		rays += 2 * M_PI;
    point_to_break = 0;	
    ray_count = 0;
    int image_size = 0;
    while(ray_count < WIN_W)
    {
        
        rays += angel_move;
        if(rays > 2 * M_PI)
			rays -= 2 * M_PI;
        distance = one_ray_for_sprite(data,rays);
     
        double ca = data->pa - rays;
        if(ca < 0 )
            ca += 2*M_PI;
        if(ca > 2*M_PI)
            ca -= 2*M_PI;
        distance = (((((distance * fabs(cos(ca))) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2) ;
        if(dest_temp == 0 && distance > 0)
            dest_temp = distance;
       double distanceprojplan = ((WIN_W / 2) / tan((M_PI/6)));
        wallHeight = (((data->map_res ) / (dest_temp)) * distanceprojplan);
        
        // //WALL
        a[0] = ray_count;
        a[1] = (WIN_H / 2) - (wallHeight / 2);
        b[0] = ray_count;
        b[1] = (WIN_H / 2) + (wallHeight / 2);
        if(distance > 0 && image_size < wallHeight/2)
        {
            draw_line(data, a, b, data->color);
            image_size++;
            loop_break++;
        }
        ray_count++;
    }
    if(last_px != data->player_x || last_py != data->player_y)
    {
        last_px = data->player_x;
        last_py = data->player_y;
        dest_temp = 0;
    }
    // one_ray_for_sprite(data,data->pa);
    // a[0] = data->player_x + 2;
    // a[1] = data->player_y + 2;
    // b[0] = a[0] + cos(data->pa) * 7;
    // b[1] = a[1] + sin(data->pa) * 7;
    // draw_line(data, a, b, 0Xffffff);
}