/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:24:00 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/17 18:03:13 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms / 10);
}

void	init_forks(t_program *pr, size_t i, size_t size)
{
	if (size == 1)
	{
		pr->philos[i].r_fork = 0;
		pr->philos[i].l_fork = -1;
	}
	if (size > 1)
	{
		pr->philos[i].r_fork = i;
		if (i == 0)
			pr->philos[i].l_fork = pr->philo_size - 1;
		else
			pr->philos[i].l_fork = i - 1;
	}
	pthread_mutex_init(&pr->forks[i], NULL);
}

static int	init_philos(t_program *pr)
{
	size_t	i;
	size_t	size;

	i = -1;
	size = pr->philo_size;
	pr->start_time = get_time();
	while (++i < size)
	{
		pr->philos[i].id = i + 1;
		init_forks(pr, i, size);
		pthread_mutex_init(&pr->philos[i].pause, NULL);
		pr->philos[i].pr = pr;
		if (pthread_create(&pr->philos[i].thread, NULL,
			init_thread, &pr->philos[i]) != 0)
			return (0);
	}
	i = 0;
	while (i < pr->philo_size)
		pthread_join(pr->philos[i++].thread, NULL);
	return (1);
}

void	init_program(t_program *pr, int amount, int ac, char *av[])
{
	int	i;
	
	i = 0;
	pr->dead_flag = 0;
	pr->time_to_die = ft_atoi(av[2]);
	pr->time_to_eat = ft_atoi(av[3]);
	pr->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		pr->num_meals = ft_atoi(av[5]);
	else
		pr->num_meals = -1;
	pr->philo_size = amount;
	pthread_mutex_init(&pr->dead_lock, NULL);
	pthread_mutex_init(&pr->meal_lock, NULL);
	pthread_mutex_init(&pr->write_lock, NULL);
	init_philos(pr);
}
