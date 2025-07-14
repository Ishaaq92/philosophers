/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:48 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/14 17:27:48 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*edge_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_last_meal(philo, get_time_in_ms());
	set_start(philo, get_time_in_ms());
	print_state(philo, HUNGRY);
	precise_action(philo, philo->info.ttd);
	print_state(philo, DEAD);
	return (NULL);
}

void	*single_philo(t_table *table)
{
	t_philo	philo;

	philo = table->philos[1];
	pthread_create(&philo.thread, NULL, edge_routine, &philo);
	pthread_join(philo.thread, NULL);
	return (NULL);
}
