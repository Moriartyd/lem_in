/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:59:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 18:20:28 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	t_lemin		*lem;

	argc = 0;
	if (!(lem = (t_lemin *)ft_memalloc(sizeof(t_lemin))))
		ft_putstr("Error: programm can't allocate memory\n");
	else
	{
		if ((argc = parse_input(lem, argv[1])) < 0 || check_startend(lem) == -1)
		{
			error_manager(lem, argc);
			mem_clean(lem);
			return (1);
		}
		else
		{
			if (check_startend(lem) == -1)
			{
				perror(argv[0]);
				mem_clean(lem);
				return (1);
			}
			bfs(lem);
			mem_clean(lem);
			return (0);
		}
	}
}
