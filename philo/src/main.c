/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:18 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/12 16:25:06 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_table	table;

	if (check(argc, argv, &table))
		return (1);
	philo_create(&table);
	free_program(&table);
	return (0);
}

// printf("Num Philos: %lu\nTime to die: %lu\nTime to eat: %lu\n"
// "Time to sleep: %lu\nNum times: %lu\n", table.philos_num,
// table.time_to_die, table.time_to_eat, table.time_to_sleep,
	// table.dinner_times);