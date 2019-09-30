/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:44:23 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 14:47:10 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	A better pathfinder
*/

void	follow_path(t_lemin *lem, int i)
{
	int		j;

	j = -1;
	while (++j < lem->size && i != lem->end->index)
	{
		if (lem->smezh[i][j])
		{
			printf("%s->", find_room_ind(i, lem)->name);
			i = j;
			j = -1;
		}
	}
	printf("%s\n", find_room_ind(i, lem)->name);
}

void	create_paths(t_lemin *lem)
{
	int		i;
	int		start;

	start = lem->start->index;
	i = -1;
	while (++i < lem->size)
	{
		if (lem->smezh[start][i])
		{
			printf("\n");
			follow_path(lem, i);
		}
	}
}
