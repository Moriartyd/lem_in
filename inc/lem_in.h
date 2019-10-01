/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 14:22:43 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct		s_room
{
	char			*name;
	int				index;
	int				level;
	int				x;
	int				y;
	int				in;
	int				out;

}					t_room;

typedef struct		s_rooms
{
	t_room			*room;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

typedef struct		s_lemin
{
	int				ants;
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

typedef struct 		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_ant
{
	int				path;
	int				room;
}					t_ant;


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
void				set_coord(t_room *room, char *line);
int					valid_room(t_room *room1, t_room *room2);
t_room				*find_room_ind(int ind, t_lemin *lem);
void				parse_link(char *str, t_lemin *lem, int *stat);
t_room				*rm_room(t_room *room);
t_rooms				*rm_rooms(t_rooms *head);
void				mem_clean(t_lemin *lem);
int					check_startend(t_lemin *lem);
int					check_lem(t_lemin *lem);

void				push_queue(t_queue **queue, int index);
int					pop_queue(t_queue **queue);

void				bfs(t_lemin *lem);

t_stack				*init_stack(int nbr);
void				push_stack(t_stack **s, int nbr);
int					read_stack(t_stack *s);
int					pop_stack(t_stack **s);
t_rooms				*find_final_room(t_lemin *lem);

int					pathlen(t_lemin *lem, int index);

void				remove_links(t_lemin *lem);

void				remove_input_forks(t_lemin *lem);
void				remove_input_forks_dumb(t_lemin *lem);
void				remove_output_forks(t_lemin *lem);

int					q_len(t_queue *q);
void				create_paths(t_lemin *lem);
void				error_manager(t_lemin *lem, int error);

int					remove_from_smezh(t_room *room, t_lemin *lem);
t_rooms				*is_same_lvl(int lvl, t_rooms *head);
void				sort_array(int **arr, int len);

int					pathscnt(t_lemin *lem);
int					*weigh_paths(int **paths, t_lemin *lem);
void				move_ants(int **paths, int *weights, t_lemin *lem);

#endif
