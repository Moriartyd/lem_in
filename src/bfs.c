/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:40 by adavis            #+#    #+#             */
/*   Updated: 2019/09/24 17:03:58 by adavis           ###   ########.fr       */
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

void	bfs(t_lemin *lem)
{
	t_queue	*q;
	int		i;
	int		j;
	int		start;
	int		current;

	q = NULL;
	push_queue(&q, lem->start->index);
	lem->start->level = 0;
	lem->end->level = 2147483647;
	lem->end->visit = 1;
	while (q)
	{
		current = pop_queue(&q);
		printf("current: %s\n", find_room_ind(current, lem)->name);
		find_room_ind(current, lem)->visit = 1;
		i = 0;
		while (i < lem->size)
		{
			if (lem->smezh[current][i] && !(find_room_ind(i, lem)->visit))
			{
				push_queue(&q, i);
				if (find_room_ind(i, lem)->level == -1)
					find_room_ind(i, lem)->level = find_room_ind(current, lem)->level + 1;
			}
			i++;
		}
	}
}
