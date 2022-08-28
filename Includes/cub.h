/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:09:11 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 16:28:48 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include "../src/libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdbool.h>

/*# define ON_KEYUP_DERECTION key_up[0]
# define ON_KEYUP_CAMERA key_up[1]
# define ON_KEYDOWN_DERECTION key_down[0] 
# define ON_KEYDOWN_CAMERA key_down[1] 
# define KEY_LEFT key_select[0]
# define KEY_WRIGHT key_select[1]
# define KEY_W key_select[2]
# define KEY_S key_select[3]
# define KEY_A key_select[4]
# define KEY_D key_select[5]
# define KEY_UP key_select[6]
# define KEY_DOWN key_select[7]
# define KEY_SPACE key_select[8]
# define KEY_ENTER key_select[9]
# define KEY_M key_select[10]
# define WIN_W data->demintion_with
# define WIN_H data->demension_hight*/

typedef struct s_int_point
{
	int	x;
	int	y;
}	t_int_point;

typedef struct s_loop_for_sprite
{
	double	b[2];
	double	tpx ;
	double	tpy;
	int		i;
	double	angel;
}t_loop_for_sprite;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_movement
{
	char		*path_begin;
	char		*path_end;
	int			i1;
}t_movement;

typedef struct s_get_pixel
{
	char	*addr;
	int		line_len;
	int		x;
	int		y;
	int		demention;
}t_get_pixel;

typedef struct s_draw_linev3_var
{
	double	delta[2];
	int		pixels;
	double	pixel[2];
	int		x;
	double	temp_x;
	int		pixel_color;
	int		y;
	double	temp_y;
}t_draw_linev3_var;

typedef struct s_draw_linev3
{
	int		*begin;
	int		*end;
	double	wall_scall;
	double	*tabl_of_distences;
	double	distence;
}t_draw_linev3;

typedef struct s_draw_linev2
{
	int		*begin;
	int		*end;
	int		x;
	int		y;
	double	wall_scall;
	char	*addr;
	int		line_len;
}t_draw_linev2;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_menu
{
	void	*start;
	char	*start_path;
	char	*start_hover_path;

	void	*quit;
	char	*quit_path;
	char	*quit_hover_path;
	int		hover_quit;
	int		hover_start;

	void	*game_over;
	char	*game_over_path;
	char	*game_over_path_hover;
}t_menu;

typedef struct s_number
{
	void	*number0;
	char	*number0_path;

	void	*number1;
	char	*number1_path;

	void	*number2;
	char	*number2_path;

	void	*number3;
	char	*number3_path;

	void	*number4;
	char	*number4_path;

	void	*number5;
	char	*number5_path;

	void	*number6;
	char	*number6_path;

	void	*number7;
	char	*number7_path;

	void	*number8;
	char	*number8_path;

	void	*number9;
	char	*number9_path;

	void	*slash;
	char	*slash_path;

	void	*logo;
	char	*logo_path;

}	t_number;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	t_number	number;
	t_menu		menu;
	void		*mlx;
	void		*mlx_win;

	t_img		img;
	t_img		img_rander;
	t_img		img_rander_derection;
	t_img		img_sprite;
	t_img		img_mini_player;
	t_img		door;
	t_img		no_tex;
	t_img		so_tex;
	t_img		we_tex;
	t_img		ea_tex;
	int			cur_img;
	char		*no_tex_path;
	char		*so_tex_path;
	char		*we_tex_path;
	char		*ea_tex_path;
	void		*no;
	void		*we;
	void		*so;
	void		*ea;
	int			floor_color;
	int			ceilling_color;

	char		*point_map_path;
	void		*point_map;

	char		**result;

	double		player_y;
	double		player_x;

	double		pdx;
	double		pdy;
	double		pa;

	int			result_hight;
	int			result_with;

	int			key_up[2];
	int			key_down[2];
	int			key_select[11];
	int			ray_count;
	int			color;
	int			demension_hight;
	int			demintion_with;
	double		box_high;
	double		box_with;
	int			mini_map_res;
	int			map_res;
	int			coin_res;
	double		player_mini_res;
	int			offcet_x;
	int			offcet_y;
	int			offcet_x1;
	int			offcet_y1;
	int			ray_offset_in_y;

	double		speed;
	double		angel_speed;
	double		is_jumping_up;
	double		is_jumping_down;
	double		jump_force;
	double		gravity;
	double		lfo9;
	double		lte7t;
	int			p_h;
	int			p_w;
	int			py;
	int			px;

	int			one_of;
	int			sprite_x;
	int			sprite_y;
	int			*pos_of_sprite_x;
	int			*pos_of_sprite_y;

	char		*path_sprite;
	void		*sprite_buf;
	int			counter_of_sprites;
	int			begin_game;
	int			**table_of_spritesy;
	int			**table_of_spritesx;
	int			coin_count;
	int			img_width;
	int			img_height;
	char		**back_up;
	double		colutsion;
	int			color_increment;
	int			time_up;
	int			time_move;
	int			sound_loop;

	int			door_open;
	int			door_close;
	bool		show_mouse;
	bool		is_close_to_door;
}	t_data;

