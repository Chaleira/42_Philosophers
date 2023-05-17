/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:42:11 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/17 22:13:42 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_philo *philo)
{
	philo->status = DEAD;
	printf("%.5ld %i died\n", get_time() - philo->table->start_time, philo->philo_id);
	return ;
}

void	philo_sleep(t_philo *philo)
{
	if (am_i_dead(philo) || !philo->table->table_service)
		return ;
	philo->status = SLEEP;
	printf("%.5ld %i is sleeping\n", get_time() - philo->table->start_time, philo->philo_id);
	watch_sleep(philo->table->time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	if (am_i_dead(philo) || !philo->table->table_service)
		return ;
	philo->status = THINK;
	printf("%.5ld %i is thinking\n", get_time() - philo->table->start_time, philo->philo_id);
	usleep(200);
}

void	philo_eat(t_philo *philo, int num, int num2)
{
	if (am_i_dead(philo) || !philo->table->table_service)
		return ;
	philo->status = EAT;
	philo->eat_times++;
	printf("%.5ld %i is eating\n", get_time() - philo->table->start_time, philo->philo_id);
	philo->last_eat = get_time();
	watch_sleep(philo->table->time_to_eat, philo);
	pthread_mutex_unlock(&philo->table->forks[num]);
	pthread_mutex_unlock(&philo->table->forks[num2]);
}

void	philo_fork(t_philo *philo, int num)
{
	if (am_i_dead(philo) || !philo->table->table_service)
		return ;
	philo->status = FORK;
	pthread_mutex_lock(&philo->table->forks[num]);
	printf("%.5ld %i has taken a fork\n", get_time() - philo->table->start_time, philo->philo_id);
}
