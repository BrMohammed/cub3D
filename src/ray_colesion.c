#include "../Includes/cub.h"


int y_detect_loop(t_data *data, int y_plus,int x, double *ray_colesion_y)
{
    int a[2];
	int b[2];
    double tpx = 0;
    double tpy = 0;
    tpy = ((data->player_y + 7.5) - (((y_plus) * 50)));
    tpx = tpy / -tan(data->pa);
    b[1] = (((y_plus) * 50));
    a[0] = data->player_x + 7.5;
    a[1] = data->player_y + 7.5;
    b[0] =   tpx + data->player_x + 7.5;
    if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
    {
        //draw_line(data, a, b, 0Xff0000);
        *ray_colesion_y =   sqrt(pow(tpx,2) + pow(tpy,2));
        data->px_y = b[0];
        data->py_y =  b[1];
        return(1);
    }
    return(0);
}

int y_detect(t_data *data,int y, int y_plus,int px,int up_down, double *ray_colesion_y)
{
    int x;
   
    x = px;
    if(up_down == 1)
    {
        while (data->result[y][x])
        {
            if(data->result[y][x] == '1') //wall detect posetion
            {
                if(y_detect_loop(data,y_plus,x,ray_colesion_y) == 1)
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
               if(y_detect_loop(data,y_plus,x,ray_colesion_y) == 1)
                    return(1);
            }
            x--;
        }
    }
    return(0);
}

int x_detect_loop(int x_plus,int y,t_data *data,double *ray_colesion_x)
{
    int a[2];
	int b[2];
    double tpx =0;
    double tpy = 0;

    tpx = ((data->player_x + 7.5) - (((x_plus) * 50)));
    tpy = tpx * tan(data->pa);
    b[1] = (data->player_y +  7.5) - tpy;
    a[0] = data->player_x + 7.5 ;
    a[1] = data->player_y + 7.5 ;
    b[0] = (((x_plus) * 50));
    if(b[1] >= y * 50 && b[1] <= (y + 1) * 50)
    {
        //draw_line(data, a, b, 1111);
        // if(data->pa == 0)
        //     *ray_colesion_x = cos(data->pa) * tpx - 7.5;
        // else
        //     *ray_colesion_x = tpy / sin(data->pa) - 7.5;
        *ray_colesion_x =   sqrt(pow(tpx,2) + pow(tpy,2));
        //printf("ray_colesion_x = %f\n", *ray_colesion_x);
        data->px_x = b[0];
        data->py_x =  b[1];
        return(1);
    }
    return(0);
}

int x_detect(int up_down_x,int px,int y,t_data *data,double *ray_colesion_x)
{
    int x;
    int x_plus;

    x = 0;
    x_plus = 0;
    double degre;
    degre = (data->pa / pi) * 180;
    if(up_down_x == 1)
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
                if(x_detect_loop(x_plus,y,data,ray_colesion_x) == 1)
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
                if(x_detect_loop(x_plus,y,data,ray_colesion_x) == 1)
                    return(1);
            }
            x++;
        }
    }
     return(0);
}

void ray_colesion(t_data *data)
{
    int y = 0;
    int x = 0;
    int px = 0;
    int py = 0;
    int up_down = 0;
    int up_down_x = 0;
    int a[2];
	int b[2];
    double degre;
    double ray_colesion_y;
    double ray_colesion_x;


    degre = (data->pa / pi) * 180;
    ray_colesion_y = 0;
    ray_colesion_x = 0;
    while(data->result[y]) //know position of player in map
    {
        if(data->player_y + 7.5 >= y * 50 && data->player_y + 7.5 <= (y + 1) * 50) // player posetion y
            py = y;
        x = 0;
        while(data->result[y][x])
        {
            if(data->player_x + 7.5 >= x * 50 && data->player_x + 7.5 <= (x + 1) * 50) //player posetion x
                px = x;
            x++;
        }
        y++;
    }
    //////// ----------  y  --------------
    if((degre <= 360 && degre > 180))
    {
        y = py;
        if(degre <= 360 && degre > 270)
            up_down = 1;
        if(degre <= 270 && degre > 180)
            up_down = 0;
        while(y >= 0)
        {
            if(y_detect(data,y,y + 1,px,up_down,&ray_colesion_y) == 1)
                break;
            y--;
        }
     }
    else
    {
        y = py;
        if(degre <= 180 && degre > 90)
            up_down = 0;
        if(degre <= 90 && degre > 0)
            up_down = 1;
        while(data->result[y])
        {
            if(y_detect(data,y,y,px,up_down,&ray_colesion_y) == 1)
                break;
            y++;
        }
    }
    //////// ----------- x ---------------
    if(degre >= 0 && degre <= 180)
    {
        y = py;
        if(degre >= 0 && degre < 90)
            up_down_x = 0;
        else
            up_down_x = 1;
        while(data->result[y])
        {
            if (x_detect(up_down_x,px,y,data,&ray_colesion_x) == 1)
                break; 
            y++;
        }
    }
    else if(degre <= 360 && degre > 180)
    {
        
        y = py;
        if(degre <= 270 && degre > 180)
            up_down_x = 1;
        else
            up_down_x = 0;
        while(y >= 0)
        {
            if (x_detect(up_down_x,px,y,data,&ray_colesion_x) == 1)
                break; 
            y--;
        }
    }
    a[0] = data->player_x + 7.5;
    a[1] = data->player_y + 7.5;
    if( (ray_colesion_x < ray_colesion_y && ray_colesion_x != 0 ) || ray_colesion_y == 0)
    {
        b[0] = data->px_x;
        b[1] = data->py_x ;
        draw_line(data, a, b, 11111);
    }
    else
    {
        b[0] = data->px_y;
        b[1] = data->py_y ;
        draw_line(data, a, b, 0Xff0000);
    }
    b[0] = a[0] + cos(data->pa) * 32;
    b[1] = a[1] + sin(data->pa) * 32;
    draw_line(data, a, b, 0Xffffff);
}