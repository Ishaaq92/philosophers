/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:18:52 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/04 15:19:03 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*checks(void *arg)
{
	t_table	*table;
	t_philo	*philos;

	table = (t_table *) arg;	
	philos = table->philos;
	int		i;

	table = (t_table *)arg;
	i = 0;
	pthread_mutex_lock(table->ready);
	pthread_mutex_unlock(table->ready);
	while (42)
	{
		pthread_mutex_lock(philos[++i].access_lm);
		if (time_diff(philos[i].last_meal, get_time_in_ms()) >= table->info.ttd)
			return (printf("%d has died   --monitoring\n", i), NULL);
		pthread_mutex_unlock(philos[i].access_lm);
		if (i == table->info.nbr_of_philos)
			i = 0;
	}
}

void	monitoring(t_table *table)
{
	pthread_t	*monitor;

	monitor = malloc(sizeof(pthread_t));
	pthread_create(monitor, NULL, checks, table);
}