/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:06:02 by adavis            #+#    #+#             */
/*   Updated: 2019/09/29 20:14:40 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_stack	*init_stack(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	push_stack(t_stack **s, int nbr)
{
	t_stack	*new;
	t_stack	*iter;

	if (!*s)
		*s = init_stack(nbr);
	else
	{
		iter = *s;
		while (iter->next)
			iter = iter->next;
		new = (t_stack *)malloc(sizeof(t_stack));
		new->nbr = nbr;
		new->next = NULL;
		iter->next = new;
	}
}

int		read_stack(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->nbr);
}

int		pop_stack(t_stack **s)
{
	int		nbr;

	nbr = (*s)->nbr;
	if ((*s)->next)
		*s = (*s)->next;
	else
		*s = NULL;
	return (nbr);
}
