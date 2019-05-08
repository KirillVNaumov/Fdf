/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:40:24 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:40:25 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_fn(int key, t_fdf *fdf, int i)
{
	(key == 27) ? zoom_minus(fdf) : (i = 0);
	(key == 24) ? zoom_plus(fdf) : (i = 0);
	(key == 25) ? ampl_plus(fdf) : (i = 0);
	(key == 29) ? ampl_minus(fdf) : (i = 0);
	if (key == 42 || key == 126 || key == 125 || key == 123 || \
		key == 124 || key == 27 || key == 25 || key == 24 || key == 29)
		mlx_clear_window(fdf->mlx, fdf->win);
	(key == 53) ? ft_clean_and_exit(fdf) : (i = 0);
	(key == 126) ? fdf->angle->x += 0.1 : (i = 0);
	(key == 126) ? fdf->angle->y += 0.1 : (i = 0);
	(key == 125 || key == 123) ? fdf->angle->x -= 0.1 : (i = 0);
	(key == 125 || key == 124) ? fdf->angle->y -= 0.1 : (i = 0);
	if (key == 126 || key == 125 || key == 123 || key == 124 || \
		key == 27 || key == 25 || key == 24 || key == 29)
	{
		make_modified(fdf);
		print_figure(fdf);
		ft_clean_t_point_matrix(&fdf->xyz_modif, fdf->height, fdf->width);
	}
	return (0);
}
