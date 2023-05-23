/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:42:11 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 06:10:15 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_philo *philo)
{
	philo->status = DEAD;
	printf("%.5ld %i died\n", get_time() - philo->table->start_time,
		philo->philo_id);
	return ;
}

int	philo_sleep(t_philo *philo)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	philo->status = SLEEP;
	printf("%.5ld %i is sleeping\n", get_time() - philo->table->start_time,
		philo->philo_id);
	watch_sleep(philo->table->time_to_sleep, philo);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	philo->status = THINK;
	printf("%.5ld %i is thinking\n", get_time() - philo->table->start_time,
		philo->philo_id);
	usleep(150);
	return (0);
}

int	philo_eat(t_philo *philo, int num, int num2)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	philo->status = EAT;
	printf("%.5ld %i is eating\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->eat_times++;
	philo->forks_in_hand = 0;
	philo->last_eat = get_time();
	watch_sleep(philo->table->time_to_eat, philo);
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num + 1]);
	philo->table->forks_on_table += 2;
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num + 1]);
	pthread_mutex_unlock(&philo->table->forks[num]);
	pthread_mutex_unlock(&philo->table->forks[num2]);
	return (0);
}

int	philo_fork(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo->table->forks[philo->table->forks_num + 1]);
	while (philo->table->forks_on_table == 0)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num + 1]);
		if (table_service(philo) || am_i_dead(philo))
			return (1);
		usleep(10);
		pthread_mutex_lock(&philo->table->forks[philo->table->forks_num + 1]);
	}
	philo->table->forks_on_table--;
	pthread_mutex_unlock(&philo->table->forks[philo->table->forks_num + 1]);
	pthread_mutex_lock(&philo->table->forks[num]);
	if (!philo->status || table_service(philo) || am_i_dead(philo))
	{
		pthread_mutex_unlock(&philo->table->forks[num]);
		return (1);
	}
	printf("%.5ld %i has taken a fork\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->forks_in_hand++;
	return (0);
}
