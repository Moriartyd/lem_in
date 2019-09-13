/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:59:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/13 18:33:56 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_lemin		*lem;

	lem = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	argc = 0;
	parse_input(lem, argv[1]);
	print_nodes(lem->list);
	printf("\n");
	for (int i = 0; i < lem->size;i++)
	{
		for (int j = 0; j < lem->size; j++)
			printf("%i ", lem->smezh[i][j]);
		printf("\n");
	}
	return (0);
}
