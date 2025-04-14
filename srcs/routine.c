/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:43:32 by ishaaq            #+#    #+#             */
/*   Updated: 2025/04/14 17:51:40 by isahmed          ###   ########.fr       */
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
	print_state(table->start, philo->id, SLEEPING);
	usleep(state->table->tts * 1000);
}

void	*eat(void *arg)
{
	t_state			*state;
	t_table			*table;
	t_philo			*philo;
	time_t			time;

	state = (t_state *)arg;
	table = state->table;
	philo = state->philo;
	time = get_time_in_ms();
	print_state(table->start, philo->id, EATING);
	usleep(table->tte * 1000);
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
	print_state(table->start, philo->id, THINKING);
}

void	*routine(void *arg)
{
	while (1)
	{
		eat(arg);
		sleeping(arg);
		thinking(arg);
	}
	free(arg);
	return (NULL);
}

void	start(t_table *table)
{
	t_state			*state;
	int				i;

	i = 1;
	while (i <= table->nbr_of_philos)
	{
		if (table->philos[i].id % 2 == 0)
		{
			// pthread_mutex_lock(&table->forks[i]);
			state = malloc(sizeof(t_state));
			state->table = table;
			state->philo = &table->philos[i];
			pthread_create(&table->philos[i].thread, NULL, routine, state);
			// pthread_mutex_unlock(&table->forks[i]);
		}
		i ++;
	}
}
