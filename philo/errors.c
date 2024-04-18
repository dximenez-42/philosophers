/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:14:11 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/18 10:46:45 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_error(void)
{
	printf("Input error.\n");
}

void	cleanup(t_program *p, int c)
{
	size_t	i;

	i = 0;
	if (c)
		return (exit(1));
	while (i < p->philo_size)
	{
		pthread_mutex_lock(&p->philos[i].pause);
		pthread_mutex_lock(&p->forks[i]);
		p->philos[i].pr = NULL;
		++i;
	}
	pthread_mutex_lock(&p->write_lock);
	return (exit(1));
}
