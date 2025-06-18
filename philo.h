/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:45 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/16 16:24:16 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_info
{
	int	nbr_of_philos;
	int	tte;
	int	tts;
	int	ttd;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*o_fork;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	t_info	info;
}	t_table;

// utils.c
int		ft_atoi(const char *nptr);

// routine.c
void    *routine(void *routine);

// init.c
void	init_philos(t_table *table, t_info *info);
void	init_table(t_table *table, t_info *info);
void	init_info(t_info *info, char **av);

#endif
