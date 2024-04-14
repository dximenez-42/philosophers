/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:24:00 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/14 16:22:34 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_program *pr)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = pr->philo_size;
	while (i < size)
	{
		pthread_mutex_init(&pr->forks[i], NULL);
		++i;
	}
}

static void	init_philos(t_program *pr)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = pr->philo_size;
	while (i < size)
	{
		pr->start_time = get_time();
		pr->philos[i].pr = (struct t_program *) pr;
		pr->philos[i].id = i + 1;
		pr->philos[i].eating = 0;
		pr->philos[i].meals_eaten = 0;
		pr->philos[i].last_meal = 0;
		pr->philos[i].r_fork = i + 1;
		if (i == 0)
			pr->philos[i].l_fork = size - 1;
		else
			pr->philos[i].l_fork = i;
		++i;
	}
}

void	init_program(t_program *pr, int amount)
{
	int	i;
	
	i = 0;
	pr->dead_flag = 0;
	pr->philo_size = amount;
	pthread_mutex_init(&pr->dead_lock, NULL);
	pthread_mutex_init(&pr->meal_lock, NULL);
	pthread_mutex_init(&pr->write_lock, NULL);
	init_philos(pr);
	init_forks(pr);
}
