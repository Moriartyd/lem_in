/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:37:19 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 22:01:58 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_len(int *arr)
{
	int len;

	len = 0;
	while (arr[len] != -1)
		len++;
	return (len);
}

static void	ft_swaptab(int **a, int **b)
{
	int	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		sort_array(int **arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ft_len(arr[i]) < ft_len(arr[j]))
				ft_swaptab(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}
