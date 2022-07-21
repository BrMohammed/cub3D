#include "../Includes/cub.h"

void ray_colesion(t_data *data)
{
    int y = 0;
    int x = 0;
    int px;
    int py;
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
            break;
        }
        y--;
    }
}