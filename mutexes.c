/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:28:58 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/20 11:24:21 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_sim(t_philo *philo, long val)
{
	t_info	info;

	info = philo->info;
	pthread_mutex_lock(info.sim);
	*info.stop = val;
	pthread_mutex_unlock(info.sim);
	// printf("stop in set_sim = %d\n", *info.stop);
}

long	get_sim(t_philo *philo)
{
	long	stop;
	t_info	info;

	info = philo->info;
	pthread_mutex_lock(info.sim);
	stop = *info.stop;
	pthread_mutex_unlock(info.sim);
	return (stop);
}

void	set_start(t_philo *philo, long val)
{
	pthread_mutex_lock(philo->m_start);
	philo->start = val;
	pthread_mutex_unlock(philo->m_start);
}

long	get_start(t_philo *philo)
{
	long	start;

	pthread_mutex_lock(philo->m_start);
	start = philo->start;
	pthread_mutex_unlock(philo->m_start);
	return (start);
}

void	set_last_meal(t_philo *philo, long val)
{
	pthread_mutex_lock(philo->m_last_meal);
	philo->last_meal = val;
	pthread_mutex_unlock(philo->m_last_meal);
}

long	get_last_meal(t_philo *philo)
{
	long	lm;

	pthread_mutex_lock(philo->m_last_meal);
	lm = philo->last_meal;
	pthread_mutex_unlock(philo->m_last_meal);
	return (lm);
}
