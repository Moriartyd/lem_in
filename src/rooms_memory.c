/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:15:11 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 20:17:57 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms	*add_rooms(t_rooms *src, t_room *room)
{
	t_rooms *new;

	if (!src)
	{
		if (!(src = init_rooms()))
			return (NULL);
		src->next = NULL;
		src->prev = NULL;
		src->room = room;
		return (src);
	}
	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	new->room = room;
	new->prev = src;
	new->next = NULL;
	src = src->next;
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
}
