/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:08 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:21:06 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "lib/ft_printf/libftprintf.h"
# include "lib/Libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SPACE 32
# define NO_PRMT 0
# define STDR_ERROR 1
# define FALSE 0
# define TRUE 1
# define A 0
# define B 1
# define NOTHING 3

typedef struct s_dllist
{
	int				size;
	struct s_node	*first;
	struct s_node	*last;
	struct s_node	*cheapest;

}				t_dllist;

typedef struct s_node
{
	int				num;
	int				index;
	int				pos;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}				t_node;

//push_swap.c
void		stack_of_three(t_dllist	*list, int mode);
void		push_to_b(t_dllist *stack_a, t_dllist *stack_b);
void		push_to_a(t_dllist *stack_a, t_dllist *stack_b, t_node *node);
void		push_swap(t_dllist *stack_a, t_dllist *stack_b);
//operations1.c
void		swap(t_dllist *list, int mode);
void		double_swap(t_dllist *stack_a, t_dllist *stack_b);
void		push_node(t_dllist *src_list, t_dllist *dst_list, int mode);
void		rotate(t_dllist *list, int mode);
void		double_rotate(t_dllist *stack_a, t_dllist *stack_b);
//operations2.c
void		reverse_rotate(t_dllist *list, int mode);
void		double_reverse_rotate(t_dllist *stack_a, t_dllist *stack_b);
void		put_node_first(t_dllist *list, t_node *node, int mode);
void		put_nodes_first(t_node *node_a, t_dllist *stack_a, \
t_node *node_b, t_dllist *stack_b);
//target.c
void		cheapest_cal(t_dllist *stack_a, t_dllist *stack_b);
void		cost_cal(t_node	*node, int node_list, int target_list);
void		find_target(t_node *node, t_dllist *list);
void		set_pos(t_dllist *list);
void		diff_index_cost_cal(t_node	*node, int node_list, int target_list);
//utils.c
t_dllist	*prmt_handle(int argc, char **argv);
void		free_matrix(char **str);
void		errors(int error, int mode, t_dllist *list, char **matrix);
void		verify_nbr(long num, int *control);
int			ft_atoi_ps(const char *str, int *control);
//utils2.c
t_node		*max_number(t_dllist *list, int limiter);
t_node		*min_number(t_dllist *list, int limiter);
int			is_sorted(t_dllist *list);
int			rptd_num(t_dllist *list);
void		below_midlist(t_node *node, int size);
//dll_utils.c
void		ft_rmvdll_node(t_dllist *list);
void		freedll(t_dllist *list);
t_dllist	*make_list(char **nums, int mode);
void		ft_add_dll_node(t_dllist *list, int content, int mode, char **nums);
void		ft_dll_new(t_dllist *list, int content, int mode, char **nums);

#endif