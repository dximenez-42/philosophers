/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:51:23 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/16 12:03:45 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*alive_checker(void *p)
{
	t_philo	*ph;

	ph = p;
	while (1)
	{
		pthread_mutex_lock(&ph->pause);
		if (ph->time_remain < get_time() && ph->meals_eaten == 0)
		{
			show_message(ph->pr, ph, DEAD);
			pthread_mutex_lock(&ph->pr->write_lock);
			pthread_mutex_unlock(&ph->pr->dead_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->pause);
		usleep(1000);
	}
}

void	*meals_checker(void *p)
{
	return (NULL);
}
