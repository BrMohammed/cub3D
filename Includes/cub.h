#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include <math.h>
#define pi 3.1415926535
#define ON_KEYUP_DERECTION key_up[0] 
#define ON_KEYUP_CAMERA key_up[1] 
#define ON_KEYDOWN_DERECTION key_down[0] 
#define ON_KEYDOWN_CAMERA key_down[1] 
#define KEY_LEFT key_select[0]
#define KEY_WRIGHT key_select[1]
#define KEY_W key_select[2]
#define KEY_S key_select[3]
#define KEY_A key_select[4]
#define KEY_D key_select[5]
#define KEY_UP key_select[6]
#define KEY_DOWN key_select[7]
#define KEY_SPACE key_select[8]
#define WIN_W data->demintion_with
#define WIN_H data->demension_hight

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_img_rander
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img_rander;

typedef struct s_img__sprite
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img_sprite;

typedef struct s_img_rander_derection
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img_rander_derection;

typedef struct s_data
{
	t_img	img;
	t_img_rander img_rander;
	t_img_rander_derection img_rander_derection;
	t_img_sprite img_sprite;
	int		cur_img;

	char		*NO_PATH;
	void 		*NO;

	char		*WE_PATH;
	void 		*WE;

	char		*SO_PATH;
	void 		*SO;

	char		*EA_PATH;
	void 		*EA;

	char *test_path;
	void *test;

	
	void		*mlx;
	void		*mlx_win;



	char		**result;

	double		player_y;
	double		player_x;

	double		pdx;
	double		pdy;
	double		pa;

	int result_hight;
	int result_with;

	int key_up[2];
	int key_down[2];
	int key_select[9];

	int ray_count;
	int player_y_for_3d;
	int player_x_for_3d;
	int color;
	

	int demension_hight;
	int demintion_with;
	double box_high;
	double box_with;
	int mini_map_res;
	int map_res;
	int player_mini_res;

	int offcet_x;
	int offcet_y;
	int offcet_x1;
	int offcet_y1;
	int ray_offset_in_y ;
	double speed;
	double angel_speed;
	double is_jumping_up;
	double is_jumping_down;
	double jump_force;
	double gravity;
	double lfo9 ;
    double lte7t ;
	int p_h;
	int p_w;
	int px_x;
	int py_x;
	int px_y;
	int py_y;

	int one_of;
	int sprite_x;
	int sprite_y;
	int *pos_of_sprite_x;
	int *pos_of_sprite_y;

	char *path_sprite;
	void *sprite_buf;
	int counter_of_sprites;

}	t_data;

typedef struct s_raycolesion
{
	double rays;
    double angel_move;
    double point_to_break;
    int begin[2];
	int end[2];
    double distance;
    double wallHeight;
    int ray_count;
	double distanceprojplan;

	
}t_raycolesion;

typedef struct s_oneray
{
	int y;
    int x;
    int px;
    int py;
    int left_begin_agrement_x_from_player;
    int left_begin_agrement_x_from_player_x;
    double degre;
    double ray_colesion_y;
    double ray_colesion_x;
    double distance;


}t_oneray;

char	*get_next_line(int fd);

void	move(t_data *data, int y, int x);
void	respone(t_data *data);
void	respone_obj(t_data *data);
int		hole_move(t_data *data);
char 	**check_map(char *str,t_data *data);
void	move_rotated(t_data *data);
void	draw_line(t_data *game, int *begin, int *end, int color);
void 	ray_colesion(t_data *data);
void	destroy_and_refresh(t_data *data);
int		movement(t_data *data);
int		key_up(int key, t_data *data);
int		key_down(int key, t_data *data);
int 	rander_image(t_img *img, t_rect rect);
void	img_pix_put(t_img *img, int x, int y, int color);
double 	one_ray(t_data *data,double angel);
int get_pixel(char *addr,int line_len,int x, int y);
void	draw_linev2(t_data *data, int *begin, int *end, int x,double wall_scall);
double ray_colesion_for_sprite(t_data *data,double *tabl_of_distences);
double one_ray_for_sprite(t_data *data,double angel);
void	draw_linev3(t_data *data, int *begin, int *end,double wall_scall,double *tabl_of_distences,double distence);
#endif