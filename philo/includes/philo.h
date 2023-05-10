/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:15 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:46:33 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

# define HERE write(1, "HERE\n", 5)
# define THERE write(1, "THERE\n", 6)

# define DEAD	0
# define SLEEP	1
# define THINK	2
# define EAT	3
# define FORK	4

typedef unsigned long int	t_ulong;

typedef struct s_philo
{
	struct s_table	*table;
	int				status;
	int				philo_id;
	pthread_t		tread;

}				t_philo;

typedef struct s_table
{
	struct s_philo	**philo;
	t_ulong			forks_num;
	t_ulong			philos_num;
	t_ulong			time_to_die;
	t_ulong			time_to_sleep;
	t_ulong			time_to_eat;
	t_ulong			dinner_times;

}				t_table;

typedef struct s_list
{
	struct s_list	*next;
	void			*content;

}				t_list;

void	philo_died(t_philo	*philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo	*philo);
void	philo_eat(t_philo	*philo);
void	philo_take_fork(t_philo	*philo);
void	actions(t_philo *philo);
void	philo_create(t_table *table);
void	*dinner(void *arg);
int		check(int argc, char **argv);



#endif