#include "fdf.h"

void		ampl_plus(t_fdf *fdf)
{
	int 	i;
	int 	j;
	double	increment;

	i = 0;
	increment = 1.1;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->xyz_stock[i][j]->z != 0)
				fdf->xyz_stock[i][j]->z *= increment;
			j++;
		}
		i++;
	}
}

void	ampl_minus(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->z /= 1.1;
			j++;
		}
		i++;
	}
}