/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 16:25:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct	s_room
{
	int			x;
	int			y;
	char		*name;
	t_list		*link;
}				t_room;

typedef struct	s_lemin
{
	unsigned	ants;
	t_room		*start;
	t_room		*end;
}				t_lemin;

typedef struct	s_rooms
{

}				t_rooms;


#endif
