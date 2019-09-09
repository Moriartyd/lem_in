/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:45:49 by jleann            #+#    #+#             */
/*   Updated: 2019/09/09 17:30:02 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_string.h"
# include "ft_list.h"
# include "ft_io.h"
# ifndef LONG_MAX
#  define LONG_MAX	9223372036854775807L
# endif
# ifndef LONG_MIN
#  define LONG_MIN	(-LONG_MAX -1L)
# endif
# ifndef ULONG_MAX
#  define ULONG_MAX	(LONG_MAX *2UL+1UL)
# endif
#endif
