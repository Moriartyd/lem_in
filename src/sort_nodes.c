/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:02:33 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 15:20:59 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

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
	t_rooms	*rooms;

	if (!lem || !lem->list || !name)
		return (NULL);
	rooms = lem->list;
	while (rooms)
	{
		if (!ft_strcmp(rooms->room->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room		*find_room_ind(int ind, t_lemin *lem)
{
	t_rooms	*rooms;

	if (!lem || !lem->list || ind < 0)
		return (NULL);
	rooms = lem->list;
	while (rooms)
	{
		if (rooms->room->index == ind)
			return (rooms->room);
		rooms = rooms->next;
	}
	return (NULL);
}

t_rooms		*is_same_lvl(int lvl, t_rooms *head)
{
	t_rooms	*rooms;

	rooms = head;
	while (rooms)
	{
		if (rooms->room->level == lvl && rooms->room->out > 1)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}
