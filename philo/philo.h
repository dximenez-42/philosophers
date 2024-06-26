/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:44:31 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/18 10:51:10 by dximenez         ###   ########.fr       */
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
enum
{
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
	ssize_t				l_fork;
	ssize_t				r_fork;
	pthread_mutex_t		pause;
	struct s_program	*pr;
}						t_philo;

typedef struct s_program
{
	int				dead_flag;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		num_meals;
	long long		start_time;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	size_t			philo_size;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];
}					t_program;

long long	get_time(void);
void		show_message(t_program *pr, t_philo *ph, int type);
int			check_input(int ac, char *av[]);

void		init_program(t_program *pr, int amount, int ac, char *av[]);
void		*alive_checker(void *p);
void		*init_thread(void *arg);

void		perform_actions(t_program *pr, t_philo *ph);

void		ft_usleep(int ms);
void		input_error(void);
void		cleanup(t_program *p, int c);
int			ft_atoi(char *s);

#endif
