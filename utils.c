/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:48:47 by anurtiag          #+#    #+#             */
/*   Updated: 2024/02/02 12:07:48 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errors(int error, int mode, t_dllist *list, char **matrix)
{
	if (mode == 1)
		free_matrix(matrix);
	if (list)
		freedll(list);
	if (error == NO_PRMT)
		exit(EXIT_FAILURE);
	else if (error == STDR_ERROR)
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	verify_nbr(long num, int *control)
{
	if (num < INT_MIN || num > INT_MAX)
		*control = FALSE;
}

void	free_matrix(char **str)
{
	size_t	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

int	ft_atoi_ps(const char *str, int *control)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || ft_strlen(str) == 0 || (str[i] == '\0'\
	&& (str[i - 1] == '-' || str[i - 1] == '+')))
		*control = FALSE;
	num = num * sign;
	verify_nbr(num, control);
	return (num);
}

t_dllist	*prmt_handle(int argc, char **argv)
{
	t_dllist	*list;
	char		**nums;

	list = NULL;
	if (argc == 1)
		errors(NO_PRMT, 0, NULL, NULL);
	else if (argc == 2)
	{
		nums = ft_split (argv[1], SPACE);
		list = make_list(nums, 1);
		free_matrix(nums);
	}
	else
		list = make_list((argv + 1), 0);
	return (list);
}
