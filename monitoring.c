/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/20 12:43:00 by ishaaq           ###   ########.fr       */
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
	// printf("stop = %d\n ", *table->info.stop);
	pthread_mutex_lock(table->info.sim);
	pthread_mutex_unlock(table->info.sim);
	precise_action(table->info.tte);
	while (time_diff(get_last_meal(&philos[i]), get_time_in_ms()) <= (long) ttd)
	{
		// pthread_mutex_lock(table->info.print);
		// printf("%d %ld \n", i , time_diff(get_last_meal(&philos[i]), get_time_in_ms()));
		// pthread_mutex_unlock(table->info.print);
		// usleep(100);
		i ++;
		if (i > table->info.nbr_of_philos)
			i = 1;
	}
	// pthread_mutex_lock(table->info.print);
	// printf("%d %ld \n", i , time_diff(get_last_meal(&philos[i]), get_time_in_ms()));
	// pthread_mutex_unlock(table->info.print);
	print_state(&philos[i], DEAD);
	set_sim(&philos[i], 1);
	// printf("stop = %d\n ", *table->info.stop);
	return (&philos[i]);
}

void    monitoring(t_table  *table)
{
	pthread_t   thread;
	
	set_sim(&table->philos[1], 0);
	// pthread_mutex_lock(table->info.sim);
	pthread_create(&thread, NULL, monitor, table);
	pthread_join(thread, NULL);
}
