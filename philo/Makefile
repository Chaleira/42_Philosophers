# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 18:40:16 by plopes-c          #+#    #+#              #
#    Updated: 2023/05/09 19:54:31 by plopes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	./src/*.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes

CFLAGS = -g -Wall -Wextra -Werror $(INCLUDES)

RM = rm -fr

all : $(NAME)

$(NAME):		$(SRCS)
				@gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:			
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)