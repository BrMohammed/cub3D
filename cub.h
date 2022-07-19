#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

typedef struct s_data
{
    int			win;
	void		*hole;
	char		*hole_path;

	int			hole_high;
	int			hole_whith;

	void		*dead;
	char		*dead_path;

	void		*mlx;
	void		*mlx_win;

	void		*player;
	char		*player_path;

	void		*player_left;
	char		*player_left_path;

	char		*walls_path;
	void		*walls;

	int			high;
	int			whith;
	char		*plat_path;
	void		*plat;
	char		**result;

	void		*coin;
	char		*coin_path;

	void		*coin1;
	char		*coin_path1;

	void		*door_close;
	char		*door_cloce_path;

	void		*door_open;
	char		*door_open_path;

	int			door_high;
	int			door_whith;

	int			coin_point ;
	int			player_count ;

	int			img_width;
	int			img_height;

	char		*bufer;
}	t_data;

char	*get_next_line(int fd);

void	move(t_data *data, char v, int y, int x);
void	error_game(char **c, int error, int fd, char *str);
void	respone(t_data *data);
void	respone_obj(t_data *data);
int		hole_move(t_data *data);
void 	destroy(t_data *data);
void 	respone2(t_data *data);
void check_map(char *str);
#endif