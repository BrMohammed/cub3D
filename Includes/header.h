/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:08:36 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/28 18:42:44 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
# include "cub.h"

int		error(char *msg, t_pars *pars);
void	re_init_pars(t_pars *pars);
int		get_map_len(char **map);
void	check_is_surrounded_by_walls(t_pars *pars, char **map);
void	check_first_last_line(t_pars *pars, char **map, int index);
void	check_walls(int i, int j, t_pars *pars, char **map);
void	check_first_column(t_pars *pars, char **map);
char	**correct_map(char **map);
int		get_map_len(char **map);
char	*char_to_str(char c);
void	check_map(t_pars *pars);
void	check_file(char *path, t_data *data);
void	is_a_valid_elem(t_pars *pars);
void	skip_space(t_pars *pars);
void	pars_advance(t_pars *pars);
t_pars	init_pars(char *line, int fd);
void	check_no_tex(t_pars *pars);
void	check_so_tex(t_pars *pars);
void	check_we_tex(t_pars *pars);
void	check_ea_tex(t_pars *pars);
void	check_floor(t_pars *pars);
int		check_nbr(char *s);
int		check_color_value(t_pars *pars);
int		check_floor_ceilling_elemt(t_pars *pars);
int		nbr_of_comma(t_pars *pars);
char	*check_tex(t_pars *pars, char c);
int		rgb(t_color color);
int		check_condition(t_pars *pars, int i);
#endif