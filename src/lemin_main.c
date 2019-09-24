/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:59:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/24 15:02:11 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	t_lemin		*lem;

	lem = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	argc = 0;
	if (parse_input(lem, argv[1]) == -1)
	{
		perror(argv[0]);
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
