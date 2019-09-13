/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:02:33 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/13 18:32:49 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
**	Сортировка листа комнат по имени комнаты
*/

void		sort_nodes(t_rooms *head)
{
	t_rooms *left;
	t_room	*tmp;
	t_rooms	*right;

	left = head;
	right = head->next;
	while (left->next)
	{
		while (right)
		{
			if (ft_strcmp(left->room->name, right->room->name) > 0)
			{
				tmp = left->room;
				left->room = right->room;
				right->room = tmp;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

void		print_nodes(t_rooms *head)
{
	while (head)
	{
		printf("%s %i\n", head->room->name, head->room->index);
		head = head->next;
	}
}

/*
**	Двоичный поиск по имени
*/

t_rooms		*find_room(const char *name, t_lemin *lem)
{
	size_t	left; 
	size_t	right;
	size_t	mid;
	size_t	i;
	t_rooms	*rooms;

	left = 0;
	right = lem->size + 1;
	rooms = lem->list;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		i = left;
		while (i < mid)
		{
			rooms = rooms->next;
			i++;
		}
		if (ft_strcmp(rooms->room->name, name) > 0)
		{
			right = mid;
			while (i-- > left)
				rooms = rooms->prev;
		}
		else if (ft_strcmp(rooms->room->name, name) < 0)
			left = mid;
		else
			return (rooms);
	}
	return (NULL);
}
