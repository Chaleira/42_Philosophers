/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:54:27 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/12 20:31:12 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	actions(t_philo *philo)
{
	struct timeval	tv;
	static long int	ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_usec / 1000;
	printf("%ld ", ms);
	if (philo->status == DEAD)
		printf("%i died\n", philo->philo_id);
	else if (philo->status == SLEEP)
		printf("%i is sleeping\n", philo->philo_id);
	else if (philo->status == THINK)
		printf("%i is thinking\n", philo->philo_id);
	else if (philo->status == EAT)
		printf("%i is eating\n", philo->philo_id);
	else if (philo->status == FORK)
		printf("%i has taken a fork\n", philo->philo_id);
}
