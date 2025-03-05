/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:22 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/05 05:30:43 by ishaaq           ###   ########.fr       */
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

enum e_fork
{
	USING,
	NOT_USING,
	IN_USE
};

typedef struct s_times
{
	int	ttd;
	int	tte;
	int	tts;
}	t_times;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	struct timeval	last_meal;
	enum e_state	state;
	enum e_fork		fork;
	t_times			t;
}   t_philo;

typedef struct s_table
{
	t_philo	*philos;
	int		nbr_of_philos;
	int		forks_on_table;
	t_times	t;
}	t_table;

// init.c
void	init_philos(t_table *table);
t_table	init_table(int ac, char *av[]);

// utils.c
int	ft_atoi(const char *nptr);
void	free_all(t_table *table);

#endif