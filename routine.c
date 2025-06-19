/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:22:07 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/19 11:19:06 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (!philo || !philo->fork || !philo->o_fork)
		return ;
	pthread_mutex_lock(philo->fork);
	print_state(philo, HUNGRY);
	pthread_mutex_lock(philo->o_fork);
	print_state(philo, HUNGRY);
	print_state(philo, EATING);
	set_last_meal(philo, get_time_in_ms());
	// philo->last_meal = get_time_in_ms();
	usleep(philo->info.tte * 1000);
	pthread_mutex_unlock(philo->o_fork);
	pthread_mutex_unlock(philo->fork);
}

void	thinking(t_philo *philo)
{
	if (!philo || !philo->fork || !philo->o_fork)
		return ;
	print_state(philo, THINKING);
}

void	sleeping(t_philo *philo)
{
	if (!philo || !philo->fork || !philo->o_fork)
		return ;
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
	philo->last_meal = get_time_in_ms();
	philo->start = get_time_in_ms();
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
