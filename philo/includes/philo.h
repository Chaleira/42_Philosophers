/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:15 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 23:48:12 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

// # define HERE write(1, "HERE\n", 5)
// # define THERE write(1, "THERE\n", 6)

# define DEAD	0
# define SLEEP	1
# define THINK	2
# define EAT	3

typedef unsigned long int	t_ulong;

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		thread;
	t_ulong			last_eat;
	int				status;
	int				first_fork;
	int				second_fork;
	int				eat_times;
	int				philo_id;
	int				forks_in_hand;

}				t_philo;

typedef struct s_fork
{
	int				key;
	pthread_mutex_t	forks;

}				t_fork;

typedef struct s_table
{
	t_fork			**forks;
	struct s_philo	**philo;
	t_ulong			start_time;
	t_ulong			forks_num;
	t_ulong			philos_num;
	t_ulong			time_to_die;
	t_ulong			time_to_eat;
	t_ulong			time_to_sleep;
	int				table_service;
	int				dinner_times;
	int				forks_on_table;

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
void	set_table(t_table *table, char **argv);
void	philos(t_table *table);

void	*dinner(void *arg);

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_program(t_table *table);

t_ulong	get_time(void);
void	forks_init(t_table *table);

void	philo_dead(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_eat(t_philo *philo, int num, int num2);
int		philo_fork(t_philo *philo, int num);
int		am_i_dead(t_philo *philo);
void	watch_sleep(t_ulong time, t_philo *philo);
void	set_fork_right_first(t_philo *philo);
void	set_fork_left_first(t_philo *philo);
int		table_service(t_philo *philo);
void	set_forks(t_philo *philo);
int		check_fork(int num, t_philo *philo);

#endif