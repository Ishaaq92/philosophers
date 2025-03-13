/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/13 08:43:59 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*eat(void *arg)
{
	t_state			*state;
	struct timeval	time;
	t_table			*table;
	t_philo			*philo;

	printf("hiii");
	state = (t_state *)arg;
	table = state->table;
	philo = state->philo;
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(table->philos[philo->id+1].fork);
	printf("%ld philosopher %d is eating", time.tv_sec*1000000 + time.tv_usec, philo->id);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(table->philos[philo->id+1].fork);
	gettimeofday(&time, NULL);
	sleep(table->tte);
	return (NULL);
}