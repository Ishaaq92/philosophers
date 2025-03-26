/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/20 15:58:56 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*eat(void *arg)
{
	t_state			*state;
	struct timeval	time;
	t_table			*table;
	t_philo			*philo;

	state = (t_state *)arg;
	table = state->table;
	philo = state->philo;
	printf("%ld philosopher %d is eating", time.tv_sec*1000000 + time.tv_usec, philo->id);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(table->philos[(philo->id + 1) % table->nbr_of_philos].fork);
	}
	// else
	// {
	// 	pthread_mutex_lock(&table->philos[right_fork].fork);
	// 	pthread_mutex_lock(&philo->fork);
	// }
	gettimeofday(&time, NULL);
	sleep(table->tte * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(table->philos[(philo->id + 1) % table->nbr_of_philos].fork);
	return (NULL);
}
