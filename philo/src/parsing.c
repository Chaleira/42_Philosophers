/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:29:00 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/11 03:51:14 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_negative(int num)
{
	if (num == 0)
		return (printf("Error\nNo value can be zero\n"));
	if (num < 0)
		return (printf("Error\nCan't have negative numbers\n"));
	return (0);
}

int	check_digit(char *str)
{
	int	i;

	if (!str || !str[0])
		return (printf("Error\nInavlid character found\n"));
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-'))
			return (printf("Error\nInavlid character found\n"));
		i++;
	}
	return (0);
}

int	check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 6 && argc != 5)
		return (printf("Error\nUsage: <number_of_philosophers> "
				"<time_to_die> <time_to_eat> <time_to_sleep> "
				"<number_of_times_each_philosopher_must_eat(optional)>\n"));
	while (argv[i])
	{
		if (check_digit(argv[i]) || check_negative(ft_atoi(argv[i])))
			return (1);
		i++;
	}
	return (0);
}
