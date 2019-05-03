#include <fdf.h>

void	ft_clean_list(t_list **list)
{
	t_list *node;

	node = *list;
	if (node && node->next)
		ft_clean_list(&node->next);
	free(node->line);
	free(node);
}

void		ft_clean_t_point_matrix(t_point	****arr, int height, int width)
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

void	ft_clean_and_exit(t_fdf *fdf)
{
	free(fdf->first);
	free(fdf->second);
	free(fdf->angle);
	ft_clean_t_point_matrix(&fdf->xyz_stock, fdf->height, fdf->width);
	while (2);
	exit(1);
}