/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/26 23:33:10 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_startend(t_lemin *lem)
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

int		check_lem(t_lemin *lem)
{
	int	res;

	res = 0;
	if (!lem->start)
		res += ft_putstr("Error: Invalid start room\n");
	else if (!lem->end)
		res += ft_putstr("Error: Invalid end room\n");
	else if (!lem->ants)
		res += ft_putstr("Error: Invalid number of ants\n");
	else if (!lem->list)
		res += ft_putstr("Error: Invalid room`s links\n");
	else if (check_startend(lem))
		res += ft_putstr("Error: Start-room may not reach End-room\n");
	return (res == 0 ? (0) : (-2));
}

void	error_manager(t_lemin *lem, int error)
{
	if (error == -1)
		perror("Error");
	else if (error == -2)
		check_lem(lem);
	else if (error == -3)
		ft_putstr("Error: Invalid links\n");
	else if (error == -4)
		ft_putstr("Error: Invalid rooms\n");
}
