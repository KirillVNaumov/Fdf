/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_modified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:41:05 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:41:09 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_modified(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	fdf->xyz_modif = (t_point ***)malloc(sizeof(t_point **) * (fdf->height + 1));
	fdf->xyz_modif[fdf->height] = NULL;
	while (i < fdf->height)
	{
		fdf->xyz_modif[i] = (t_point **)malloc(sizeof(t_point *) * (fdf->width + 1));
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_modif[i][j] = (t_point *)malloc(sizeof(t_point));
			fdf->xyz_modif[i][j]->x = 400 + ((fdf->xyz_stock[i][j]->x -\
				fdf->xyz_stock[i][j]->y) * cos(fdf->angle->x));
			fdf->xyz_modif[i][j]->y = 150 + (((fdf->xyz_stock[i][j]->x +\
				fdf->xyz_stock[i][j]->y) * sin(fdf->angle->y))\
				- fdf->xyz_stock[i][j]->z);
			fdf->xyz_modif[i][j]->z = fdf->xyz_stock[i][j]->z;
			j++;
		}
		fdf->xyz_modif[i][j] = NULL;
		i++;
	}
}
