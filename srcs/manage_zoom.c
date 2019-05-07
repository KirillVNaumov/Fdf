#include "fdf.h"

int			check_zoom(t_fdf *fdf)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->xyz_stock[i][j]->x / 1.3 < 10)
				return (-1);
			if (fdf->xyz_stock[i][j]->y / 1.3 < 10)
				return (-1);
			if (fdf->xyz_stock[i][j]->z / 1.1 < 10 && fdf->xyz_stock[i][j]->z != 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

// double		identify_increment_for_zoom(t_fdf *fdf)
// {
// 	int 	i;
// 	int 	j;

// 	i = 0;
// 	while (i < fdf->height)
// 	{
// 		j = 0;
// 		while (j < fdf->width)
// 		{
// 			if (fdf->xyz_stock[i][j]->z != 0 && fdf->xyz_stock[i][j]->z < 10)
// 				return (2);
// 			if (fdf->xyz_stock[i][j]->x / 1.3 < 1)
// 				return (2);
// 			if (fdf->xyz_stock[i][j]->y / 1.3 < 1)
// 				return (2);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1.1);
// }

void		zoom_plus(t_fdf *fdf)
{
	int 	i;
	int 	j;

	ft_printf("Entered zoom_plus\n");
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->x *= 1.3;
			fdf->xyz_stock[i][j]->y *= 1.3;
			fdf->xyz_stock[i][j]->z *= 1.3;
			j++;
		}
		i++;
	}
}

void	zoom_minus(t_fdf *fdf)
{
	int i;
	int j;

	ft_printf("Entered zoom_minus\n");
	draw_map(fdf);
	if (check_zoom(fdf) == -1)
	{
		ft_printf("zoom = -1\n");
		return ;
	}
	ft_printf("zoom = 1\n");
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->x /= 1.3;
			fdf->xyz_stock[i][j]->y /= 1.3;
			fdf->xyz_stock[i][j]->z /= 1.3;
			j++;
		}
		i++;
	}
}
