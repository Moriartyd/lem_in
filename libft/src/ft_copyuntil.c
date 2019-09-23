/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:28:48 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:55:07 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copyuntil(const char *str, int c)
{
	char *res;
	char *sym;

	if (!str)
		return (NULL);
	sym = ft_strchr(str, c);
	if (!sym)
		return (NULL);
	res = ft_strnew(sym - str);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, str, sym - str);
	return (res);
}
