/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:29:00 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/10 20:48:07 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_negative(int num)
{
	if (num <= 0)
		return (1);
	return (0);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i++])
	{
		if (str[i] < 0 || str[i] > 9)
			return (1);
	}
	return (0);
}

int	check(int argc, char **argv)
{
	(void)argv;
	if (argc != 6 && argc != 5)
		return (printf("Error\nUsage: <number_of_philosophers> "
				"<time_to_die> <time_to_eat> <time_to_sleep> "
				"<number_of_times_each_philosopher_must_eat(optional)>\n"));
	return (0);
}
