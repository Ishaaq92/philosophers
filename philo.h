/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:45 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/14 17:39:32 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
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

typedef struct s_info
{
	int				nbr_of_philos;
	int				*remaining;
	pthread_mutex_t	*print;
	pthread_mutex_t	*sim;
	pthread_mutex_t	*m_remaining;
	int				*stop;
	int				rounds;
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
	pthread_mutex_t	*m_start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*o_fork;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_info			info;
}	t_table;

// utils.c
int		ft_atoi(const char *nptr);
t_philo	*print_state(t_philo *philo, enum e_state s);
long	get_time_in_ms(void);
long	diff(long t0, long t1);
void	free_all(t_table *table);

// mutexes.c
void	set_last_meal(t_philo *philo, long val);
long	get_last_meal(t_philo *philo);
void	set_start(t_philo *philo, long val);
long	get_start(t_philo *philo);
void	set_sim(t_info *info, int val);
int		get_sim(t_philo *philo);
void	decrement_remaining(t_info *info);
int		get_remaining(t_info *info);

// routine.c
void	*routine(void *arg);
int		thinking(t_philo *philo);

// init.c
void	init_philos(t_table *table, t_info *info);
void	init_table(t_table *table, t_info *info);
void	init_info(t_info *info, int ac, char **av);

// monitoring.c
void	monitoring(t_table *table);

// precision.c
void	precise_action(t_philo *philo, int tta);

// edge.c
void	*single_philo(t_table *table);

// forks.c
void	unlock_fork(t_philo *philo);
void	lock_fork(t_philo *philo);

#endif
