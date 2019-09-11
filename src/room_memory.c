/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:45 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/11 20:06:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(size_t size, int ind)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!(room->name = (char *)malloc(sizeof(char) * size)))
	{
		free(room);
		return (NULL);
	}
	room->index = ind;
	return (room);
}
