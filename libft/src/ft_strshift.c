/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:32:52 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:59:16 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char **str, size_t n)
{
	char *res;

	if (!str || !*str)
		return (NULL);
	res = ft_strsub(*str, n, ft_strlen(*str) - n);
	if (!res)
		return (NULL);
	ft_strdel(str);
	return (res);
}
