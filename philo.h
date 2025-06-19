/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:45 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/19 11:12:06 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	HUNGRY,
	DEAD
};

typedef struct s_info
{
	int				nbr_of_philos;
	pthread_mutex_t	*print;
	pthread_mutex_t	*sim;
	int				tte;
	int				tts;
	int				ttd;
}	t_info;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	long			start;
	t_info			info;
	pthread_t		thread;
	pthread_mutex_t	*m_last_meal;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*o_fork;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_info			info;
}	t_table;

// utils.c
int			ft_atoi(const char *nptr);
t_philo		*print_state(t_philo *philo, enum e_state state);
long int	get_time_in_ms(void);
long		time_diff(long t0, long t1);
void		set_last_meal(t_philo *philo, long val);
long		get_last_meal(t_philo *philo);

// routine.c
void    *routine(void *arg);
void	thinking(t_philo *philo);

// init.c
void	init_philos(t_table *table, t_info *info);
void	init_table(t_table *table, t_info *info);
void	init_info(t_info *info, char **av);

// monitoring.c
void    monitoring(t_table  *table);

#endif
