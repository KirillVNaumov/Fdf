/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_to_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:40:16 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:41:47 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_to_zero(t_fdf *fdf)
{
	fdf->first = (t_double_point *)malloc(sizeof(t_double_point));
	fdf->second = (t_double_point *)malloc(sizeof(t_double_point));
	fdf->angle = (t_double_point *)malloc(sizeof(t_double_point));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->angle->x = 0.523599;
	fdf->angle->y = 0.523599;
}
