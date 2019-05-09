/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:41:18 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/08 23:46:36 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		count_width(char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '-' && \
			(line[i] > '9' || line[i] < '0'))
			return (0);
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			++width;
			if (line[i] == '-')
				++i;
			while (line[i] >= '0' && line[i] <= '9')
				++i;
		}
		if (line[i] != ' ' && line[i] != '\0')
			return (0);
		if (line[i])
			++i;
	}
	return (width);
}

int		check_input(t_list *list)
{
	int	width;
	int	tmp;

	if (!list)
		return (-1);
	width = count_width(list->line);
	if (width == 0)
		return (-1);
	list = list->next;
	while (list)
	{
		tmp = count_width(list->line);
		if (width != tmp || tmp == 0)
			return (-1);
		list = list->next;
	}
	return (1);
}

void	copy_data(t_list *list, t_fdf *fdf)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (list)
	{
		j = 0;
		k = 0;
		fdf->num[i] = (int*)malloc(sizeof(int) * fdf->width);
		line = list->line;
		while (j < fdf->width)
		{
			fdf->num[i][j] = ft_atoi(&line[k]);
			while (line[k] && line[k] != ' ')
				k++;
			while (line[k] && line[k] == ' ')
				k++;
			j++;
		}
		i++;
		list = list->next;
	}
}

void	move_to_int(t_list **list, t_fdf *fdf)
{
	int		list_size;

	if (check_input(*list) == -1)
	{
		free(fdf->first);
		free(fdf->second);
		free(fdf->angle);
		ft_clean_list(list);
		error("Input error");
	}
	list_size = ft_list_size(*list);
	fdf->height = list_size;
	fdf->num = (int**)malloc(sizeof(int*) * (list_size + 1));
	fdf->num[list_size] = NULL;
	fdf->width = find_width((*list)->line);
	copy_data(*list, fdf);
}
