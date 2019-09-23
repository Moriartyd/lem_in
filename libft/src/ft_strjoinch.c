/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:48:24 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 20:17:32 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char **str, char c)
{
	char	*res;

	if (!str || !(*str))
		return (NULL);
	res = ft_strnew(ft_strlen(*str) + 1);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, *str);
	res = ft_strncat(res, &c, 1);
	free(*str);
	*str = NULL;
	return (res);
}
