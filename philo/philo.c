/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:43:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/14 19:25:14 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	show_message(t_program *pr, t_philo *ph, int type)
{
	printf("%llu\t", (get_time() - pr->start_time));
	if (type == FORK)
		printf("%d has taken a fork\n", ph->id);
	else if (type == EAT)
		printf("%d is eating\n", ph->id);
	else if (type == THINK)
		printf("%d is thinking\n", ph->id);
	else if (type == SLEEP)
		printf("%d is sleeping\n", ph->id);
	else if (type == DEAD)
		printf("%d died\n", ph->id);
}

int main(int ac, char *av[])
{
	t_program	pr;
	
	if (!check_input(ac, av))
		return (input_error(), 0);
	init_program(&pr, ft_atoi(av[1]), ac, av);
	if (start_loop(&pr) == 0)
		printf("Error in the loop.\n");
	pthread_mutex_lock(&pr.dead_lock);
}
