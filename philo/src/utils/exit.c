/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:20:44 by plopes-c          #+#    #+#             */
/*   Updated: 2023/05/12 20:30:22 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	my_syscall(long number, long arg)
{
	long	result;

	asm volatile (
		"mov %1, %%rax;\n\t"
		"mov %2, %%rdi;\n\t"
		"syscall;\n\t"
		"mov %%rax, %0;"
		TE "=r"(result)
		TE "r"(number),
		"r"(arg)
		TE "rax", "rdi"
	);
	return (result);
}

void	my_exit(int status)
{
	my_syscall(60, status);
}
