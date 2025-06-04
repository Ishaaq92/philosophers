/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:22 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/02 16:48:15 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>


typedef struct s_state t_state;
typedef struct s_philo t_philo;

enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	HUNGRY,
	DEAD	
};

typedef struct	s_info
{
	int				nbr_of_philos;
	int				go;
	long			t0;
	long			ttd;
	long			tte;
	long			tts;
}	t_info;

typedef struct s_table
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_info			info;
	t_state			**states;
	pthread_mutex_t	*ready;
	pthread_mutex_t	*printf;
	pthread_mutex_t	*dead_philo;
}	t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long int		last_meal;
	enum e_state	state;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*o_fork;
}   t_philo;


typedef struct s_state
{
	int		id;
	t_table	*table;
	t_philo	*philo;
}	t_state;

// init.c
void	init_philos(t_table *table);
t_table	init_table(int ac, char *av[], t_info info);
t_info	init_info(int ac, char **av);

// utils.c
long int	get_time_in_ms(void);
int			ft_atoi(const char *nptr);
void		free_all(t_table *table, int error);
long		time_diff(long t0, long t1);
t_philo		*print_state(t_table *table, int id, enum e_state state);

// actions.c
t_philo	*eating(t_state *state);
t_philo	*sleeping(t_state *state);
t_philo	*thinking(t_state *state);
void	start(t_table *table);

#endif