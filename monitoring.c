/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/19 20:43:32 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_table	*table;
	t_philo *philos;
	int		i;
	int		ttd;

	table = (t_table *) arg;
	philos = table->philos;
	ttd = table->info.ttd;
	i = 1;
	usleep(table->info.tte * 1000);
	pthread_mutex_lock(table->info.sim);
	pthread_mutex_unlock(table->info.sim);
	while (time_diff(get_last_meal(&philos[i]), get_time_in_ms()) <= (long) ttd)
	{
		i ++;
		if (i > table->info.nbr_of_philos)
			i = 1;
		// usleep(table->info.tte * 1000 / 3);
	}
	print_state(&philos[i], DEAD);
	// pthread_mutex_lock(table->info.print);
	return (&philos[i]);
}

void    monitoring(t_table  *table)
{
	pthread_t   thread;
	
	pthread_mutex_lock(table->info.sim);
	pthread_create(&thread, NULL, monitor, table);
}
