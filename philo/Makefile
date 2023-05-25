# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 18:40:16 by plopes-c          #+#    #+#              #
#    Updated: 2023/05/25 15:04:44 by plopes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	src/actions.c src/dinner.c src/forks.c src/main.c src/parsing.c \
		src/thread.c src/utils/utils2.c src/utils/utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

CFLAGS = -Wall -Wextra -Werror -pthread $(INCLUDES)

RM = rm -fr

all : $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:			
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)