/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:41:30 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:41:31 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_border_lines(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->height - 1)
	{
		fdf->first->x = fdf->xyz_modif[i][fdf->width - 1]->x;
		fdf->first->y = fdf->xyz_modif[i][fdf->width - 1]->y;
		fdf->first->z = fdf->xyz_modif[i][fdf->width - 1]->z;
		fdf->second->x = fdf->xyz_modif[i + 1][fdf->width - 1]->x;
		fdf->second->y = fdf->xyz_modif[i + 1][fdf->width - 1]->y;
		fdf->second->z = fdf->xyz_modif[i + 1][fdf->width - 1]->z;
		printline(fdf);
		i++;
	}
	i = 0;
	while (i < fdf->width - 1)
	{
		fdf->first->x = fdf->xyz_modif[fdf->height - 1][i]->x;
		fdf->first->y = fdf->xyz_modif[fdf->height - 1][i]->y;
		fdf->first->z = fdf->xyz_modif[fdf->height - 1][i]->z;
		fdf->second->x = fdf->xyz_modif[fdf->height - 1][i + 1]->x;
		fdf->second->y = fdf->xyz_modif[fdf->height - 1][i + 1]->y;
		fdf->second->z = fdf->xyz_modif[fdf->height - 1][i + 1]->z;
		printline(fdf);
		i++;
	}
}

void	print_figure(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height - 1)
	{
		j = 0;
		while (j < fdf->width - 1)
		{
			fdf->first->x = fdf->xyz_modif[i][j]->x;
			fdf->first->y = fdf->xyz_modif[i][j]->y;
			fdf->first->z = fdf->xyz_modif[i][j]->z;
			fdf->second->x = fdf->xyz_modif[i + 1][j]->x;
			fdf->second->y = fdf->xyz_modif[i + 1][j]->y;
			fdf->second->z = fdf->xyz_modif[i + 1][j]->z;
			printline(fdf);
			fdf->second->x = fdf->xyz_modif[i][j + 1]->x;
			fdf->second->y = fdf->xyz_modif[i][j + 1]->y;
			fdf->second->z = fdf->xyz_modif[i][j + 1]->z;
			printline(fdf);
			j++;
		}
		i++;
	}
	print_border_lines(fdf);
}

void	read_file(t_fdf *fdf, char *str)
{
	int		fd;
	t_list	*matrix;
	char	*line;

	matrix = NULL;
	fdf->first->x = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error("Invalid file");
	while (get_next_line(fd, &line) == 1)
	{
		matrix = list_append(matrix, line);
		ft_strdel(&line);
	}
	move_to_int(matrix, fdf);
	ft_clean_list(&matrix);
	save_data_in_stock(fdf);
	ft_clean_int_arr(&fdf->num);
	make_modified(fdf);
	print_figure(fdf);
	ft_clean_t_point_matrix(&fdf->xyz_modif, fdf->height, fdf->width);
	close(fd);
}
