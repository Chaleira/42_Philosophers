/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:17 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 06:05:00 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num]);
	if (!philo->table->table_service)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
		return (1);
	}
	else if ((get_time() - philo->last_eat) >= philo->table->time_to_die)
	{
		philo_dead(philo);
		philo->table->table_service = 0;
		pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num]);
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
		usleep(1);
}

static int	dinner_aux(t_philo *philo)
{
	if (!philo->forks_in_hand)
	{
		if (philo_fork(philo, philo->first_fork))
			return (1);
	}
	else if (philo->forks_in_hand == 1)
	{
		if (philo_fork(philo, philo->second_fork))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->first_fork]);
			return (1);
		}
	}
	else if (philo->forks_in_hand == 2)
	{
		if (philo_eat(philo, philo->first_fork, philo->second_fork))
		{
			pthread_mutex_unlock(&philo->table->forks[philo->first_fork]);
			pthread_mutex_unlock(&philo->table->forks[philo->second_fork]);
			return (1);
		}	
		if (philo_sleep(philo) || philo_think(philo))
			return (1);
	}
	return (0);
}

void	*dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	grab_fork(philo);
	while (philo->status && philo->eat_times != philo->table->dinner_times)
	{
		if (dinner_aux(philo))
			break ;
	}
	return (NULL);
}
