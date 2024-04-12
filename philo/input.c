/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:52:10 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/12 19:21:11 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			i++;
		else
			return (0);
	}
	if (i > 11)
		return (0);
	return (1);
}

int	check_input(int ac, char *av[])
{
	int	i;
	int	val;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (!is_number(av[i]))
				return (0);
			val = ft_atoi(av[i]);
			if (val <= 0 || val > INT_MAX || (i == 0 && val > 200)
				|| (i == 2 || i == 3 || i == 4) && val < 60)
				return (0);
			++i;
		}
	}
	else
		return (0);
	return (1);
}
