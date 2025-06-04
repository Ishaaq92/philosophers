/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/04 13:24:06 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*sleeping(t_state *state)
{
	t_philo	*philo;
	t_table	*table;

	table = state->table;
	philo = state->philo;
	// if (time_diff(philo->last_meal, get_time_in_ms()) >= table->info.ttd)
	// 	return (print_state(table, philo->id, DEAD));
	print_state(table, philo->id, SLEEPING);
	usleep(table->info.tts * 1000);
	return (NULL);
}

t_philo	*eating(t_state *state)
{
	t_table			*table;
	t_philo			*philo;

	table = state->table;
	philo = state->philo;
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->o_fork);
	// if (time_diff(philo->last_meal, get_time_in_ms()) >= table->info.ttd)
	// 	return (print_state(table, philo->id, DEAD));
	print_state(table, philo->id, HUNGRY);
	print_state(table, philo->id, HUNGRY);
	philo->last_meal = get_time_in_ms();
	print_state(table, philo->id, EATING);
	usleep(table->info.tte * 1000);
	pthread_mutex_unlock(philo->o_fork);
	pthread_mutex_unlock(philo->fork);
	return (NULL);
}

t_philo	*thinking(t_state *state)
{
	t_table	*table;
	t_philo	*philo;
	
	table = state->table;
	philo = state->philo;
	// if (time_diff(philo->last_meal, get_time_in_ms()) >= table->info.ttd)
	// 	return (print_state(table, philo->id, DEAD));
	print_state(table, philo->id, THINKING);
	// usleep(table->info.tte * 1000);
	return (NULL);
}

void	*routine(void *arg)
{
	t_state	*state;

	state = (t_state *)arg;
	pthread_mutex_lock(state->table->ready);
	if ((state->id % 2) == 1)
	{
		pthread_mutex_unlock(state->table->ready);
		usleep(state->table->info.tte * 500);
	}	
	else
		pthread_mutex_unlock(state->table->ready);
	state->philo->last_meal = get_time_in_ms();
	// state->table->info.t0 = get_time_in_ms();
	while (!eating(state) && !sleeping(state) && !thinking(state))
		continue ;
	return (state->philo);
}

void	start(t_table *table)
{
	t_state		**states;
	int			i;

	i = 0;
	states = table->states;
	pthread_mutex_lock(table->ready);
	free(table->ready);
	while (++i <= table->info.nbr_of_philos)
	{
		states[i]->id = i;
		states[i]->table = table;
		states[i]->philo = &table->philos[i];
		pthread_create(&table->philos[i].thread, NULL, routine, states[i]);
	}
	table->info.t0 = get_time_in_ms();
	pthread_mutex_unlock(table->ready);
}
