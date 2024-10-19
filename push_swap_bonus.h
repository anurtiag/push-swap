/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:56:06 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:22:58 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "lib/ft_printf/libftprintf.h"
# include "lib/Libft/libft.h"
# include "lib/gnl/get_next_line.h"

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

//checker_bonus.c
int			is_sorted(t_dllist *list);
int			rptd_num(t_dllist *list);
void		make_movements(char	*line, t_dllist *stack_a, t_dllist *stack_b);
void		wrong_move(char	*line, t_dllist *stack_a, t_dllist *stack_b);
//operations1_bonus.c
void		swap(t_dllist *list, int mode);
void		double_swap(t_dllist *stack_a, t_dllist *stack_b);
void		push_node(t_dllist *src_list, t_dllist *dst_list, int mode);
void		rotate(t_dllist *list, int mode);
void		double_rotate(t_dllist *stack_a, t_dllist *stack_b);
//operations2_bonus.c
void		reverse_rotate(t_dllist *list, int mode);
void		double_reverse_rotate(t_dllist *stack_a, t_dllist *stack_b);
//utils_bonus.c
t_dllist	*prmt_handle(int argc, char **argv);
void		free_matrix(char **str);
void		errors(int error, int mode, t_dllist *list, char **matrix);
void		verify_nbr(long num, int *control);
int			ft_atoi_ps(const char *str, int *control);
//dll_utils_bonus.c
void		ft_rmvdll_node(t_dllist *list);
void		freedll(t_dllist *list);
t_dllist	*make_list(char **nums, int mode);
void		ft_add_dll_node(t_dllist *list, int content, int mode, char **nums);
void		ft_dll_new(t_dllist *list, int content, int mode, char **nums);

#endif