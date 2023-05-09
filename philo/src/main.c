/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:18 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/09 19:45:19 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	int x;

	(void)argc;
	(void)argv;
	t_philo philo;
	t_table table;
	philo.table = &table;
	table.philo = &philo;
	philo.table->philo->table->philo->test = 5;
	x = 1;
	printf("This is x: %i\n", x);
	while (x++ < 20)
		printf("This is x: %i\n", x);
	printf("TEST : %i\n", philo.test);
	return (0);
}
