/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/24 15:07:28 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_startend(t_lemin *lem)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < lem->size && lem->smezh)
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

int	check_lem(t_lemin *lem)
{
	int	res;

	res = 0;
	if (!lem->start)
		res += ft_printf("Error: Invalid start room\n");
	else if (!lem->end)
		res += ft_printf("Error: Invalid end room\n");
	else if (!lem->ants)
		res += ft_printf("Error: Invalid number of ants\n");
	else if (!lem->list)
		res += ft_printf("Error: Invalid room`s links\n");
	else if (check_startend(lem))
		res += ft_printf("Error: Start-room may not reach End-room\n");
	return (res == 0 ? (0) : (-2));
}
