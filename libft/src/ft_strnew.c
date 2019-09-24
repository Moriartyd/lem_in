/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:00:53 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/07/24 18:26:58 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	check;

	check = 0;
	if (size == check - 1)
		return (NULL);
	array = ft_memalloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	array[size] = 0;
	return (array);
}
