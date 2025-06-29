/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:15:05 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/29 18:51:23 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_philo *philo)
{
	// printf("1");
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
}

void	unlock_fork(t_philo *philo)
{
	// printf("1");
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
