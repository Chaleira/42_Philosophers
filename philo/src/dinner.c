/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:17 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/17 22:10:40 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo			*philo;
	int				first;
	int				second;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	if ((philo->philo_id % 2))
	{
		first = philo->philo_id - 1;
		second = philo->philo_id - 2
			+ (philo->philo_id == 1) * philo->table->philos_num;
		philo_think(philo);
	}
	else
	{
		first = philo->philo_id - 2
			+ (philo->philo_id == 1) * philo->table->philos_num;
		second = philo->philo_id - 1;
	}
	while (philo->eat_times != philo->table->dinner_times && philo->status)
	{
		philo_fork(philo, first);
		philo_fork(philo, second);
		philo_eat(philo, first, second);
		philo_sleep(philo);
		philo_think(philo);
	}
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num]);
	philo->table->table_service = 0;
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
	if (!philo->status)
		philo_dead(philo);
	philo->status = DEAD;
	return (NULL);
}

int	check_dead(t_philo *philo)
{
	t_ulong	i;

	i = 0;
	while (i < philo->table->philos_num)
	{
		if (!philo->table->philo[i]->status)
		{
			pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num]);
	if (!philo->table->table_service)
	{
		philo->status = 0;
		return (pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]) * 0 + 1);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
	if ((get_time() - philo->last_eat) > philo->table->time_to_die)
	{
		philo->status = DEAD;
		return (1);
	}
	return (0);
}

void	watch_sleep(t_ulong time, t_philo *philo)
{
	t_ulong	start;

	start = get_time();
	while ((get_time() - start) < time
		&& !am_i_dead(philo))
		usleep(200);
}
