/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:17 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:17:58 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	actions(t_philo *philo)
{
	if (philo->status == DEAD)
		philo_died(philo);
	else if (philo->status == SLEEP)
		philo_sleep(philo);
	else if (philo->status == THINK)
		philo_think(philo);
	else if (philo->status == EAT)
		philo_eat(philo);
	else if (philo->status == FORK)
		philo_take_fork(philo);
}
