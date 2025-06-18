/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:22:07 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/18 20:31:27 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (!philo || !philo->fork || !philo->o_fork)
		return ;
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->o_fork);
	print_state(philo, EATING);
	pthread_mutex_unlock(philo->o_fork);
	pthread_mutex_unlock(philo->fork);
}

void    *routine(void *arg)
{
	t_philo *philo;
	t_info  info;

	philo = (t_philo *) arg;
	info = philo->info; 
	pthread_mutex_lock(info.sim);
	pthread_mutex_unlock(info.sim); 
	if (philo->id % 2 == 1)
		usleep(info.tte * 1000 / 2);
	// Debugging

	eating(philo);
	// while (42)
	// {
	// }
	return (NULL);
}
