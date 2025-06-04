/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:18:52 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/04 17:25:33 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*checks(void *arg)
{
	t_table	*table;
	t_philo	*philos;
	table = (t_table *) arg;	
	philos = table->philos;
	long	diff;
	int		i;

	table = (t_table *)arg;
	i = 0;
	pthread_mutex_lock(table->ready);
	pthread_mutex_unlock(table->ready);
	while (42)
	{
		pthread_mutex_lock(philos[++i].access_lm);
		diff = time_diff(philos[i].last_meal, get_time_in_ms());
		if (philos[i].last_meal != 0 && diff > table->info.ttd)
		{
			pthread_mutex_lock(table->simulation);	
			table->info.stop = 1;
			pthread_mutex_unlock(table->simulation);
			pthread_mutex_lock(table->m_printf);
			printf("%ld %d has died   --monitoring\n", diff, i);
			pthread_mutex_unlock(table->m_printf);
			return (NULL);
		}
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
	pthread_join(*monitor, NULL);
}
