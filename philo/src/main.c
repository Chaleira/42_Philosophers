/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:18 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 22:52:35 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_table	table;

	table.start_time = get_time();
	if (check(argc, argv, &table))
		return (1);
	if (table.philos_num == 1)
	{
		printf("%.5ld %i has taken a fork\n", get_time() - table.start_time, 1);
		usleep(table.time_to_die * 1000);
		printf("%.5ld %i died\n", get_time() - table.start_time, 1);
		return (0);
	}
	philo_create(&table);
	free_program(&table);
	return (0);
}
