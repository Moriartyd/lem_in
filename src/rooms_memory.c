/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:15:11 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 21:04:07 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms	*create_firstrooms(t_room *room)
{
	t_rooms	*res;

	if (!(res = init_rooms()))
		return (NULL);
	res->room = room;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_rooms	*add_rooms(t_rooms *src, t_room *room)
{
	t_rooms *new;

	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	new->room = room;
	new->prev = src;
	new->next = NULL;
	src->next = new;
	return (new);
}

t_rooms	*init_rooms(void)
{
	t_rooms	*res;

	if (!(res = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	res->next = NULL;
	res->prev = NULL;
	res->room = NULL;
	return (res);
}

t_rooms	*rm_rooms(t_rooms *head)
{
	t_rooms	*next;

	while (head)
	{
		if (head->room->name)
		next = head->next;
		head->room = rm_room(head->room);
		head->prev = NULL;
		head->next = NULL;
		free(head);
		head = next;
	}
	return (head);
}
