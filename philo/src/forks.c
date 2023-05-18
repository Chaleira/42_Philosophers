/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:53:34 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/18 23:31:59 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_table *table)
{
	t_ulong	i;

	i = 0;
	while (i <= table->forks_num)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	grab_fork_1(t_philo *philo)
{
	philo->first_fork = philo->philo_id - 1;
	philo->second_fork = philo->philo_id - 2
		+ (philo->philo_id == 1) * philo->table->philos_num;
	philo_think(philo);
}

void	grab_fork_2(t_philo *philo)
{
	philo->first_fork = philo->philo_id - 2
		+ (philo->philo_id == 1) * philo->table->philos_num;
	philo->second_fork = philo->philo_id - 1;
}
