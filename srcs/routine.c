/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/04/14 21:04:11 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*sleeping(void *arg)
{
	t_state			*state;
	t_philo			*philo;
	t_table			*table;
	time_t			time;

	state = (t_state *)arg;
	table = state->table;
	philo = state->philo;
	time = get_time_in_ms();
	print_state(table, philo->id, SLEEPING);
	usleep(state->table->tts * 1000);
}

void	*eating(void *arg)
{
	t_state			*state;
	t_table			*table;
	t_philo			*philo;
	time_t			time;

	state = (t_state *)arg;
	table = state->table;
	philo = state->philo;
	// printf("%ld\n", time_diff(table->start, philo->last_meal));
	if (time_diff(table->start, philo->last_meal) > table->ttd)
		print_state(table, philo->id, DEAD);
	else
		philo->last_meal = get_time_in_ms();
	pthread_mutex_lock(philo->fork);
	print_state(table, philo->id, HUNGRY);
	pthread_mutex_lock(&table->forks[(philo->id + 1) % table->nbr_of_philos]);
	print_state(table, philo->id, HUNGRY);
	philo ->last_meal = get_time_in_ms();
	time = get_time_in_ms();
	print_state(table, philo->id, EATING);
	usleep(table->tte * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(&table->forks[(philo->id + 1) % table->nbr_of_philos]);
}

void	*thinking(void *arg)
{
	t_state	*state;
	t_table	*table;
	t_philo	*philo;
	time_t	time;

	state = (t_state *)arg;
	table = state->table;
	philo = state->philo;
	time = get_time_in_ms();
	print_state(table, philo->id, THINKING);
}

void	*routine(void *arg)
{
	while (1)
	{
		eating(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}

void	start(t_table *table)
{
	t_state			**states;
	int				i;

	i = 0;
	states = table->states;
	while (++i <= table->nbr_of_philos)
	{
		if (table->philos[i].id % 2 == 0)
		{
			states[i]->table = table;
			states[i]->philo = &table->philos[i];
			pthread_create(&table->philos[i].thread, NULL, routine, states[i]);
		}
	}
	i = 0;
	while (++i <= table->nbr_of_philos)
	{
		if (table->philos[i].id % 2 == 1)
		{
			states[i]->table = table;
			states[i]->philo = &table->philos[i];
			pthread_create(&table->philos[i].thread, NULL, routine, states[i]);
		}
	}
}
