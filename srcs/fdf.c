/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:40:32 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:40:47 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** dont forget to remove mlx_mouse_hook
*/

int		main(int argc, char **argv)
{
	t_fdf fdf;

	ft_bzero(&fdf, sizeof(t_fdf));
	assign_to_zero(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1024, 1024, "FDF");
	if (argc == 2)
		read_file(&fdf, argv[1]);
	mlx_key_hook(fdf.win, exit_fn, &fdf);
	mlx_loop(fdf.mlx);
}
