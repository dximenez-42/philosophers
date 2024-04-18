/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:00:01 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/18 10:51:17 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *s)
{
	size_t	i;
	int		v;
	int		sy;

	i = 0;
	v = 0;
	sy = 1;
	while (is_space(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sy = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		v = (v * 10) + (s[i] - '0');
		i++;
	}
	return (sy * v);
}
