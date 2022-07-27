#include "../Includes/cub.h"

int y_detect_loop(t_data *data, int y_plus,int x, double *ray_colesion_y,double engel)
{
    int a[2];
	int b[2];
    double tpx = 0;
    double tpy = 0;
    tpy = ((data->player_y + 2) - (((y_plus) * 10)));
    tpx = tpy / -tan(engel);
    b[1] = (((y_plus) * 10));
    a[0] = data->player_x + 2;
    a[1] = data->player_y + 2;
    b[0] =   tpx + data->player_x + 2;
    if(b[0] >= x * 10 && b[0] <= (x + 1) * 10)
    {
        *ray_colesion_y =   sqrt(pow(tpx,2) + pow(tpy,2));
        data->px_y = b[0];
        data->py_y =  b[1];
        return(1);
    }
    return(0);
}

int y_detect(t_data *data,int y, int y_plus,int px,int left_begin_agrement_x_from_player, double *ray_colesion_y,double engel)
{
    int x;
   
    x = px;
    if(left_begin_agrement_x_from_player == 1)
    {
        while (data->result[y][x])
        {
            if(data->result[y][x] == '1') //wall detect posetion
            {
                if(y_detect_loop(data,y_plus,x,ray_colesion_y,engel) == 1)
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
               if(y_detect_loop(data,y_plus,x,ray_colesion_y,engel) == 1)
                    return(1);
            }
            x--;
        }
    }
    return(0);
}

int x_detect_loop(int x_plus,int y,t_data *data,double *ray_colesion_x,double engel)
{
    int a[2];
	int b[2];
    double tpx =0;
    double tpy = 0;

    tpx = ((data->player_x + 2) - (((x_plus) * 10)));
    tpy = tpx * tan(engel);
    b[1] = (data->player_y +  2) - tpy;
    a[0] = data->player_x + 2 ;
    a[1] = data->player_y + 2 ;
    b[0] = (((x_plus) * 10));
    if(b[1] >= y * 10 && b[1] <= (y + 1) * 10)
    {
        *ray_colesion_x =   sqrt(pow(tpx,2) + pow(tpy,2));
        data->px_x = b[0];
        data->py_x =  b[1];
        return(1);
    }
    return(0);
}

int x_detect(int left_begin_agrement_x_from_player_x,int px,int y,t_data *data,double *ray_colesion_x,double engel)
{
    int x;
    int x_plus;

    x = 0;
    x_plus = 0;
    double degre;
    degre = (engel / pi) * 180;
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
                if(x_detect_loop(x_plus,y,data,ray_colesion_x,engel) == 1)
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
                if(x_detect_loop(x_plus,y,data,ray_colesion_x,engel) == 1)
                    return(1);
            }
            x++;
        }
    }
     return(0);
}

double one_ray(t_data *data,double engel)
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
    double end_ray;


    degre = (engel / pi) * 180;
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
    /* ----------  y  && x  -------------- */
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
            if(y_detect(data,y,y + 1,px,left_begin_agrement_x_from_player,&ray_colesion_y,engel) == 1 ||
                 x_detect(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,engel) == 1)
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
            if(y_detect(data,y,y,px,left_begin_agrement_x_from_player,&ray_colesion_y,engel) == 1 || 
                x_detect(left_begin_agrement_x_from_player_x,px,y,data,&ray_colesion_x,engel) == 1)
                break;
            y++;
        }
    }

    a[0] = data->player_x + 2;
    a[1] = data->player_y + 2;
    if( (ray_colesion_x < ray_colesion_y && ray_colesion_x != 0 ) || ray_colesion_y == 0)
    {
        b[0] = data->px_x;
        b[1] = data->py_x ;
        end_ray = ray_colesion_x;
    }
    else
    {
        b[0] = data->px_y;
        b[1] = data->py_y ;
        end_ray = ray_colesion_y;
    }
    draw_line(data, a, b, 0Xff0000);
    return(end_ray);
}

void ray_colesion(t_data *data)
{
    double rays;
    int a[2];
	int b[2];
    int test = 0;
    double angel_move = 0;
    double point_to_break;

    angel_move = (M_PI/3) / ((data->result_with) * 50);
    rays =  data->pa;
    rays -= M_PI/6;		
	if(rays <= 0)
		rays += 2 * M_PI; 
    point_to_break = 0;	
    while(point_to_break <= M_PI/3 )
    {	
        rays += angel_move;
        if(rays > 2 * M_PI)
			rays -= 2 * M_PI;
        one_ray(data,rays);
        point_to_break += angel_move;
        test++;
    }
    one_ray(data,data->pa);
    a[0] = data->player_x + 2;
    a[1] = data->player_y + 2;
    b[0] = a[0] + cos(data->pa) * 7;
    b[1] = a[1] + sin(data->pa) * 7;
    draw_line(data, a, b, 0Xffffff);
   
}
