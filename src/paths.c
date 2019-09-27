/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:44:23 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/27 17:10:00 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Shitty pathfinder
*/

void	make_path(t_lemin *lem, t_stack **s)
{
	int		i;
	int		current;

	current = read_stack(*s);
	if (current != lem->end->index)
	{
		i = 0;
		while (i < lem->size)
		{
			if (lem->smezh[current][i] == 1)
			{
				push_stack(s, i);
				make_path(lem, s);
			}
			i++;
		}
	}
	else
	{
		push_stack(s, -1);
	}
}

/*
**	Shitty pathfinder
*/

void	create_paths(t_lemin *lem)
{
	t_stack	*s;
	int		i;

	s = NULL;
	push_stack(&s, lem->start->index);
	make_path(lem, &s);
	pop_stack(&s);
	while (s)
	{
		if (read_stack(s) != lem->start->index)
		{
			i = pop_stack(&s);
			if (i == -1)
				printf("\n");
			else
				printf("%s ", find_room_ind(i, lem)->name);
		}
		else
			pop_stack(&s);
	}
}
