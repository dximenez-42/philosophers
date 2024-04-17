/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:55:30 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/17 11:22:30 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	p_take_forks(t_program *pr, t_philo *ph)
{
	int	i;

	i = 1;
	if (ph->l_fork != -1)
	{
		pthread_mutex_lock(&pr->forks[ph->l_fork]);
		show_message(pr, ph, FORK);
		++i;
	}
	pthread_mutex_lock(&pr->forks[ph->r_fork]);
	show_message(pr, ph, FORK);
	return (i);
}

static void	p_eat(t_program *pr, t_philo *ph)
{
	ph->last_meal = get_time();
	pthread_mutex_lock(&ph->pause);
	ph->time_remain = ph->last_meal + pr->time_to_die;
	pthread_mutex_unlock(&ph->pause);
	show_message(pr, ph, EAT);
	usleep(pr->time_to_eat * 1000);
	pthread_mutex_lock(&ph->pause);
	ph->meals_eaten++;
	pthread_mutex_unlock(&ph->pause);
	pthread_mutex_unlock(&pr->forks[ph->l_fork]);
	pthread_mutex_unlock(&pr->forks[ph->r_fork]);
}

static void	p_sleep(t_program *pr, t_philo *ph)
{
	show_message(pr, ph, SLEEP);
	usleep(pr->time_to_sleep * 1000);
}

static void	p_think(t_program *pr, t_philo *ph)
{
	show_message(pr, ph, THINK);
}

void	perform_actions(t_program *pr, t_philo *ph)
{
	if (p_take_forks(pr, ph) == 2)
	{
		p_eat(pr, ph);
		p_sleep(pr, ph);
		p_think(pr, ph);
	}
}
