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

typedef struct s_data
{
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

	int result_lenght;
	int result_x_length;

	double px_y;
	double py_y;
	double px_x;
	double py_x;
}	t_data;

char	*get_next_line(int fd);

void	move(t_data *data, int y, int x);
void	respone(t_data *data);
void	respone_obj(t_data *data);
int		hole_move(t_data *data);
void 	destroy(t_data *data);
void 	respone2(t_data *data);
char 	**check_map(char *str,t_data *data);
void	move_rotated(t_data *data);
void	draw_line(t_data *game, int *begin, int *end, int color);
void ray_colesion(t_data *data);
#endif