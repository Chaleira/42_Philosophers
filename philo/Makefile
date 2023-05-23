# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 18:40:16 by plopes-c          #+#    #+#              #
#    Updated: 2023/05/23 06:16:02 by plopes-c         ###   ########.fr        #
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
				# ./philo 1 800 200 200 #morte
					./philo 4 310 200 100 #morte
					# ./philo 5 800 200 200 #vive
					# ./philo 5 800 200 200 7 #vive
					# ./philo 4 410 200 200 #vive
				

clean:			
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)