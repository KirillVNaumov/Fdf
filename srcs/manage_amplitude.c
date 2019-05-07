#include "fdf.h"

int			check_ampl(t_fdf *fdf)
{
	int 	i;
	int 	j;
	int		tmp;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->xyz_stock[i][j]->z != 0)
			{
				tmp = fdf->xyz_stock[i][j]->z / 1.1;
				if (tmp == 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

double		identify_increment(t_fdf *fdf)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->xyz_stock[i][j]->z != 0 && fdf->xyz_stock[i][j]->z < 10)
				return (2);
			j++;
		}
		i++;
	}
	return (1.1);
}

void		ampl_plus(t_fdf *fdf)
{
	int 	i;
	int 	j;
	double	increment;

	i = 0;
	increment = identify_increment(fdf);
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

	if (check_ampl(fdf) == -1)
		return ;
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