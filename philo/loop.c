/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:51:23 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/17 21:10:06 by dximenez         ###   ########.fr       */
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
		if (ph->time_remain < get_time() && ph->meals_eaten != 0)
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

void	*init_thread(void *arg)
{
	pthread_t	thread;
	t_philo		*ph;
	long long	i;

	ph = arg;
	i = -1;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pr->time_to_eat / 10);
	ph->last_meal = get_time();
	ph->time_remain = ph->last_meal + ph->pr->time_to_die;
	if (pthread_create(&thread, NULL, alive_checker, ph) != 0)
		return ((void *) 1);
	while (ph->pr->num_meals == -1 || ++i < ph->pr->num_meals)
	{
		perform_actions(ph->pr, ph);
	}
	return (NULL);
}