/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:22:07 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/29 21:17:37 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	lock_fork(philo);
	if (get_sim(philo) == 1 || !print_state(philo, HUNGRY) || !print_state(philo, HUNGRY) || !print_state(philo, EATING))
		return (unlock_fork(philo), 0);
	set_last_meal(philo, get_time_in_ms());
	precise_action(philo->info.tte);
	unlock_fork(philo);
	return (1);
}

int	thinking(t_philo *philo)
{
	if (!philo || print_state(philo, THINKING) == NULL)
		return (0);
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (!philo || print_state(philo, SLEEPING) == NULL)
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
	set_start(philo, get_time_in_ms());
	if (philo->id % 2 == 1)
		precise_action(philo->info.tte);
	set_last_meal(philo, get_time_in_ms());
	i = 0;
	while ((info.rounds == -1 || i++ < info.rounds) && get_sim(philo) == 0)
		if (eating(philo) == 0 || sleeping(philo) == 0 || thinking(philo) == 0)
			break;
	return (NULL);
}
