/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/04 15:57:53 by isahmed          ###   ########.fr       */
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
	if (print_state(table, philo->id, SLEEPING))
		return (philo);
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
	pthread_mutex_lock(philo->access_lm);
	if (print_state(table, philo->id, HUNGRY))
		return (philo);
	if (print_state(table, philo->id, HUNGRY))
		return (philo);
	philo->last_meal = get_time_in_ms();
	if (print_state(table, philo->id, EATING))
		return (philo);
	usleep(table->info.tte * 1000);
	pthread_mutex_unlock(philo->access_lm);
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
	if (print_state(table, philo->id, THINKING))
		return (philo);
	return (NULL);
}

void	*routine(void *arg)
{
	t_state	*state;

	state = (t_state *)arg;
	pthread_mutex_lock(state->philo->access_lm);
	state->philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(state->philo->access_lm);
	pthread_mutex_lock(state->table->ready);
	if ((state->id % 2) == 1)
	{
		pthread_mutex_unlock(state->table->ready);
		usleep(state->table->info.tte * 500);
	}	
	else
		pthread_mutex_unlock(state->table->ready);
	while (!eating(state) && !sleeping(state) && !thinking(state))
		continue ;
	return (state->philo);
}
