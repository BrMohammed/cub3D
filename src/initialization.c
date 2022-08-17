
#include "../Includes/cub.h"

void initial_var(t_data *data)
{
    data->lfo9 = 10;
    data->lte7t = 10;
    data->demension_hight = 1000;
    data->demintion_with = 1000;
    if((data->demension_hight / data->result_hight) < (data->demintion_with / data->result_with) )
        data->mini_map_res = (data->demension_hight / data->result_hight) / 3;
    else
    data->mini_map_res = (data->demintion_with / data->result_with) / 3;
    data->map_res = 1000;
    data->player_mini_res = data->mini_map_res / 2;
    data->speed = 3;
    data->angel_speed = 0.15707963267 ;
    data->is_jumping_up = 0;
    data->is_jumping_down = 0;
    data->jump_force = 40;
    data->gravity = 3;
    data->coin_res = 400;
    data->begin_game = 0;
    data->coin_count = 0;
}

void inisial_path(t_data *data)
{
    data->img_rander.mlx_img = mlx_xpm_file_to_image(data->mlx, data->NO_PATH,
    &data->map_res, &data->map_res);
    data->img_rander.addr = mlx_get_data_addr(data->img_rander.mlx_img, &data->img_rander.bpp,
    &data->img_rander.line_len, &data->img_rander.endian);

    data->point_map_path = "./assets/arow5.xpm";
    data->img_mini_player.mlx_img  = mlx_xpm_file_to_image(data->mlx, data->point_map_path,
    &data->p_w, &data->p_h);
     data->img_mini_player.addr = mlx_get_data_addr(data->img_mini_player.mlx_img, &data->img_mini_player.bpp,
    &data->img_mini_player.line_len, &data->img_mini_player.endian);

    data->path_sprite = "./assets/YellowCoin/xpm/1.xpm";
    data->img_sprite.mlx_img = mlx_xpm_file_to_image(data->mlx, data->path_sprite,
    &data->p_w, &data->p_h);
    data->img_sprite.addr = mlx_get_data_addr(data->img_sprite.mlx_img, &data->img_sprite.bpp,
    &data->img_sprite.line_len, &data->img_sprite.endian);
    data->number.number0_path = "./assets/0.xpm";
	data->number.number1_path = "./assets/1.xpm";
	data->number.number2_path = "./assets/2.xpm";
	data->number.number3_path = "./assets/3.xpm";
	data->number.number4_path = "./assets/4.xpm";
	data->number.number5_path = "./assets/5.xpm";
	data->number.number6_path = "./assets/6.xpm";
	data->number.number7_path = "./assets/7.xpm";
	data->number.number8_path = "./assets/8.xpm";
	data->number.number9_path = "./assets/9.xpm";
    data->number.slash_path = "./assets/slash.xpm";

    number_b(data);
}
void	number_b(t_data *data)
{
	data->number.number0 = mlx_xpm_file_to_image(data->mlx,
			data->number.number0_path, &data->p_h, &data->img_height);
	data->number.number1 = mlx_xpm_file_to_image(data->mlx,
			data->number.number1_path, &data->img_width, &data->img_height);
	data->number.number2 = mlx_xpm_file_to_image(data->mlx,
			data->number.number2_path, &data->img_width, &data->img_height);
	data->number.number3 = mlx_xpm_file_to_image(data->mlx,
			data->number.number3_path, &data->img_width, &data->img_height);
	data->number.number4 = mlx_xpm_file_to_image(data->mlx,
			data->number.number4_path, &data->img_width, &data->img_height);
	data->number.number5 = mlx_xpm_file_to_image(data->mlx,
			data->number.number5_path, &data->img_width, &data->img_height);
	data->number.number6 = mlx_xpm_file_to_image(data->mlx,
			data->number.number6_path, &data->img_width, &data->img_height);
	data->number.number7 = mlx_xpm_file_to_image(data->mlx,
			data->number.number7_path, &data->img_width, &data->img_height);
	data->number.number8 = mlx_xpm_file_to_image(data->mlx,
			data->number.number8_path, &data->img_width, &data->img_height);
	data->number.number9 = mlx_xpm_file_to_image(data->mlx,
			data->number.number9_path, &data->img_width, &data->img_height);
    data->number.slash = mlx_xpm_file_to_image(data->mlx,
			data->number.slash_path, &data->img_width, &data->img_height);
}

void destroy(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
   // mlx_destroy_image(data->mlx,data->point_map);

}

// void respone2(t_data *data)
// {
//     // data->point_map = mlx_xpm_file_to_image(data->mlx, data->point_map_path,
//     // &data->p_w, &data->p_h);
// }