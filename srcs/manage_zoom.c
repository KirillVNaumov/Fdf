#include "fdf.h"

void		zoom_plus(t_fdf *fdf)
{
	int 	i;
	int 	j;

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
