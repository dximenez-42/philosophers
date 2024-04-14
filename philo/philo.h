/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:44:31 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/14 16:27:49 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define MAX_PHILOS 200

// Message types
enum {
	EAT,
	THINK,
	SLEEP,
	FORK,
	DEAD
};

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					eating;
	int					meals_eaten;
	long long			last_meal;
	long long			time_remain;
	size_t				l_fork;
	size_t				r_fork;
	struct t_program	*pr;
}						t_philo;

typedef struct s_program
{
	int				dead_flag;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		num_times_to_eat;
	long long		start_time;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	size_t			philo_size;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];
}					t_program;

long long	get_time(void);

int			check_input(int ac, char *av[]);

// Init
void		init_program(t_program *pr, int amount);

// Errors
void		input_error(void);

int			ft_atoi(char *s);

#endif