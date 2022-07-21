#include "../Includes/cub.h"

void ray_colesion(t_data *data)
{
    int y = 0;
    int x = 0;
    int px;
    int py;
    int tpx;
    int tpy;
    double temp_length_y;
    int t_y;
    while(data->result[y])
    {
        if(data->player_y + 7.5 >= y * 50 && data->player_y + 7.5 <= (y + 1) * 50) // player posetion y
            py = y;
        while(data->result[y][x])
        {
            if(data->player_x + 7.5 >= x * 50 && data->player_x + 7.5 <= (x + 1) * 50) //player posetion x
                px = x;
            x++;
        }
        y++;
    }
    x = 0;
    y = py;
    while(y >=0)
    {
        if(data->result[y][px] == '1') //wall detect posetion
        {
            //sqrt(((py - y) * 50) + 7.5)
            data->lenght_of_ray = sqrt(((data->player_y) - (((y + 1) * 50))) + 7.5);
            tpy = (data->player_y + 7.5) + data->pdy * data->lenght_of_ray;
            tpx = (data->player_x + 7.5) + data->pdx * data->lenght_of_ray;
            // printf("player_y  = %f\n", data->player_y);
            // printf("tpy  = %f\n", tpy + data->pdy);
            // printf("tpx  = %d\n", tpx);
            // printf("wall  = %d\n", (y + 1) * 50);
            if(tpy  >  (y + 1) * 50)
            {
                x = 0;
                t_y = 0;
                while(data->result[t_y])
                {
                    if(	tpy >= t_y * 50 && tpy <= (t_y + 1) * 50) // end point posetion y
                        py = y;
                    while(data->result[t_y][x])
                    {
                        if(tpx >= x * 50 && tpx <= (x + 1) * 50) //end  point posetion x
                            px = x;
                        x++;
                    }
                    t_y++;
                }
                t_y = py;
                x = 0;
                while(t_y >=0)
                {
                    if(data->result[t_y][px] == '1') //wall detect posetion
                    {
                        //sqrt(((py - y) * 50) + 7.5)
                        temp_length_y = sqrt(abs((tpy) - (((t_y + 1) * 50))));
                        // printf("tpy  = %d\n", tpy);
                        // printf("t_y  = %d\n", (t_y + 1) * 50);
                         printf("temp_length_y  = %f\n", temp_length_y);
                        // printf("x =  %f\n", (tan(cos(data->pa)) * temp_length_y));
                        // printf("z =  %f\n",  sqrt(pow((tan(sin(data->pa)) * temp_length_y),(double)2) + pow(temp_length_y,(double)2)));
                        // printf("lenght_of_ray1  = %f\n", data->lenght_of_ray);
                        data->lenght_of_ray += sqrt(fabs(sqrt(fabs(pow((tan(cos(data->pa)) * temp_length_y),(double)2) + pow(temp_length_y,(double)2))))) ;
                        //printf("lenght_of_ray2  = %f\n", data->lenght_of_ray);
                        printf("================================\n\n");
                        break;
                    }
                    t_y--;
                }
           }
            break;
        }
        y--;
    }
}