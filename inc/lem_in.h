/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/24 14:43:36 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"


typedef struct		s_room
{
	char			*name;
	int				index;
	int				visit;
	int				level;
}					t_room;

typedef struct		s_rooms
{
	t_room			*room;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

typedef struct		s_lemin
{
	unsigned		ants;
	t_room			*start;
	t_rooms			*list;
	t_room			*end;
	int				size;
	int				**smezh;
}					t_lemin;

typedef struct		s_queue
{
	int				index;
	struct s_queue	*next;
}					t_queue;


int					parse_input(t_lemin *lem, char *name);
int					what_parse(char *line, t_lemin *lem,
						int *p, char **addline);
void				sort_nodes(t_rooms *head);
void				print_nodes(t_rooms *head);
t_rooms				*add_rooms(t_rooms *src, t_room *room);
t_rooms				*init_rooms(void);
t_rooms				*create_firstrooms(t_room *room);
t_room				*create_room(size_t size, int *ind);
t_rooms				*find_room(const char *name, t_lemin *lem);
void				parse_link(char *str, t_lemin *lem, int *stat);
t_room				*rm_room(t_room *room);
t_rooms				*rm_rooms(t_rooms *head);
void				mem_clean(t_lemin *lem);
int					check_startend(t_lemin *lem);

void				push_queue(t_queue **queue, int index);
int					pop_queue(t_queue **queue);

void				bfs(t_rooms *rooms, t_room *start);

#endif
