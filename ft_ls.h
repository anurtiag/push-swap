/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:08 by anurtiag          #+#    #+#             */
/*   Updated: 2025/04/19 13:23:23 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
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

typedef struct s_ls_options
{
	bool			r_option;
    bool            R_option;
    bool            a_option;
    bool            t_option;
    bool            l_option;
	struct s_list	*file_list;
}	t_ls_options;

#endif