/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 22:30:37 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_startend(t_lemin *lem)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < lem->size)
	{
		sum += lem->smezh[lem->start->index][i];
		i++;
	}
	if (!sum)
		return (-1);
	i = 0;
	sum = 0;
	while (i < lem->size)
	{
		sum += lem->smezh[lem->end->index][i];
		i++;
	}
	if (!sum)
		return (-1);
	return (0);
}
