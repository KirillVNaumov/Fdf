/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:42:26 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:42:27 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_clean_t_point_matrix(t_point ****arr, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			free((*arr)[i][j]);
			++j;
		}
		free((*arr)[i]);
		++i;
	}
	free(*arr);
}

void		ft_clean_and_exit(t_fdf *fdf)
{
	free(fdf->first);
	free(fdf->second);
	free(fdf->angle);
	ft_clean_t_point_matrix(&fdf->xyz_stock, fdf->height, fdf->width);
	exit(1);
}
