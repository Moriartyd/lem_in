/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:03:26 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/26 20:57:59 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_rooms	*choose_best_variant(t_rooms **rooms)
{
	int	level;
	int	i;

	level = 0;
	i = -1;
	while (rooms && rooms[++i])
		if (rooms[i]->room->level > level)
			level = rooms[i]->room->level;
	i = -1;
	while (rooms && rooms[++i] && rooms[i]->room->level != level)
		;
	return (rooms[i]);
}

static t_rooms	*find_rooms_ind(int ind, t_lemin *lem)
{
	t_rooms	*rooms;

	if (!lem || !lem->list || ind < 0)
		return (NULL);
	rooms = lem->list;
	while (rooms)
	{
		if (rooms->room->index == ind)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_rooms			*find_final_room(t_lemin *lem)
{
	int		i;
	int		size;
	t_rooms	**rooms;
	t_rooms	*ret;

	i = -1;
	size = 0;
	while (++i < lem->size)
		if (lem->smezh[i][lem->end->index])
			size++;
	if (!(rooms = (t_rooms **)malloc(sizeof(t_rooms *) * (size + 1))))
		exit (-1);
	i = -1;
	rooms[size] = NULL;
	size = 0;
	while (++i < lem->size)
	{
		if (lem->smezh[i][lem->end->index])
		{
			rooms[size] = find_rooms_ind(i, lem);
			size++;
		}
	}
	ret = choose_best_variant(rooms);
	free(rooms);
	return (ret);
}
