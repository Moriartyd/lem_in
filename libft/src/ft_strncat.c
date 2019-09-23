/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:11:13 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/16 20:58:52 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *restrict	ret;
	size_t			i;

	i = 0;
	ret = s1;
	while (*s1)
		s1++;
	while (i < n && *s2)
	{
		*s1 = (char)*s2;
		s1++;
		s2++;
		i++;
	}
	*s1 = '\0';
	return (ret);
}
