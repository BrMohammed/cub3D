#include "../Includes/cub.h"

int y_detect(t_data *data, int y,int up_down)
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
                draw_line(data, a, b, 0Xff0000);
                return(1);
                break;
            }
        }
        x++;
    }
    return(0);
}


void ray_colesion(t_data *data)
{
    int y = 0;
    int x = 0;
    int px = 0;
    int py = 0;
   // int up_down = 0;

    int a[2];
	int b[2];
    double tpx =0;
    double tpy = 0;
    
    printf("pa = %f\n",data->pa );
    double degre = (data->pa / pi) * 180;
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
    /*//   ----  y   ------
    y = py;
    if((degre >= 0 && degre < 90) || (degre <= 360 && degre > 270))
    {
        up_down = 1;
        y--;
        while(y >= 0)
        {
            if(y_detect(data,y,up_down) == 1)
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
            if(y_detect(data,y,up_down) == 1)
                break;
            y++;
        }
    }
    */




    // if((degre >= 0 && degre < 90) || (degre <= 360 && degre > 270))
    // {
        y = py;
        while(y >= 0)
        {
            x = px;
            while (data->result[y][x])
            {
                if(data->result[y][x] == '1') //wall detect posetion
                {
                    tpx = ((((x) * 50)) - (data->player_x) ) + 7.5;
                    tpy = tpx / tan(data->pa);
                    a[0] = data->player_x + 7.5;
                    a[1] = data->player_y + 7.5;
                    b[0] = (((x ) * 50));
                    b[1] = data->player_y - tpy;
                    if(b[1] >= y * 50 && b[1] <= (y + 1) * 50)
                    {
                        draw_line(data, a, b, 0Xff0000);
                        printf("y * 50 = %d , y + 1 * 50 = %d\n",y * 50,(y + 1) * 50);
                        printf("x = %d\n px = %d \n",x,px);
                        printf("b[1]y = %d \n b[0]x = %d\n y = %f \n",b[1],b[x],tpy);
                        printf("tpx = %f\n",tpx);
                        printf("=====================\n\n");
                        break;
                    }
                }
                x++;
            }
            if(b[1] >= y * 50 && b[1] <= (y + 1) * 50)
            {
                draw_line(data, a, b, 0Xff0000);
                break;
            }
                
            y--;
        }
    // }
    // else
    // {
    //     y = py;
    //     y++;
    //     while(data->result[y])
    //     {
    //         x = 0;
    //         while (data->result[y][x])
    //         {
    //             if(data->result[y][x] == '1') //wall detect posetion
    //             {
    //                 tpy = ((((y) * 50)) - (data->player_y)) + 7.5;
    //                 tpx = -tan(data->pa) * tpy;
    //                 a[0] = data->player_x + 7.5;
    //                 a[1] = data->player_y + 7.5;
    //                 b[0] =   tpx + data->player_x;
    //                 b[1] = (((y) * 50));
    //                 if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
    //                 {
    //                     draw_line(data, a, b, 0Xff0000);
    //                     printf("x * 50 = %d , x + 1 * 50 = %d\n",x * 50,(x + 1) * 50);
    //                     printf("x = %d\n px = %d \n",x,px);
    //                     printf("b[0]x = %d\n y = %f \n",b[0],tpy);
    //                     printf("tpx = %f\n",tpx);
    //                     break;
    //                 }
    //             }
    //             x++;
    //         }
    //         if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
    //             break;
    //         y++;
    //     }
    // }
}