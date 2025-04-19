/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:48:47 by anurtiag          #+#    #+#             */
/*   Updated: 2025/04/19 13:25:45 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ls_init(t_ls_options *ls) {
	(*ls).file_list = NULL;
	(*ls).a_option = false;
	(*ls).r_option = false;
	(*ls).R_option = false;
	(*ls).l_option = false;
	(*ls).t_option = false;
}

int main(int argc, char **argv, char **env) {
	t_ls_options ls;
	ls_init(&ls);
	
}