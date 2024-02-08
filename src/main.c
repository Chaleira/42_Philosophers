/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:18 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/23 23:31:25 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_table	table;

	table.start_time = get_time();
	if (check(argc, argv, &table))
		return (1);
	philo_create(&table);
	free_program(&table);
	return (0);
}
