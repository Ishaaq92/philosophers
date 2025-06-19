/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:28:58 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/19 19:29:21 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
