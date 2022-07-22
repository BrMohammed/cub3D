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
            tpy = ((data->player_y) - (((y + 1) * 50))) + 7.5;
            tpx = tan(data->pa) * tpy;
            a[0] = data->player_x + 7.5;
			a[1] = data->player_y + 7.5;
			b[0] =   tpx + data->player_x;
			b[1] = (((y + 1) * 50));
            draw_line(data, a, b, 0Xff0000);
            break;
        }
        y--;
    }
}