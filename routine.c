/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:22:07 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/20 12:30:37 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
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
	if (!print_state(philo, HUNGRY) || !print_state(philo, HUNGRY) || !print_state(philo, EATING))
		return (0);
	set_last_meal(philo, get_time_in_ms());
	precise_action(philo->info.tte);
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
	return (1);
}

int	thinking(t_philo *philo)
{
	if (!philo)
		return (0);
	if (print_state(philo, THINKING) == NULL)
		return (0);
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (!philo)
		return (0);
	if (print_state(philo, SLEEPING) == NULL)
		return (0);
	precise_action(philo->info.tts);
	return (1);
}

void    *routine(void *arg)
{
	t_philo *philo;
	t_info  info;
	int		i;

	philo = (t_philo *) arg;
	info = philo->info; 
	pthread_mutex_lock(info.sim);
	pthread_mutex_unlock(info.sim); 
	set_last_meal(philo, get_time_in_ms());
	set_start(philo, get_time_in_ms());
	if (philo->id % 2 == 1)
		precise_action(philo->info.tte / 2);
	i = 0;
	while (eating(philo) && sleeping(philo) && thinking(philo) && (i++ < info.rounds || info.rounds == -1))
		continue ;
	return (NULL);
}
