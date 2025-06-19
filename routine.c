/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:22:07 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/19 20:47:06 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(philo->o_fork);
	}
	else
	{
		pthread_mutex_lock(philo->o_fork);
		pthread_mutex_lock(philo->fork);
	}
	print_state(philo, HUNGRY);
	print_state(philo, HUNGRY);
	print_state(philo, EATING);
	set_last_meal(philo, get_time_in_ms());
	usleep(philo->info.tte * 1000);
	if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock(philo->o_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->o_fork);
		pthread_mutex_unlock(philo->fork);
	}
}

void	thinking(t_philo *philo)
{
	// if (!philo || !philo->fork || !philo->o_fork)
	// 	return ;
	print_state(philo, THINKING);
}

void	sleeping(t_philo *philo)
{
	// if (!philo || !philo->fork || !philo->o_fork)
	// 	return ;
	print_state(philo, SLEEPING);
	usleep(philo->info.tts * 1000);
}

void    *routine(void *arg)
{
	t_philo *philo;
	t_info  info;

	philo = (t_philo *) arg;
	info = philo->info; 
	pthread_mutex_lock(info.sim);
	pthread_mutex_unlock(info.sim); 
	set_last_meal(philo, get_time_in_ms());
	set_start(philo, get_time_in_ms());
	if (philo->id % 2 == 1)
		usleep(info.tte * 1000 / 3);
	while (42)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		break ;
	}
	return (NULL);
}
