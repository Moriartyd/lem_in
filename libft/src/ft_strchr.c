/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:24:15 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:57:44 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char*)s != (unsigned char)c && *s)
		s++;
	if (*(unsigned char*)s != (unsigned char)c)
		return (NULL);
	else
		return ((char*)s);
}
