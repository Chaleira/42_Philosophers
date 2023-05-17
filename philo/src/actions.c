/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:54:27 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/17 18:52:04 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	turns(t_philo *philo)
// {
// 	if (philo->table->forks_num >= 1 && philo->status != EAT)
// 	{
// 		philo->table->forks_num -= 1;
// 		philo->status = FORK;
// 	}
// 	else if (philo->status == FORK && philo->forks == 2)
// 		philo->status = EAT;
// 	else if (philo->status == EAT)
// 	{
// 		philo->forks = 0;
// 		philo->table->forks_num += 2;
// 		philo->status = SLEEP;
// 	}
// 	else if (philo->status == SLEEP)
// 		philo->status = THINK;
// 	else if (philo->status == THINK)
// 		philo->status = EAT;
// 	actions(philo);
// 	usleep(50000);
// }
