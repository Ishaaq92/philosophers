/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:33:37 by isahmed           #+#    #+#             */
/*   Updated: 2025/07/14 17:36:17 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_last_meal(t_philo *philo)
{
	long	lm;

	pthread_mutex_lock(philo->m_last_meal);
	lm = philo->last_meal;
	pthread_mutex_unlock(philo->m_last_meal);
	return (lm);
}

int	get_remaining(t_info *info)
{
	int	val;

	val = -1;
	pthread_mutex_lock(info->m_remaining);
	if (info->remaining)
		val = *info->remaining;
	pthread_mutex_unlock(info->m_remaining);
	return (val);
}

void	decrement_remaining(t_info *info)
{
	pthread_mutex_lock(info->m_remaining);
	(*info->remaining) = (*info->remaining) - 1;
	pthread_mutex_unlock(info->m_remaining);
}
