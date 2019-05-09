/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:42:31 by knaumov           #+#    #+#             */
/*   Updated: 2019/05/06 12:42:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list		*add_list(t_list *list, char *data)
{
	t_list	*begin;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->line = ft_strdup(data);
	new->next = NULL;
	if (!list)
		return (new);
	begin = list;
	while (list->next)
		list = list->next;
	list->next = new;
	return (begin);
}

int			ft_list_size(t_list *list)
{
	int		i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void		ft_clean_list(t_list **list)
{
	t_list	*node;

	node = *list;
	if (node && node->next)
		ft_clean_list(&node->next);
	free(node->line);
	free(node);
}
