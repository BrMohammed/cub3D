#include "../Includes/cub.h"

void ray_colesion(t_data *data)
{
    int y = 0;
    int x = 0;
    int px = 0;
    int py = 0;
    double tpx =0;
    double tpy = 0;
    int a[2];
	int b[2];
    // double temp_length_y = 0;
    // double temp_length_x = 0;
    // int t_y = 0;
    // double lenght_of_ray_temp;
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
    x = 0;
    y = py;
    while(y >= 0)
    {
        if(data->result[y][px] == '1') //wall detect posetion
        {
            //sqrt(((py - y) * 50) + 7.5)
            // data->lenght_of_ray = sqrt(((data->player_y) - (((y + 1) * 50))) + 7.5);
            tpy = ((data->player_y) - (((y + 1) * 50))) + 7.5;
            tpx = tan(data->pa) * tpy;
            // printf("tpx = %f\n",tpx);
            // printf("tpy = %f\n",tpy);
            a[0] = data->player_x + 7.5;
			a[1] = data->player_y + 7.5;
			b[0] =   tpx + data->player_x;
			b[1] = (((y + 1) * 50));
            draw_line(data, a, b, 0Xff0000);
            break;
        }
        y--;
    }
    y = py;
    while(y >=0)
    {
        while(data->result[y][x])
        {
            if(data->result[y][x] == '1' && b[0] >= x * 50 && b[0] + 7.5 <= (x + 1) * 50) //wall detect posetion
            {
                //sqrt(((py - y) * 50) + 7.5)
                data->lenght_of_ray = sqrt(((data->player_y) - (((y + 1) * 50))) + 7.5);
                tpy = ((data->player_y) - (((y + 1) * 50))) + 7.5;
                tpx = tan(data->pa) * tpy;
                // printf("tpx = %f\n",tpx);
                // printf("tpy = %f\n",tpy);
                a[0] = data->player_x + 7.5;
                a[1] = data->player_y + 7.5;
                b[0] =   tpx + data->player_x;
                b[1] = (((y + 1) * 50));
                draw_line(data, a, b, 0Xff0000);
                break;
            }
            x++;
        }
        y--;
    }
}