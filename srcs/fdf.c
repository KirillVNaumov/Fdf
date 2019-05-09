/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:40:32 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/08 23:43:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	ft_bzero(&fdf, sizeof(t_fdf));
	assign_to_zero(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1024, 1024, "FDF");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR);
		read_file(&fdf, fd);
	}
	else
	{
		free(fdf.first);
		free(fdf.second);
		free(fdf.angle);
		error("Wrong number of arguments");
	}
	mlx_key_hook(fdf.win, exit_fn, &fdf);
	mlx_loop(fdf.mlx);
}
