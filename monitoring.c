/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/11 19:47:28 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_table	*table = (t_table *) arg;
	t_philo	*philos = table->philos;
	int		i;

	for (i = 1; i <= table->info.nbr_of_philos; i++)
		while (get_last_meal(&philos[i]) == -1)
			usleep(100); 
	while (42)
	{
		i = 1;
		while (i <= table->info.nbr_of_philos)
		{
			if (get_sim(&philos[i])) 
				return (NULL);
			if (diff(get_last_meal(&philos[i]), get_time_in_ms()) > (long)table->info.ttd)
			{
				print_state(&philos[i], DEAD);
				set_sim(&table->info, 1);
				return (&philos[i]);
			}
			i++;
		}
		usleep(1000);  
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
