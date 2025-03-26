/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/26 14:36:25 by isahmed          ###   ########.fr       */
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
	gettimeofday(&time, NULL);

	printf("%ld\n", time_val_diff(table->start, time));

	// printf("Here -> %d\n", philo->id);
	// printf("%ld philosopher %d is eating\n", time.tv_sec + time.tv_usec, philo->id);
	// sleep(table->tte * 1000);
	// pthread_mutex_unlock(philo->fork);
	// pthread_mutex_unlock(table->philos[(philo->id + 1) % table->nbr_of_philos].fork);
	return (NULL);
}

void	start(t_table *table)
{
	t_state			state;
	int				i;

	i = 1;
	state.table = table;
	while (i <= table->nbr_of_philos)
	{
		if (table->philos[i].id % 2 == 0)
		{
			pthread_mutex_lock(&table->forks[i]);

			state.philo = &table->philos[i];
			// printf("philo %d is eating\n", table->philos[i].id);
			// printf(" %d\n", state.philo->id);
			pthread_create(&table->philos[i].thread, NULL, eat, &state);

			pthread_mutex_unlock(&table->forks[i]);
		}
		i ++;
	}
}
