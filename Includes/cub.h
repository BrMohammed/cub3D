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
#define WIN_W data->result_with * 50
#define WIN_H data->result_hight * 50

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


typedef struct s_data
{
	t_img	img;
	int		cur_img;
	
	void		*mlx;
	void		*mlx_win;

	int			img_width;
	int			img_height;

	void		*player;
	char		*player_path;

	void		*player_left;
	char		*player_left_path;

	char		*walls_path;
	void		*walls;

	char		*plat_path;
	void		*plat;
	char		**result;

	double		player_y;
	double		player_x;

	double		pdx;
	double		pdy;
	double		pa;
	double		lenght_of_ray;

	int result_hight;
	int result_with;

	double px_y;
	double py_y;
	double px_x;
	double py_x;
	int key_up[2];
	int key_down[2];
	int key_select[6];

	int ray_count;
	int player_y_for_3d;
	int player_x_for_3d;
}	t_data;

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

#endif