/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:45 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/24 17:15:07 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(size_t size, int *ind)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!(room->name = ft_strnew(size)))
	{
		free(room);
		return (NULL);
	}
	room->index = *ind;
	room->level = -1;
	*ind = *ind + 1;
	return (room);
}

t_room	*rm_room(t_room *room)
{
	if (!room)
		return (NULL);
	ft_strdel(&(room->name));
	room->index = 0;
	room->level = 0;
	free(room);
	room = NULL;
	return (room);
}

void	mem_clean(t_lemin *lem)
{
	lem->list = rm_rooms(lem->list);
	lem->ants = 0;
	lem->end = NULL;
	lem->start = NULL;
	ft_doublematrixdel(&(lem->smezh), lem->size);
	lem->size = 0;
	free(lem);
}
