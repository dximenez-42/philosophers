/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:51:23 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/14 20:07:09 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*alive_checker(void *p)
{
	t_philo	*ph;

	ph = (t_philo *) p;
	while (1)
	{
		pthread_mutex_lock(&ph->pause);
	}
	return (NULL);
}

void	*meals_checker(t_philo *ph)
{
	return (NULL);
}

static void	philo_loop(void *ph, t_program *pr)
{
	pthread_t	thread;
	void		*data;

	pthread_create(&thread, NULL, alive_checker, ph);
	while (1)
		perform_actions(pr, ph);
}

int	start_loop(t_program *pr)
{
	pthread_t	threads[MAX_PHILOS];
	size_t		i;
	
	i = 0;
	if (pr->num_meals != -1)
	{
		// meals_checker();
	}
	while (i < pr->philo_size)
	{
		// philo_loop();
		++i;
	}
	// join_threads();
	return (1);
}
