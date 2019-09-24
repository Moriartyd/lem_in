/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:40 by adavis            #+#    #+#             */
/*   Updated: 2019/09/24 15:04:30 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	bfs(t_lemin *lem)
{
	t_queue	*q;
	int		i;
	int		start;

	printf("%d\n", start = lem->start->index);
	i = 0;
	while (i < lem->size)
	{
		if (lem->smezh[start][i])
			printf("Child: %d\n", i);
		i++;
	}
}
