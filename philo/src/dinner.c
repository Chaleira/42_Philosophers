/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:17 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/18 23:33:33 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	if ((philo->philo_id % 2))
		grab_fork_1(philo);
	else
		grab_fork_2(philo);
	while (philo->eat_times != philo->table->dinner_times && philo->status)
	{
		if (philo_fork(philo, philo->first_fork)
			|| philo_fork(philo, philo->second_fork)
			|| philo_eat(philo, philo->first_fork, philo->second_fork)
			|| philo_sleep(philo) || philo_think(philo))
			break ;
	}
	if (!philo->status)
		philo_dead(philo);
	return (NULL);
}

int	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num]);
	if (!philo->table->table_service)
		return (1);
	if ((get_time() - philo->last_eat) > philo->table->time_to_die)
	{
		philo->status = DEAD;
		philo->table->table_service = 0;
		pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
	return (0);
}

int	table_service(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num]);
	if (!philo->table->table_service)
		return (1);
	if (philo->eat_times == philo->table->dinner_times)
	{
		philo->table->table_service = 0;
		pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
	return (0);
}

void	watch_sleep(t_ulong time, t_philo *philo)
{
	t_ulong	start;

	start = get_time() * 1000;
	while (((get_time() * 1000) - start) < time
		&& !am_i_dead(philo) && !table_service(philo))
		usleep(1);
}
