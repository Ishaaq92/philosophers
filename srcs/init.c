/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/13 08:22:54 by ishaaq           ###   ########.fr       */
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
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(table->philos[philo->id+1].fork);
	printf("%ld philosopher %d is eating", time.tv_sec*1000000 + time.tv_usec, philo->id);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(table->philos[philo->id+1].fork);
	gettimeofday(&time, NULL);
	sleep(table->tte);
	return (NULL);
}

void	init_philos(t_table *table)
{
	int		i;
	t_state	state;

	i = 1;
	printf("init_philo\n");
	state.table = table;
	while (i < table->nbr_of_philos)
	{
		table->philos[i].id = i;
		table->philos[i].state = HUNGRY;
		table->philos[i].fork = &table->forks[i];
		pthread_mutex_init(table->philos[i].fork, NULL);
		table->philos[i].last_meal.tv_sec = 0;
		table->philos[i].last_meal.tv_usec = 0;
		state.philo = &table->philos[i];
		if (i % 2 == 0)
			pthread_create(&table->philos[i].thread, NULL, eat, &state);
		i ++;
	}
}

t_table	init_table(int ac, char *av[])
{
	t_table			table;

	if (ac != 5)
		exit(1);
	table.nbr_of_philos = ft_atoi(av[1]);
	table.philos = malloc(sizeof(t_philo) * table.nbr_of_philos + 1);
	if (!table.philos)
		exit(1);
	table.forks = malloc(sizeof(pthread_mutex_t) * table.nbr_of_philos + 1);
	if (!table.forks)
	{
		free(table.philos);
		exit(1);	
	}
	table.ttd = ft_atoi(av[2]);
	table.tte = ft_atoi(av[3]);
	table.tts = ft_atoi(av[4]);
	init_philos(&table);
	return (table);
}
