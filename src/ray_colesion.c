#include "../Includes/cub.h"

int y_detect(t_data *data, int y,int up_down, double *ray_colesion_y)
{
    int x;

    x = 0;
    int a[2];
	int b[2];
    double tpx =0;
    double tpy = 0;
    while (data->result[y][x])
    {
        if(data->result[y][x] == '1') //wall detect posetion
        {
           
            if (up_down == 1) 
            {
                tpy = ((data->player_y) - (((y + 1) * 50))) + 7.5;
                tpx = tan(data->pa) * tpy;
            }
            else
            {
                tpy = ((((y) * 50)) - (data->player_y)) + 7.5;
                tpx = -tan(data->pa) * tpy;
            }
            a[0] = data->player_x + 7.5;
            a[1] = data->player_y + 7.5;
            b[0] =   tpx + data->player_x;
            if (up_down == 1) 
                b[1] = (((y + 1) * 50));
            else
               b[1] = (((y) * 50));
            if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
            {
                //draw_line(data, a, b, 0Xff0000);
                *ray_colesion_y =   sqrt(pow(tpx,2) + pow(tpy,2));
                printf("ray_colesion_y = %f\n", *ray_colesion_y);
                data->px_y = b[0];
	            data->py_y =  b[1];
                return(1);
            }
        }
        x++;
    }
    return(0);
}

int x_detect(int up_down_x,int px,int y,t_data *data,double *ray_colesion_x)
{
    int x;
    int a[2];
	int b[2];
    double tpx =0;
    double tpy = 0;

     x = 0;
    if(up_down_x == 1)
    {
        x = px;
        while (data->result[y][x])
        {
            if(data->result[y][x] == '1') //wall detect posetion
            {
                tpx = ((((x) * 50)) - (data->player_x)) + 7.5;
                tpy = tpx / tan(data->pa);
                a[0] = data->player_x + 7.5;
                a[1] = data->player_y + 7.5;
                b[0] = (((x) * 50));
                b[1] = (data->player_y +  7.5) - tpy;
                if( y + 1 != '\0' && b[1] >= y * 50 && b[1] <= (y + 1) * 50)
                {
                    //draw_line(data, a, b, 11111);
                    *ray_colesion_x =   sqrt(pow(tpx,2) + pow(tpy,2));
                    printf("ray_colesion_x = %f\n", *ray_colesion_x);
                    data->px_x = b[0];
	                data->py_x =  b[1];
                    return(1);
                    break;
                }
            }
            x++;
        }
    }
    else
    {
        x = px;
        while (x >= 0)
        {
            if(data->result[y][x] == '1') //wall detect posetion
            {
                tpx = ((((x + 1) * 50)) - (data->player_x)) + 7.5;
                tpy = tpx / tan(data->pa);
                a[0] = data->player_x + 7.5;
                a[1] = data->player_y + 7.5;
                b[0] = (((x + 1) * 50));
                b[1] = (data->player_y +  7.5) - tpy;
                if(b[1] >= y * 50 && b[1] <= (y + 1) * 50)
                {
                    //draw_line(data, a, b, 11111);
                    *ray_colesion_x =   sqrt(pow(tpx,2) + pow(tpy,2));
                    printf("ray_colesion_x = %f\n", *ray_colesion_x);
                    data->px_x = b[0];
	                data->py_x =  b[1];
                    return(1);
                }
            }
            x--;
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

    double ray_colesion_y = 0;
    double ray_colesion_x = 0;
    
    printf("pa = %f\n",data->pa );
    double degre = (data->pa / pi) * 180;
    if(degre == 360)
        degre = 0;
    printf("degre = %f\n",degre);
    while(data->result[y])
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
    //   ----  y   ------
    y = py;
    if((degre >= 0 && degre < 90) || (degre <= 360 && degre >= 270))
    {
        up_down = 1;
        y--;
        while(y >= 0)
        {
            if(y_detect(data,y,up_down,&ray_colesion_y) == 1)
                break;
            y--;
        }
    }
    else
    {
        up_down = 0;
        y++;
        while(data->result[y])
        {
            if(y_detect(data,y,up_down,&ray_colesion_y) == 1)
                break;
            y++;
        }
    }
    //////// ----------- x ---------------

    if(degre >= 0 && degre < 90)
    {
        y = py;
        y--;
        up_down_x = 1;
        while(y >= 0)
        {
            if (x_detect(up_down_x,px,y,data,&ray_colesion_x) == 1)
                break; 
            y--;
        }
    }
    else if(degre <= 360 && degre > 270)
    {
        y = py;
        y--;
        while(y >= 0)
        {
            if (x_detect(up_down_x,px,y,data,&ray_colesion_x) == 1)
                break; 
            y--;
        }
    }
    else if(degre >= 90 && degre < 180)
    {
        y = py;
        y++;
        up_down_x = 1;
        while(data->result[y])
        {
            if (x_detect(up_down_x,px,y,data,&ray_colesion_x) == 1)
                break; 
            y++;
        }
    }
    else
    {
        y = py;
        y++;
        while(data->result[y])
        {
           if (x_detect(up_down_x,px,y,data,&ray_colesion_x) == 1)
                break; 
            y++;
        }
    }
    printf("## ray_colesion_x = %f\n",ray_colesion_x);
    printf("## ray_colesion_y = %f\n",ray_colesion_y);
    if( (ray_colesion_x < ray_colesion_y && ray_colesion_x != 0 ) || ray_colesion_y == 0)
    {
        a[0] = data->player_x + 7.5;
        a[1] = data->player_y + 7.5;
        b[0] = data->px_x;
        b[1] = data->py_x ;
        draw_line(data, a, b, 11111);
    }
    else
    {
        a[0] = data->player_x + 7.5;
        a[1] = data->player_y + 7.5;
        b[0] = data->px_y;
        b[1] = data->py_y ;
        draw_line(data, a, b, 0Xff0000);
    }
}