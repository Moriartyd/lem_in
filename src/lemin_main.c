/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:59:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 20:31:06 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include <errno.h>

int	main(int ac, char **argv)
{
	t_lemin		*lem;

	ac = 0;
	if (!(lem = (t_lemin *)ft_memalloc(sizeof(t_lemin))))
		ft_putstr_fd("Error: programm can't allocate memory\n", 2);
	else
	{
		if ((ac = parse_input(lem, argv[1])) < 0 || check_startend(lem) == -1)
		{
			check_startend(lem) < 0 ? perror("Error") : error_manager(lem, ac);
			mem_clean(lem);
		}
		else
		{
			bfs(lem);
			mem_clean(lem);
		}
	}
	return (0);
}
