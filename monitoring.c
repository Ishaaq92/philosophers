/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/29 21:26:23 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_table	*table;
	t_philo *philos;
	int		i;

	table = (t_table *) arg;
	philos = table->philos;
	precise_action(table->info.tte);
	i = 0;
	while (++i <= table->info.nbr_of_philos)
		while (get_last_meal(&philos[i]) == -1)
			continue;
	i = 1;
	while (diff(get_last_meal(&philos[i]), get_time_in_ms()) <= (long) table->info.ttd)
	{
		usleep(1000);
		if ((++i) > table->info.nbr_of_philos)
			i = 1;
	}
	print_state(&philos[i], DEAD);
	set_sim(&table->info, 1);
	return (&philos[i]);
}

void    monitoring(t_table  *table)
{
	pthread_t   thread;
	
	set_sim(&table->info, 0);
	pthread_create(&thread, NULL, monitor, table);
	pthread_join(thread, NULL);
	printf("monitoring thread terminated\n");
}
