/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:22 by ishaaq            #+#    #+#             */
/*   Updated: 2025/04/14 19:49:34 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	HUNGRY,
	DEAD	
};

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	time_t			last_meal;
	enum e_state	state;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*o_fork;
}   t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				nbr_of_philos;
	pthread_mutex_t	*forks;
	time_t			start;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
}	t_table;

typedef struct s_state
{
	t_table	*table;
	t_philo	*philo;
}	t_state;

// init.c
void	init_philos(t_table *table);
t_table	init_table(int ac, char *av[]);

// utils.c
long int	get_time_in_ms(void);
int			ft_atoi(const char *nptr);
void		free_all(t_table *table, int error);
time_t		time_diff(time_t t0, time_t t1);
void	print_state(time_t start, int id, enum e_state state);

// actions.c
void	*eating(void *arg);
void	start(t_table *table);

#endif