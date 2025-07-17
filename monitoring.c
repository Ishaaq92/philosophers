/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/17 15:51:40 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->info.print);
	set_sim(&philo->info, 1);
	printf("%ld %d died\n", diff(get_start(philo),
			get_time_in_ms()), philo->id);
	pthread_mutex_unlock(philo->info.print);
}

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
			if (get_remaining(&table->info) == 0)
				return (set_sim(&table->info, 1), NULL);
			if (get_sim(&philos[i]))
				return (NULL);
			if (diff(get_last_meal(&philos[i]),
					get_time_in_ms()) > (long)table->info.ttd)
				return (print_dead(&philos[i]), &philos[i]);
		}
		precise_action(&philos[1], table->info.ttd / 100);
	}
}

void	monitoring(t_table *table)
{
	pthread_t	thread;

	set_sim(&table->info, 0);
	pthread_create(&thread, NULL, monitor, table);
	pthread_join(thread, NULL);
}
