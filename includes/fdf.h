/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:36:55 by amelikia          #+#    #+#             */
/*   Updated: 2019/04/24 12:59:58 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_point			*first;
	t_point			*second;
	t_point			*angle;
	int				**num;
	int				width;
	int				height;
	double			color_incr;
	t_point			***xyz_stock;
	t_point			***xyz_modif;
}					t_fdf;

int					exit_fn(int key, t_fdf *fdf, int i);
void				assign_to_zero(t_fdf *fdf);
void				read_file(t_fdf *fdf, int fd);
void				move_to_int(t_list **list, t_fdf *fdf);
void				save_data_in_stock(t_fdf *fdf);
void				make_modified(t_fdf *fdf);
void				printline(t_fdf *fdf);
void				print_figure(t_fdf *fdf);
int					check_ampl(t_fdf *fdf);
void				ampl_plus(t_fdf *fdf);
void				ampl_minus(t_fdf *fdf);
int					check_zoom(t_fdf *fdf);
void				zoom_plus(t_fdf *fdf);
void				zoom_minus(t_fdf *fdf);
void				draw_map(t_fdf *fdf);

/*
**	Utils
*/

int					ft_list_size(t_list *list);
t_list				*add_list(t_list *list, char *str);
int					find_width(char *s);
void				ft_clean_list(t_list **list);
void				ft_clean_t_point_matrix(t_point	****arr, \
											int height, int width);
void				ft_clean_and_exit(t_fdf *fdf);

#endif
