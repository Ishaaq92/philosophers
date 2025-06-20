/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:48 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/20 12:40:20 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *edge_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->info.sim);
	pthread_mutex_unlock(philo->info.sim); 
	set_last_meal(philo, get_time_in_ms());
	set_start(philo, get_time_in_ms());
	pthread_mutex_lock(philo->fork);
	print_state(philo, HUNGRY);
	pthread_mutex_unlock(philo->fork);
	return (NULL);
}

void    *single_philo(t_table *table)
{
	// printf("here");
	t_philo	philo;

	philo = table->philos[1];
	pthread_create(&philo.thread, NULL, edge_routine, &philo);
	monitoring(table);
	return(NULL);
}