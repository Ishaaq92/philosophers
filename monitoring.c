/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/13 15:46:47 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_table	*table;
	t_philo	*philos;
	int		i;
	
	table = (t_table *) arg;
	philos = table->philos;
	i = 0;
	while (++i <= table->info.nbr_of_philos)
		while (get_last_meal(&philos[i]) == -1)
			usleep(100); 
	while (42)
	{
		i = 0;
		while (++i <= table->info.nbr_of_philos)
		{
			// printf("remaining = %d\n", get_remaining(&table->info));
			if (get_remaining(&table->info) == 0)
				return (set_sim(&table->info, 1), NULL);
			if (get_sim(&philos[i])) 
				return (NULL);
			if (diff(get_last_meal(&philos[i]), get_time_in_ms()) > (long)table->info.ttd)
				return (print_state(&philos[i], DEAD), &philos[i]);
		}
		precise_action(&philos[1], table->info.ttd / 1000);
	}
}

void    monitoring(t_table  *table)
{
	pthread_t   thread;
	
	set_sim(&table->info, 0);
	pthread_create(&thread, NULL, monitor, table);
	pthread_join(thread, NULL);
	printf("monitoring thread terminated\n");
}
