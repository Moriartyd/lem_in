/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:45 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/26 23:29:36 by cpollich         ###   ########.fr       */
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
	room->x = 0;
	room->y = 0;
	room->level = -1;
	room->in = 0;
	room->out = 0;
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

int		valid_room(t_room *room1, t_room *room2)
{
	if ((room1->x == room2->x && room1->y == room2->y)
		|| !ft_strcmp(room1->name, room2->name))
		return (0);
	else
		return (1);
}

void	set_coord(t_room *room, char *line)
{
	int	x;
	int	y;

	room->x = ft_atoi(line + 1);
	room->y = ft_atoi(ft_strchr(line + 1, ' ') + 1);
}