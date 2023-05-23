/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:43:15 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 22:08:32 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_create(t_table *table)
{
	t_ulong	i;

	i = 0;
	while (i < table->philos_num)
	{
		if (pthread_create(&table->philo[i]->thread, NULL,
				dinner, table->philo[i]))
			return (printf("Error\nCouldn't create the philos"));
		i++;
	}
	i = 0;
	while (i < table->philos_num)
	{
		if (pthread_join(table->philo[i]->thread, 0))
			return (printf("Error\nCouldn't join philos\n"));
		i++;
	}
	return (0);
}

void	philos(t_table *table)
{
	t_ulong		i;

	table->philo = ft_calloc(table->philos_num, sizeof(t_philo *));
	table->forks = ft_calloc(table->forks_num + 1, sizeof(t_fork *));
	i = 0;
	while (i < table->philos_num)
	{
		table->philo[i] = ft_calloc(1, sizeof(t_philo));
		table->philo[i]->table = table;
		table->philo[i]->philo_id = i + 1;
		table->philo[i]->status = 1;
		set_forks(table->philo[i]);
		i++;
	}
	i = 0;
	while (i <= table->forks_num)
	{
		table->forks[i] = ft_calloc(1, sizeof(t_fork));
		table->forks[i]->key = 1;
		i++;
	}
}

void	set_table(t_table *table, char **argv)
{
	table->forks_num = ft_atoi(argv[1]);
	table->philos_num = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->dinner_times = ft_atoi(argv[5]);
	if (!argv[5])
		table->dinner_times = -1;
	table->table_service = 1;
	table->forks_on_table = table->philos_num;
	philos(table);
	forks_init(table);
}
