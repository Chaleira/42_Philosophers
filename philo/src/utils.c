/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:29 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/11 03:34:43 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	philo_create(t_table *table)
// {
// 	t_ulong	i;

// 	i = 0;
// 	while (i++ < table->philos_num)
// 		pthread_create(table->philo[i]->tread, NULL, dinner, table);
// }

// void	*dinner(void *arg)
// {
// 	t_philo	*philo;
// 	(void)arg;
// 	philo = (t_philo *)arg;
// 	return (NULL);
// }

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	nbr;

	i = 0;
	s = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = nptr[i] - '0' + nbr * 10;
		i++;
	}
	return (nbr * s);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