typedef struct s_pars
{
	char	*line;
	int		i;
	char	c;
	int		order_flag;
	int		fd;
	int		no_f;
	int		so_f;
	int		we_f;
	int		ea_f;
	int		floor_f;
	int		ceilling_f;
	int		map_height;
	t_data	data;
}	t_pars;

typedef struct s_raycolesion
{
	double	rays;
	double	angel_move;
	double	point_to_break;
	int		begin[2];
	int		end[2];
	double	distance;
	double	wall_height;
	int		ray_count;
	double	distanceprojplan;
	int		y;
	int		offcet;

}t_raycolesion;

typedef struct s_oneray
{
	int		y;
	int		x;
	int		px;
	int		py;
	int		left_begin_agrement_x_from_player;
	int		left_begin_agrement_x_from_player_x;
	double	degre;
	double	ray_colesion_y;
	double	ray_colesion_x;
	double	distance;
	double	ray_count;
	int		x_plus;
	int		y_plus;

}t_oneray;

char	*get_next_line(int fd);
void	move(t_data *data, int y, int x);
void	respone(t_data *data);
void	respone_obj(t_data *data);
int		hole_move(t_data *data);
void	move_rotated(t_data *data);
void	draw_line(t_data *game, int *begin, int *end, int color);
void	ray_colesion(t_data *data);
void	destroy_and_refresh(t_data *data);
int		movement(t_data *data);
int		key_up(int key, t_data *data);
int		key_down(int key, t_data *data);
int		rander_image(t_img *img, t_rect rect);
void	img_pix_put(t_img *img, int x, int y, int color);
double	one_ray(t_data *data, double angel, int ray_count);
int		get_pixel(t_get_pixel get_pixel_var);
void	draw_linev2(t_data *data, t_draw_linev2 line_var);
void	ray_colesion_for_sprite(t_data *data, double *tabl_of_distences);
double	one_ray_for_sprite(t_data *data, double angel);
void	draw_linev3(t_data *data, t_draw_linev3 line_var);
void	initial_var(t_data *data);
void	destroy(t_data *data);
void	respone2(t_data *data);
void	inisial_path(t_data *data);
int		y_detect_loop_for_sprite(t_data *data, int x,
			double angel, t_oneray *one_ray);
int		x_detect_for_sprite_loop(t_data *data, double angel, t_oneray *one_ray);
int		rander_image_for_mini_player(t_img *img, t_rect rect);
void	number_b(t_data *data);
void	aloccation_sprites_and_storage(t_data *data);
void	*background(void *var);
int		mouse(void);
int		mouse_down(int button, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);
void	check_file(char *path, t_data *data);
int		x_detect(t_oneray *oneray_var, t_data *data, double angel);
int		y_detect(t_data *data, t_oneray *oneray_var, double angel);
double	one_ray(t_data *data, double angel, int ray_count);
void	init_var(t_raycolesion *rc_var, double *betwinenngels,
			double *destence_of_door, t_data *data);
void	init_var_from_map(t_data *data, t_pars pars);
int		coin_animation(t_data *data, t_movement *var, int index_of_anim);
void	move_show_count(t_data *data);
void	start_game_and_menue(t_data *data);
#endif