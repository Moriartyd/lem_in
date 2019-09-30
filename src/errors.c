/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 20:23:09 by cpollich         ###   ########.fr       */
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
		res += ft_putstr_fd("Error: Invalid start room\n", 2);
	else if (!lem->end)
		res += ft_putstr_fd("Error: Invalid end room\n", 2);
	else if (!lem->ants)
		res += ft_putstr_fd("Error: Invalid number of ants\n", 2);
	else if (!lem->list)
		res += ft_putstr_fd("Error: Invalid room`s links\n", 2);
	else if (check_startend(lem))
		res += ft_putstr_fd("Error: Start-room may not reach End-room\n", 2);
	return (res == 0 ? (0) : (-2));
}

void	error_manager(t_lemin *lem, int error)
{
	if (error == -1)
		perror("Error");
	else if (error == -2)
		check_lem(lem);
	else if (error == -3)
		ft_putstr_fd("Error: Invalid links\n", 2);
	else if (error == -4)
		ft_putstr_fd("Error: Invalid rooms\n", 2);
}
