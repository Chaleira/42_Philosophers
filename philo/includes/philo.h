/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:15 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/09 19:43:52 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	struct s_table	*table;
	int				test;

}				t_philo;

typedef struct s_table
{
	struct s_philo	*philo;

}				t_table;

typedef struct s_list
{
	struct s_list	*next;
	void	*content;

}				t_list;

void	print_test(void);

#endif