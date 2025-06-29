/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:28:58 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/29 21:11:53 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_sim(t_info *info, int val)
{
	pthread_mutex_lock(info->sim);
	*info->stop = val;
	// printf("set_sim was called value = %d\n", *info->stop);
	pthread_mutex_unlock(info->sim);
}

int	get_sim(t_philo *philo)
{
	int		stop;
	t_info	info;

	info = philo->info;
	pthread_mutex_lock(info.sim);
	stop = *info.stop;
	// printf("get_sim was called value = %d\n", stop);
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
