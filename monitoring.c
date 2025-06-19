/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/19 11:36:31 by ishaaq           ###   ########.fr       */
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
	usleep(table->info.tte * 1000  );
	while (42)
	{
		// pthread_mutex_lock(philos[i].info.print);
		// printf("%ld %d\n", time_diff(get_last_meal(&philos[i]), get_time_in_ms()), philos[i].id);
		// pthread_mutex_unlock(philos[i].info.print);
		if (time_diff(get_last_meal(&philos[i]), get_time_in_ms()) > (long) ttd)
		    break ;
		i ++;
		if (i > table->info.nbr_of_philos)
			i = 1;
	}
	// while (time_diff(get_last_meal(&philos[++i]), get_time_in_ms()) <= ttd)
	//     continue ;
	// return (NULL);
	return (&philos[i]);
}

void    monitoring(t_table  *table)
{
	pthread_t   thread;
	void        *ptr;

	ptr = NULL;
	pthread_create(&thread, NULL, monitor, table);
	// pthread_join(thread, ptr);
	// if (ptr)
	// 	printf("has died");
}