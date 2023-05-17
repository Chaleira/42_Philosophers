/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:15 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/17 21:34:24 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define HERE write(1, "HERE\n", 5)
# define THERE write(1, "THERE\n", 6)

# define TE :

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
	t_ulong			last_eat;
	int				eat_times;
	int				philo_id;
	pthread_t		thread;

}				t_philo;

typedef struct s_table
{
	struct s_philo	**philo;
	t_ulong			forks_num;
	int				table_service;
	t_ulong			philos_num;
	t_ulong			time_to_die;
	t_ulong			time_to_eat;
	t_ulong			time_to_sleep;
	int				dinner_times;
	t_ulong			start_time;
	pthread_mutex_t	*forks;

}				t_table;

typedef struct s_list
{
	struct s_list	*next;
	void			*content;

}				t_list;

int		check(int argc, char **argv, t_table *table);
int		check_negative(int num);
int		check_digit(char *str);

int		philo_create(t_table *table);
int		philo_create_loop(t_table *table);
void	set_table(t_table *table, char **argv);
void	philos(t_table *table);

void	*dinner(void *arg);

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_program(t_table *table);

long	my_syscall(long number, long arg);
void	my_exit(int status);

// void	turns(t_philo *philo);
t_ulong	get_time(void);
void	forks_init(t_table *table);

void	philo_dead(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo, int num, int num2);
void	philo_fork(t_philo *philo, int num);
int		check_dead(t_philo *philo);
int		am_i_dead(t_philo *philo);
void	watch_sleep(t_ulong time, t_philo *philo);


#endif