/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:40 by adavis            #+#    #+#             */
/*   Updated: 2019/09/24 14:38:53 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	bfs(t_rooms *rooms, t_room *start)
{
	t_queue	*q;

	rooms = rooms->next;
	push_queue(&q, start->index);
	printf("AAAAAAA%d\n", pop_queue(&q));
}
