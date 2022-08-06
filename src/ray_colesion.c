#include "../Includes/cub.h"

int y_detect_loop(t_data *data, int y_plus,int x, double *ray_colesion_y,double angel)
{
	double b[2];
    double tpx = 0;
    double tpy = 0;

   // double  m;
    tpy =  ((data->player_y + (data->player_mini_res / 2)) - (((y_plus ) * data->mini_map_res)));
    tpx =  (tpy / -tan(angel));
    b[1] = (((y_plus) * data->mini_map_res));
    b[0] = (tpx + data->player_x + (data->player_mini_res / 2));
    if(b[0] >= x * data->mini_map_res && b[0] < (x + 1) * data->mini_map_res)
    { 
        *ray_colesion_y =   sqrt((tpx*tpx) +(tpy*tpy));
        b[0] = (((((b[0] - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2));
        b[1] = ((((((x * data->mini_map_res) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2));
        data->offcet_x1 =  (abs((((int)b[0]) - (int)b[1] )) % data->map_res);
        data->ray_offset_in_y = 0;
        return(1);
    }
    return(0);
}

int x_detect_loop(int x_plus,int y,t_data *data,double *ray_colesion_x,double angel)
{
	double b[2];
    double tpx =0;
    double tpy = 0;
    tpx = ((data->player_x + (data->player_mini_res / 2)) - (((x_plus) * data->mini_map_res)));
    tpy = (tpx * tan(angel));
    b[1] = ((data->player_y +  (data->player_mini_res / 2)) - tpy);
    b[0] = (((x_plus) * data->mini_map_res));
    if(b[1] >= y * data->mini_map_res && b[1] < (y + 1) * data->mini_map_res)
    {
        *ray_colesion_x =  sqrt((tpx*tpx) +(tpy*tpy));
        b[0] = (((((((y) * data->mini_map_res) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2));
        b[1] = (((((b[1] - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2));
        data->offcet_x =  (abs((((int)b[1]) - (int)b[0] )) % data->map_res);
        data->ray_offset_in_y = 1;
        return(1);
    }
    return(0);
}

int y_detect(t_data *data,t_oneray *oneray_var, int y_plus,double angel)
{
    int x;
   
    x = oneray_var->px;
    if(oneray_var->left_begin_agrement_x_from_player == 1)
    {
        while (data->result[oneray_var->y][x])
        {
            if(data->result[oneray_var->y][x] == '1') //wall detect posetion
            {
                if(y_detect_loop(data,y_plus,x,&oneray_var->ray_colesion_y,angel) == 1)
                    return(1);
            }
            x++;
        }
    }
    else
    {
        while (x >= 0)
        {
            if(data->result[oneray_var->y][x] == '1') //wall detect posetion
            {
               if(y_detect_loop(data,y_plus,x,&oneray_var->ray_colesion_y,angel) == 1)
                    return(1);
            }
            x--;
        }
    }
    return(0);
}


int x_detect(t_oneray *oneray_var,t_data *data,double angel)
{
    int x;
    int x_plus;

    x = 0;
    x_plus = 0;
    double degre;
    degre = (angel / pi) * 180;
    if(oneray_var->left_begin_agrement_x_from_player_x == 1)
    {
        x = oneray_var->px;
        while (x >= 0)
        {
            if((degre >= 270 && degre <= 90 ))
               x_plus = x;
            else
                x_plus = x + 1;
            
            if(data->result[oneray_var->y][x] == '1') //wall detect posetion
            {
                if(x_detect_loop(x_plus,oneray_var->y,data,&oneray_var->ray_colesion_x,angel) == 1)
                    return(1);
            }
            x--;
        }
    }
    else
    {
        x = oneray_var->px;
        x++;
        while (data->result[oneray_var->y][x])
        {
            if((degre >= 270 && degre <= 90 ))
               x_plus = x + 1;
            else
                x_plus = x;
            if(data->result[oneray_var->y][x] == '1') //wall detect posetion
            {
                if(x_detect_loop(x_plus,oneray_var->y,data,&oneray_var->ray_colesion_x,angel) == 1)
                    return(1);
            }
            x++;
        }
    }
     return(0);
}

double one_ray(t_data *data,double angel)
{
    t_oneray oneray_var;

    oneray_var.y = 0;
    oneray_var.x = 0;
    oneray_var.ray_colesion_y = 0;
    oneray_var.ray_colesion_x = 0;
    oneray_var.degre = (angel / pi) * 180;
    while(data->result[ oneray_var.y]) //know position of player in map
    {
        if(data->player_y + (data->player_mini_res / 2) >=  oneray_var.y * data->mini_map_res && data->player_y + (data->player_mini_res / 2) <= ( oneray_var.y + 1) * data->mini_map_res) // player posetion y
             oneray_var.py =  oneray_var.y;
         oneray_var.x = 0;
        while(data->result[ oneray_var.y][ oneray_var.x])
        {
            if(data->player_x + (data->player_mini_res / 2) >=  oneray_var.x * data->mini_map_res && data->player_x + (data->player_mini_res / 2) <= ( oneray_var.x + 1) * data->mini_map_res) //player posetion x
                 oneray_var.px =  oneray_var.x;
             oneray_var.x++;
        }
         oneray_var.y++;
    }
    if(( oneray_var.degre <= 360 &&  oneray_var.degre > 180))
    {
         oneray_var.y =  oneray_var.py;
        if( oneray_var.degre <= 360 &&  oneray_var.degre > 270)
        {
             oneray_var.left_begin_agrement_x_from_player = 1;
             oneray_var.left_begin_agrement_x_from_player_x = 0;
        }
        if( oneray_var.degre <= 270 &&  oneray_var.degre > 180)
        {
            oneray_var.left_begin_agrement_x_from_player = 0;
            oneray_var.left_begin_agrement_x_from_player_x = 1;
        }
            
        while( oneray_var.y >= 0)
        {
            if((y_detect(data, &oneray_var, oneray_var.y + 1,angel) == 1 ||
                 x_detect(&oneray_var,data,angel) == 1) )
                break;
             oneray_var.y--;
        }
     }
    else
    {
         oneray_var.y =  oneray_var.py;
        if( oneray_var.degre <= 180 &&  oneray_var.degre > 90)
        {
             oneray_var.left_begin_agrement_x_from_player = 0;
             oneray_var.left_begin_agrement_x_from_player_x = 1;
        }
            
        if( oneray_var.degre <= 90 &&  oneray_var.degre > 0)
        {
             oneray_var.left_begin_agrement_x_from_player = 1;
             oneray_var.left_begin_agrement_x_from_player_x = 0;
        } 
        while(data->result[ oneray_var.y])
        {
            if(y_detect(data, &oneray_var, oneray_var.y,angel) == 1 ||
                x_detect(&oneray_var,data,angel) == 1)
                break;
             oneray_var.y++;
        }
    }

    
    if (( oneray_var.ray_colesion_y <=  oneray_var.ray_colesion_x &&  oneray_var.ray_colesion_y != 0 ) ||  oneray_var.ray_colesion_x == 0)
    {
        oneray_var.distance =  oneray_var.ray_colesion_y;
        if(oneray_var.degre > 180 && oneray_var.degre <= 360)
            data->color= 27391; //blue for NO
        else
            data->color= 4652872; //gren for SO
    }
    else if( ( oneray_var.ray_colesion_x <=  oneray_var.ray_colesion_y &&  oneray_var.ray_colesion_x != 0 ) ||  oneray_var.ray_colesion_y == 0)
    {
        oneray_var.distance =  oneray_var.ray_colesion_x;
        if(oneray_var.degre >= 270  ||  oneray_var.degre <= 90)
            data->color= 16777062; //yelow for EA
         else
            data->color= 16711716; //reds for WE
    }
    return( oneray_var.distance);
}

void ray_colesion(t_data *data)
{
    t_raycolesion rc_var;
    double betwinenngels;
    double wall_scall;

    rc_var.angel_move = (M_PI/3) / (WIN_W);
    rc_var.point_to_break = 0;	
    rc_var.ray_count = 0;
    rc_var.rays =  data->pa;
    rc_var.rays -= M_PI/6;
	if(rc_var.rays < 0)
		rc_var.rays += 2 * M_PI;
    while(rc_var.ray_count < WIN_W)
    {
        rc_var.rays += rc_var.angel_move;
        if(rc_var.rays > 2 * M_PI)
			rc_var.rays -= 2 * M_PI;
        rc_var.distance = one_ray(data,rc_var.rays);
        betwinenngels = data->pa - rc_var.rays;
        if(betwinenngels < 0 )
            betwinenngels += 2*M_PI;
        if(betwinenngels > 2*M_PI)
            betwinenngels -= 2*M_PI;
        rc_var.distance = ((((((rc_var.distance * cos(betwinenngels)) - (data->player_mini_res / 2)) / data->mini_map_res)) * data->map_res) + (data->mini_map_res / 2)) ;
        rc_var.distanceprojplan = ((WIN_W / 2) / tan((M_PI/6)));
        rc_var.wallHeight = (((data->map_res ) / ( rc_var.distance)) * rc_var.distanceprojplan);
        //rc_var.wallHeight = (WIN_H /2) - rc_var.distance;
        //sma
        rc_var.begin[0] =  rc_var.ray_count;
        rc_var.begin[1] = 0;
        rc_var.end[0] =  rc_var.ray_count;
        rc_var.end[1] = (WIN_H  / 2) - ( (rc_var.wallHeight /2) - data->lfo9);
        if( rc_var.distance > 0)
            draw_line(data, rc_var.begin, rc_var.end, 39679);
        //l2ard
        rc_var.begin[0] =  rc_var.ray_count;
        rc_var.begin[1] = (WIN_H  / 2) + ( (rc_var.wallHeight/2) - data->lte7t);
        rc_var.end[0] =  rc_var.ray_count;
        rc_var.end[1] = WIN_H ;
        if(rc_var.distance > 0)
            draw_line(data, rc_var.begin, rc_var.end, 16711935);
        
        //WALL
        rc_var.begin[0] =  rc_var.ray_count;
        rc_var.begin[1] = (WIN_H / 2) - ( (rc_var.wallHeight / 2) - data->lfo9);
        rc_var.end[0] =  rc_var.ray_count;
        rc_var.end[1] = (WIN_H / 2) + ( (rc_var.wallHeight / 2) - data->lte7t);
        if( rc_var.distance > 0)
        {
            wall_scall = (rc_var.wallHeight) / data->map_res;
             
            if(data->ray_offset_in_y == 0)
                draw_linev2(data, rc_var.begin, rc_var.end,floor(data->offcet_x1),wall_scall);
            else
                draw_linev2(data, rc_var.begin, rc_var.end,floor(data->offcet_x ),wall_scall);
        } 
        
         rc_var.ray_count++;
    }
    ray_colesion_for_sprite(data);
}