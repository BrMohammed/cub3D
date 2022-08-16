#include "../Includes/cub.h"

void	destroy_and_refresh(t_data *data)
{
	//destroy(data);
	respone2(data);
	respone_obj(data);
}

void	move(t_data *data, int y, int x)
{
	data->player_x += x;
	data->player_y += y ;
	data->player_y_for_3d += y;
	data->player_x_for_3d += x;
	//move_rotated(data);
}
void	move_rotated(t_data *data)
{
	int begin[2];
	int end[2];
	destroy_and_refresh(data);
	begin[0] =  (data->player_x) ;
	begin[1] = (data->player_y + (data->player_mini_res));
	end[0] = data->player_x ;
	end[1]= data->player_y ;
	draw_linev4_for_static_imgs(data, begin,end,data->player_mini_res,data->img_mini_player.addr,data->img_mini_player.line_len);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	//mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_mini_player.mlx_img, data->player_x - (data->player_mini_res / 1.7),  data->player_y - (data->player_mini_res / 1.7));
}