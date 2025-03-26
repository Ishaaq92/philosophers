/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:22 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/26 14:15:21 by isahmed          ###   ########.fr       */
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
	HUNGRY	
};

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	struct timeval	last_meal;
	enum e_state	state;
	pthread_mutex_t	*fork;
}   t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				nbr_of_philos;
	pthread_mutex_t	*forks;
	struct timeval	start;
	int				ttd;
	int				tte;
	int				tts;
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
int			ft_atoi(const char *nptr);
void		free_all(t_table *table, int error);
long int	time_val_diff(struct timeval t0, struct timeval t1);

// actions.c
void	*eat(void *arg);
void	start(t_table *table);

#endif