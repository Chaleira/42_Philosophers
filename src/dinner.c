/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:17 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/31 17:06:19 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num]->forks);
	if (!philo->table->table_service)
	{
		pthread_mutex_unlock(&philo->table->forks
		[philo->table->forks_num]->forks);
		return (1);
	}
	else if ((get_time() - philo->last_eat) >= philo->table->time_to_die)
	{
		philo_dead(philo);
		philo->table->table_service = 0;
		pthread_mutex_unlock(&philo->table->forks
		[philo->table->forks_num]->forks);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]->forks);
	return (0);
}

int	table_service(t_philo *philo)
{
	if (philo->eat_times == philo->table->dinner_times)
	{
		return (1);
	}
	return (0);
}

void	watch_sleep(t_ulong time, t_philo *philo)
{
	t_ulong	start;

	start = get_time();
	while (((get_time()) - start) < time
		&& !am_i_dead(philo) && !table_service(philo))
		usleep(150);
}

static int	dinner_aux(t_philo *philo)
{
	if (philo_fork(philo, philo->first_fork)
		|| philo_fork(philo, philo->second_fork)
		|| philo_eat(philo, philo->first_fork, philo->second_fork)
		|| philo_sleep(philo))
		return (1);
	return (0);
}

void	*dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	if ((philo->philo_id % 2))
		usleep(500);
	while (philo->status && philo->eat_times != philo->table->dinner_times)
	{
		if (dinner_aux(philo))
			break ;
	}
	return (NULL);
}
