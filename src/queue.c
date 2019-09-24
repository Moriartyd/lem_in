/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:20:10 by adavis            #+#    #+#             */
/*   Updated: 2019/09/24 14:35:52 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

t_queue	*init_queue(int index)
{
	t_queue	*new;

	new = (t_queue *)malloc(sizeof(*new));
	new->index = index;
	new->next = NULL;
	return (new);
}

void	push_queue(t_queue **queue, int index)
{
	t_queue	*new;

	if (!*queue)
		*queue = init_queue(index);
	else
	{
		new = (t_queue *)malloc(sizeof(t_queue));
		new->index = index;
		new->next = *queue;
		*queue = new;
	}
}

int		pop_queue(t_queue **q)
{
	int		index;
	t_queue *q_iter;
	t_queue	*tmp;

	if ((*q)->next)
	{
		q_iter = *q;
		while (q_iter->next)
		{
			tmp = q_iter;
			q_iter = q_iter->next;
		}
		tmp->next = NULL;
		index = q_iter->index;
		free(q_iter);
	}
	else
	{
		index = (*q)->index;
		free(*q);
		*q = NULL;
	}
	return (index);
}
