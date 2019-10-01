/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:36:21 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 15:39:16 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*init_weights(int cnt)
{
	int		*weights;
	int		i;

	if (!(weights = (int *)malloc(sizeof(int) * cnt)))
        return (NULL);
	i = -1;
	while (++i < cnt)
	{
		weights[i] = 0;
	}
	return (weights);
}

int     *remove_weights(int **w)
{
    if (w && *w)
    {
        free(*w);
        *w = NULL;
    }
    return (NULL);
}
