/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/05/28 18:19:50 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*sleeping(t_state *state)
{
	t_philo			*philo;
	t_table			*table;
	time_t			time;

	if (time_diff(table->start, philo->last_meal) > table->ttd)
		print_state(table, philo->id, DEAD);
	table = state->table;
	philo = state->philo;
	time = get_time_in_ms();
	usleep(state->table->tts * 1000);
	return (print_state(table, philo->id, SLEEPING));
}

t_philo	*eating(t_state *state)
{
	t_table			*table;
	t_philo			*philo;

	table = state->table;
	philo = state->philo;
	if (time_diff(table->start, philo->last_meal) > table->ttd)
		return (print_state(table, philo->id, DEAD));
	philo->last_meal = get_time_in_ms();
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(&table->forks[(philo->id + 1) % table->nbr_of_philos]);
	print_state(table, philo->id, HUNGRY);
	print_state(table, philo->id, HUNGRY);
	philo ->last_meal = get_time_in_ms();
	print_state(table, philo->id, EATING);
	usleep(table->tte * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(&table->forks[(philo->id + 1) % table->nbr_of_philos]);
	return (NULL);
}

t_philo	*thinking(t_state *state)
{
	t_table	*table;
	t_philo	*philo;
	time_t	time;

	if (time_diff(table->start, philo->last_meal) > table->ttd)
		return (print_state(table, philo->id, DEAD));
	table = state->table;
	philo = state->philo;
	time = get_time_in_ms();
	print_state(table, philo->id, THINKING);
	return (NULL);
}

void	*routine(void *arg)
{
	t_state	*state;

	state = (t_state *)arg;
	while (42)
	{
		if (!eating(state) && !sleeping(state) && !thinking(state))
			continue ;
		return (state->philo);
	}
}

void	start(t_table *table)
{
	t_state		**states;
	int			i;

	i = 0;
	states = table->states;
	pthread_mutex_lock(table->ready);
	pthread_mutex_unlock(table->ready);
	free(table->ready);
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
