/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:35:42 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/24 23:34:30 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

t_pars	init_pars(char *line, int fd)
{
	t_pars	pars;

	pars.fd = fd;
	if (!line)
		error("Invalid file!", &pars);
	pars.line = line;
	pars.i = 0;
	pars.c = pars.line[pars.i];
	pars.order_flag = 0;
	pars.no_f = 0;
	pars.so_f = 0;
	pars.we_f = 0;
	pars.ea_f = 0;
	pars.floor_f = 0;
	pars.ceilling_f = 0;
	pars.map_height = 0;
	pars.data.result = NULL;
	return (pars);
}

void	pars_advance(t_pars *pars)
{
	if (pars->c != '\0'
		&& pars->i < (int)ft_strlen(pars->line) - 1)
	{
		pars->i++;
		pars->c = pars->line[pars->i];
	}
}

void	skip_space(t_pars *pars)
{
	while (pars->line[pars->i]
		&& pars->line[pars->i] != '\n'
		&& pars->line[pars->i] == ' ')
		pars->i++;
	pars->c = pars->line[pars->i];
}

void	is_a_valid_elem(t_pars *pars)
{
	if (pars->c == ' ' && pars->order_flag != 6)
		skip_space(pars);
	if (pars->c == 'N' && !pars->no_f)
		check_no_tex(pars);
	else if (pars->c == 'S' && !pars->so_f)
		check_so_tex(pars);
	else if (pars->c == 'W' && !pars->we_f)
		check_we_tex(pars);
	else if (pars->c == 'E' && !pars->ea_f)
		check_ea_tex(pars);
	else if (pars->c == 'F' && !pars->floor_f)
		check_floor(pars);
	else if (pars->c == 'C' && !pars->ceilling_f)
	{
		pars->data.ceilling_color = check_floor_ceilling_elemt(pars);
		pars->ceilling_f = 1;
	}
	else if (pars->c == '\n')
		return ;
	else if (pars->order_flag == 6)
		check_map(pars);
	else
		error("Invalid file!", pars);
}

t_data	check_file(char *path,t_data *data)
{
	t_pars	pars;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("file not found!", NULL);
	pars = init_pars(get_next_line(fd), fd);
	while (pars.line)
	{
		if (pars.line[0] == '\n')
		{
			re_init_pars(&pars);
			continue ;
		}
		is_a_valid_elem(&pars);
		re_init_pars(&pars);
	}
	close(pars.fd);
	if (pars.order_flag == 6 && !pars.data.result)
		error("Map  element is missing!", NULL);
	else if (pars.order_flag != 6)
		error("Invalid file!", NULL);
	data->result = pars.data.result;
	data->no_tex_path = pars.data.no_tex_path;
	data->so_tex_path = pars.data.so_tex_path;
	data->we_tex_path = pars.data.we_tex_path;
	data->ea_tex_path = pars.data.ea_tex_path;
	data->floor_color = pars.data.floor_color;
	data->ceilling_color = pars.data.ceilling_color;
	return (pars.data);
}
