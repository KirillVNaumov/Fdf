/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:40:54 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:40:55 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_low(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point			*diff;
	t_point			*point;
	double			yi;
	double			d;
	double			color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	diff->x = second->x - first->x;
	diff->y = second->y - first->y;
	diff->z	= (second->z > first->z) ? (second->z - first->z) : (first->z - second->z);
	yi = 0;
	(diff->y < 0) ? (yi -= 1) : (yi += 1);
	(diff->y < 0) ? (diff->y = -diff->y) : (yi += 0);
	d = 2 * diff->y - diff->x;
	point->y = first->y;
	point->x = first->x - 1;
	printf("diff->z = %.1f\n", diff->z);
	color_increment = diff->z / (second->y - point->y);
	printf("increment color = %.1f\n", color_increment);
	color_increment = 280;
	while (++point->x < second->x)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, (int)point->x, (int)point->y, minimum_altitude);
		(d > 0) ? (point->y = point->y + yi) : (minimum_altitude += 0);
		(d > 0) ? (d = d - 2 * diff->x) : (minimum_altitude += 0);
		minimum_altitude += color_increment;
		d = d + 2 * diff->y;
	}
	free(diff);
	free(point);
}

void	print_high(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point			*diff;
	t_point			*point;
	double			xi;
	double			d;
	double			color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	diff->x = second->x - first->x;
	diff->y = second->y - first->y;
	diff->z	= (second->z > first->z) ? (second->z - first->z) : (first->z - second->z);
	xi = 0;
	(diff->x < 0) ? (xi -= 1) : (xi = 1);
	(diff->x < 0) ? (diff->x = -diff->x) : (xi += 0);
	d = 2 * diff->x - diff->y;
	point->y = first->y - 1;
	point->x = first->x;
	printf("diff->z = %.1f\n", diff->z);
	color_increment = diff->z / (second->y - point->y);
	printf("increment color = %.1f\n", color_increment);
	color_increment = 280;
	while (++point->y < second->y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, (int)point->x, (int)point->y, minimum_altitude);
		(d > 0) ? (point->x = point->x + xi) : (minimum_altitude += 0);
		(d > 0) ? (d = d - 2 * diff->y) : (minimum_altitude += 0);
		minimum_altitude += color_increment;
		d = d + 2 * diff->x;
	}
	free(diff);
	free(point);
}

// 98765

// 16 000 000 

void	printline(t_fdf *fdf)
{
	int		minimum_altitude;

	printf("\n");
	printf("first->z = %.1f\n", fdf->first->z);
	printf("second->z = %.1f\n", fdf->second->z);

	minimum_altitude = (fdf->first->z > fdf->second->z ? fdf->second->z : fdf->first->z);
	if (ft_abs(fdf->second->y - fdf->first->y) < \
		ft_abs(fdf->second->x - fdf->first->x))
	{
		if (fdf->first->x > fdf->second->x)
			print_low(fdf, fdf->second, fdf->first, minimum_altitude * 900000);
		else
			print_low(fdf, fdf->first, fdf->second, minimum_altitude * 900000);
	}
	else
	{
		if (fdf->first->y > fdf->second->y)
			print_high(fdf, fdf->second, fdf->first, minimum_altitude * 900000);
		else
			print_high(fdf, fdf->first, fdf->second, minimum_altitude * 900000);
	}
	printf("\n");
}
