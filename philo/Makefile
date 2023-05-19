# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 18:40:16 by plopes-c          #+#    #+#              #
#    Updated: 2023/05/19 19:44:43 by plopes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	src/*.c src/*/*.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

CFLAGS = -Wall -Wextra -Werror -pthread $(INCLUDES) -g -fsanitize=thread 

RM = rm -fr

all : $(NAME)

$(NAME):		$(SRCS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

run:			all
				./philo 5 450 200 800

clean:			
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)