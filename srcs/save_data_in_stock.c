/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data_in_stock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:41:40 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:41:41 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_data_in_stock(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	fdf->xyz_stock = (t_point ***)malloc(sizeof(t_point **) * (fdf->height + 1));
	fdf->xyz_stock[fdf->height] = NULL;
	while (i < fdf->height)
	{
		fdf->xyz_stock[i] = (t_point **)malloc(sizeof(t_point *) * (fdf->width + 1));
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j] = (t_point *)malloc(sizeof(t_point));
			fdf->xyz_stock[i][j]->x = j + 1;
			fdf->xyz_stock[i][j]->y = i + 1;
			fdf->xyz_stock[i][j]->z = fdf->num[i][j];
			fdf->xyz_stock[i][j]->x *= 30;
			fdf->xyz_stock[i][j]->y *= 30;
			fdf->xyz_stock[i][j]->z *= 10;
			j++;
		}
		fdf->xyz_stock[i][j] = NULL;
		i++;
	}
}
