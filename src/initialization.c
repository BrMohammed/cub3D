
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
    data->speed = 2;
    data->angel_speed = 0.15707963267 / 2;
    data->is_jumping_up = 0;
    data->is_jumping_down = 0;
    data->jump_force = 40;
    data->gravity = 3;
    data->coin_res = 400;
    data->begin_game = 0;
}

void inisial_path(t_data *data)
{
    data->img_rander.mlx_img = mlx_xpm_file_to_image(data->mlx, data->NO_PATH,
    &data->map_res, &data->map_res);
    data->img_rander.addr = mlx_get_data_addr(data->img_rander.mlx_img, &data->img_rander.bpp,
    &data->img_rander.line_len, &data->img_rander.endian);

    data->point_map_path = "./assets/point.xpm";
    data->point_map = mlx_xpm_file_to_image(data->mlx, data->point_map_path,
    &data->p_w, &data->p_h);

    data->path_sprite = "./assets/YellowCoin/xpm/1.xpm";
    data->img_sprite.mlx_img = mlx_xpm_file_to_image(data->mlx, data->path_sprite,
    &data->p_w, &data->p_h);
    data->img_sprite.addr = mlx_get_data_addr(data->img_sprite.mlx_img, &data->img_sprite.bpp,
    &data->img_sprite.line_len, &data->img_sprite.endian);
}

void destroy(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    mlx_destroy_image(data->mlx,data->point_map);

}

void respone2(t_data *data)
{
    data->point_map = mlx_xpm_file_to_image(data->mlx, data->point_map_path,
    &data->p_w, &data->p_h);
}