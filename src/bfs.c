/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:40 by adavis            #+#    #+#             */
/*   Updated: 2019/09/24 21:20:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		q_len(t_queue *q)
{
	int		cnt;

	cnt = 0;
	while (q)
	{
		cnt++;
		q = q->next;
	}
	return (cnt);
}

void	print_levels(t_lemin *lem)
{
	while (lem->list)
	{
		printf("%s\t%d\n", lem->list->room->name, lem->list->room->level);
		lem->list = lem->list->next;
	}
}

/*
**	OUT	- horizontal
**	IN	- vertikal
*/

void	count_in_out(t_lemin *lem)
{
	int		index;
	int		i;
	t_rooms	*rooms;

	rooms = lem->list;
	while (rooms && rooms->room)
	{
		index = rooms->room->index;
		i = -1;
		while (++i < lem->size)
		{
			rooms->room->out += lem->smezh[index][i];
			rooms->room->in += lem->smezh[i][index];
		}
		rooms = rooms->next;
	}
}

void	remove_links(t_lemin *lem)
{
	int		i;
	int		j;
	t_room	*k;
	t_room	*l;

	i = 0;
	while (i < lem->size)
	{
		ft_printf("%s\t", find_room_ind(i, lem)->name);
		j = 0;
		while (j < lem->size)
		{
			k = find_room_ind(i, lem);
			l = find_room_ind(j, lem);
			if (k->level >= l->level || k->level < 0 || l->level < 0)
				lem->smezh[i][j] = 0;
			printf("%d ", lem->smezh[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	count_in_out(lem);
}

void	bfs(t_lemin *lem)
{
	t_queue	*q;
	int		i;
	int		current;

	q = NULL;
	push_queue(&q, lem->start->index);
	while (q)
	{
		current = pop_queue(&q);
		i = 0;
		while (i < lem->size)
		{
			if (lem->smezh[current][i] && find_room_ind(i, lem)->level == -1)
			{
				push_queue(&q, i);
				if (find_room_ind(i, lem)->level == -1)
					find_room_ind(i, lem)->level =
						find_room_ind(current, lem)->level + 1;
			}
			i++;
		}
	}
	remove_links(lem);
}
