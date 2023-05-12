/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:29 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/12 11:16:17 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_bzero(void *s, int n)
{
	char	*p;
	int		i;

	p = s;
	i = 0;
	while (n > i)
	{
		p[i] = '\0';
		i++;
	}
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(size * nmemb);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

void	free_program(t_table *table)
{
	t_ulong	i;

	i = 0;
	while (i < table->philos_num)
	{
		free(table->philo[i]);
		i++;
	}
	free(table->philo);
}
