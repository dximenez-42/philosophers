/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:43:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/14 16:49:00 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	show_message(t_philo *ph, t_program *pr, int t)
{
	printf("%llu\t", (get_time() - pr->start_time));
	if (t == FORK)
		printf("%d has taken a fork\n", ph->id);
	else if (t == EAT)
		printf("%d is eating\n", ph->id);
	else if (t == THINK)
		printf("%d is thinking\n", ph->id);
	else if (t == SLEEP)
		printf("%d is sleeping\n", ph->id);
	else if (t == DEAD)
		printf("%d died\n", ph->id);
}

int main(int ac, char *av[])
{
	t_program	*pr;
	
	if (!check_input(ac, av))
		return (input_error(), 0);
	pr = malloc(sizeof(t_program));
	if (pr == NULL)
		return (1);
	init_program(pr, ft_atoi(av[1]), ac, av);
}
