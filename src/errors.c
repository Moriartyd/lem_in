/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:26:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 20:18:12 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_startend(t_lemin *lem)
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

/*
**	-10	- Invalid start room
**	-11 - Invalid end room
**	-12 - Invalid number of ants
**	-13 - Invalid room`s links
**	-14 - Start-room may not reach End-room
*/

int			check_lem(t_lemin *lem)
{
	int	res;

	res = 0;
	if (!lem->start)
		return (-10);
	else if (!lem->end)
		return (-11);
	else if (!lem->ants)
		return (-12);
	else if (!lem->list)
		return (-13);
	else if (check_startend(lem))
		return (-14);
	return (res);
}

/*
**	1	- start
** 	2	- end
** 	3	- link
**	4	- room
**	5	- ants
**	-1	- error
**	-2	- error with lem
**	-3	- error with links
**	-4	- error with room
**	-5	- Invalid number of ants
**	-10	- Invalid start room
**	-11 - Invalid end room
**	-12 - Invalid number of ants
**	-13 - Invalid room`s links
**	-14 - Start-room may not reach End-room
**	0	- comment
*/

static void	error_manager2(int error)
{
	if (error == -10)
		ft_putstr_fd("Error: Invalid start room\n", 2);
	else if (error == -11)
		ft_putstr_fd("Error: Invalid end room\n", 2);
	else if (error == -12)
		ft_putstr_fd("Error: Invalid number of ants\n", 2);
	else if (error == -13)
		ft_putstr_fd("Error: Invalid room`s links\n", 2);
	else if (error == -14)
		ft_putstr_fd("Error: Start-room may not reach End-room\n", 2);
}

void		error_manager(int error)
{
	if (error == -1)
		perror("Error");
	else if (error <= -10)
		error_manager2(error);
	else if (error == -3)
		ft_putstr_fd("Error: Invalid links\n", 2);
	else if (error == -4)
		ft_putstr_fd("Error: Invalid rooms\n", 2);
	else if (error == -5)
		ft_putstr_fd("Error: Invalid number of ants\n", 2);
	else if (error == -6)
		ft_putstr_fd("Error: Invalid coordinates\n", 2);
	else if (error == -7)
		ft_putstr_fd("Error: Invalid start or end instrution\n", 2);
	else if (error == -8)
		ft_putstr_fd("Error: No coordinates\n", 2);
}
