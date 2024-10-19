# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 11:46:43 by anurtiag          #+#    #+#              #
#    Updated: 2024/02/02 10:05:41 by anurtiag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

LIBFT			=	./lib/Libft

PRINTF			= 	./lib/ft_printf

GNL				=	./lib/gnl

LIBS			=	$(LIBFT)/libft.a $(PRINTF)/libftprintf.a

LIBS_BONUS		=	$(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(GNL)/gnl.a

HEADERS			=	-I $(LIBFT) -I $(PRINTF)

HEADERS_BONUS	=	-I $(LIBFT) -I $(PRINTF) -I $(GNL)

SRCS			=	push_swap.c utils.c utils2.c dll_utils.c operations1.c operations2.c target.c

SRCS_BONUS		=	checker_bonus.c utils_bonus.c dll_utils_bonus.c operations1_bonus.c operations2_bonus.c

OBJ				=	$(SRCS:.c=.o)

OBJ_BONUS		=	$(SRCS_BONUS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror 

RM				=	rm -rf



all:			$(NAME)

$(NAME):		libft printf $(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

bonus:			libft printf gnl $(OBJ)
				@$(CC) -g $(CFLAGS) -c $(SRCS_BONUS) $(HEADERS_BONUS)
				@$(CC) -g $(CFLAGS) $(OBJ_BONUS) $(LIBS_BONUS) -o $(NAME_BONUS)

libft:
				@$(MAKE) -C $(LIBFT)
printf:
				@$(MAKE) -C  $(PRINTF)
gnl:
				@$(MAKE) -C  $(GNL)
clean:
				@$(RM) $(OBJ)
				@$(RM) $(OBJ_BONUS)
				@$(MAKE) -C $(LIBFT) clean
				@$(MAKE) -C $(PRINTF) clean
				@$(MAKE) -C $(GNL) clean

fclean:			clean
				@$(MAKE) -C $(LIBFT) fclean
				@$(MAKE) -C $(PRINTF) fclean
				@$(MAKE) -C $(GNL) fclean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft printf gnl