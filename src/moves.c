/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:25:43 by adavis            #+#    #+#             */
/*   Updated: 2019/10/01 14:13:25 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// t_ant	*create_ants(t_lemin *lem)
// {
// 	t_ant	ants[lem->ants];
// 	int		i;

// 	i = -1;
// 	while (++i < lem->ants)
// 	{
// 		ants[i].room = lem->start->index;
// 		ants[i].path = -1;
// 	}
// 	return (ants);
// }

// int		ants_remaining(t_ant *ants, t_lemin *lem)
// {
// 	int		i;
// 	int		cnt;

// 	cnt = 0;
// 	i = -1;
// 	while (i < lem->ants)
// 		if (ants[i].room != lem->end->index)
// 			cnt++;
// 	return (cnt);
// }

// void	move_ants(int **paths, t_lemin *lem)
// {
// 	t_ant	*ants;
// 	int		i;
// 	int		j;

// 	ants = create_ants(lem);
// 	i = 0;
// 	while (ants_remaining(ants, lem))
// 	{
// 		j = -1;
// 	}
// }

int		*init_weights(int cnt)
{
	int		*weights;
	int		i;

	weights = (int *)malloc(sizeof(int) * cnt);
	i = -1;
	while (++i < cnt)
	{
		weights[i] = 0;
	}
	return (weights);
}

int		weigh_path(int **paths, t_lemin *lem, int ind, int len)
{
	int		i;
	int		weight;

	weight = 0;
	i = -1;
	while (++i < ind)
		weight += len - pathlen(lem, paths[i][0]);
	return (weight);
}

int		*weigh_paths(int **paths, t_lemin *lem)
{
	int		*weights;
	int		i;

	weights = init_weights(pathscnt(lem));
	i = -1;
	while (++i < pathscnt(lem))
		weights[i] = weigh_path(paths, lem,  i, pathlen(lem, paths[i][0]));
	return (weights);
}
