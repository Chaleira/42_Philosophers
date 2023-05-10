/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:54:27 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:07:04 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_died(t_philo	*philo)
{
	printf("%i died\n", philo->philo_id);
}

void	philo_sleep(t_philo *philo)
{
	printf("%i is sleeping\n", philo->philo_id);
}

void	philo_think(t_philo	*philo)
{
	printf("%i is thinking\n", philo->philo_id);
}

void	philo_eat(t_philo	*philo)
{
	printf("%i is eating\n", philo->philo_id);
}

void	philo_take_fork(t_philo	*philo)
{
	printf("%i has taken a fork\n", philo->philo_id);
}
