/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:53:34 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 23:42:51 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_table *table)
{
	t_ulong	i;

	i = 0;
	while (i <= table->forks_num)
	{
		pthread_mutex_init(&table->forks[i]->forks, NULL);
		i++;
	}
}

void	set_forks(t_philo *philo)
{
	philo->first_fork = philo->philo_id - 1;
	philo->second_fork = philo->philo_id - 2
		+ (philo->philo_id == 1) * philo->table->philos_num;
}

int	check_fork(int num, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[num]->forks);
	if (philo->table->forks[num]->key)
	{
		pthread_mutex_unlock(&philo->table->forks[num]->forks);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->forks[num]->forks);
	return (0);
}
