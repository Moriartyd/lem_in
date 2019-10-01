/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:28:23 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 15:38:40 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*create_ants(t_lemin *lem)
{
	t_ant	*ants;
	int		i;

	ants = (t_ant *)malloc(sizeof(t_ant) * lem->ants);
	i = -1;
	while (++i < lem->ants)
	{
		ants[i].room = lem->start->index;
		ants[i].path = -1;
	}
	return (ants);
}
t_ant   *remove_ants(t_ant **ant)
{
    if (ant && *ant)
	{
    	free(*ant);
    	*ant = NULL;
	}
    return (NULL);
}
