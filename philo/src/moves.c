/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:42:11 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/18 23:33:01 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_philo *philo)
{
	printf("%.5ld %i died\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->status = DEAD;
	return ;
}

int	philo_sleep(t_philo *philo)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	printf("%.5ld %i is sleeping\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->status = SLEEP;
	watch_sleep(philo->table->time_to_sleep * 1000, philo);
	// usleep(philo->table->time_to_sleep * 1000);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	philo->status = THINK;
	printf("%.5ld %i is thinking\n", get_time() - philo->table->start_time,
		philo->philo_id);
	usleep(500);
	return (0);
}

int	philo_eat(t_philo *philo, int num, int num2)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	printf("%.5ld %i is eating\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->status = EAT;
	philo->eat_times++;
	philo->last_eat = get_time();
	watch_sleep(philo->table->time_to_eat * 1000, philo);
	// usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->table->forks[num]);
	pthread_mutex_unlock(&philo->table->forks[num2]);
	return (0);
}

int	philo_fork(t_philo *philo, int num)
{
	if (!philo->status || table_service(philo) || am_i_dead(philo))
		return (1);
	printf("%.5ld %i has taken a fork\n", get_time() - philo->table->start_time,
		philo->philo_id);
	philo->status = FORK;
	pthread_mutex_lock(&philo->table->forks[num]);
	return (0);
}
