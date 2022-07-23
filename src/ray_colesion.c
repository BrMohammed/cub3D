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
    if((degre >= 0 && degre < 90) || (degre <= 360 && degre > 270))
    {
        y = py;
        y--;
        while(y >= 0)
        {
            x = 0;
            while (data->result[y][x])
            {
                if(data->result[y][x] == '1') //wall detect posetion
                {
                    tpy = ((data->player_y) - (((y + 1) * 50))) + 7.5;
                    tpx = tan(data->pa) * tpy;
                    a[0] = data->player_x + 7.5;
                    a[1] = data->player_y + 7.5;
                    b[0] =   tpx + data->player_x;
                    b[1] = (((y + 1) * 50));
                    if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
                    {
                        draw_line(data, a, b, 0Xff0000);
                        printf("x * 50 = %d , x + 1 * 50 = %d\n",x * 50,(x + 1) * 50);
                        printf("x = %d\n px = %d \n",x,px);
                        printf("b[0]x = %d\n y = %f \n",b[0],tpy);
                        printf("tpx = %f\n",tpx);
                        break;
                    }
                }
                x++;
            }
            if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
                break;
            y--;
        }
    }
    else
    {
        y = py;
        y++;
        while(data->result[y])
        {
            x = 0;
            while (data->result[y][x])
            {
                if(data->result[y][x] == '1') //wall detect posetion
                {
                    tpy = ((((y) * 50)) - (data->player_y)) + 7.5;
                    tpx = -tan(data->pa) * tpy;
                    a[0] = data->player_x + 7.5;
                    a[1] = data->player_y + 7.5;
                    b[0] =   tpx + data->player_x;
                    b[1] = (((y) * 50));
                    if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
                    {
                        draw_line(data, a, b, 0Xff0000);
                        printf("x * 50 = %d , x + 1 * 50 = %d\n",x * 50,(x + 1) * 50);
                        printf("x = %d\n px = %d \n",x,px);
                        printf("b[0]x = %d\n y = %f \n",b[0],tpy);
                        printf("tpx = %f\n",tpx);
                        break;
                    }
                }
                x++;
            }
            if(b[0] >= x * 50 && b[0] <= (x + 1) * 50)
                break;
            y++;
        }
    }
    
    // }
    // if((data->pa >= (3*pi)/4 && data->pa <= pi) || (data->pa >= 0 && data->pa <= pi / 4)  )
    // {
    //     printf("hi\n");
    // }
    printf("===============\n\n");
    
}