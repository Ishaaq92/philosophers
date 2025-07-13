/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:22:07 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/13 15:39:48 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	lock_fork(philo);
	if (get_sim(philo) == 1 || !print_state(philo, HUNGRY) || !print_state(philo, HUNGRY) || !print_state(philo, EATING))
		return (unlock_fork(philo), 0);
	set_last_meal(philo, get_time_in_ms());
	precise_action(philo, philo->info.tte);
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
	precise_action(philo, philo->info.tts);
	return (1);
}

void    *routine(void *arg)
{
	t_philo *philo;
	t_info  info;
	int		rounds;

	philo = (t_philo *) arg;
	info = philo->info;
	pthread_mutex_lock(info.sim);
	pthread_mutex_unlock(info.sim); 
	set_start(philo, get_time_in_ms());
	if (philo->id % 2 == 1)
		precise_action(philo, philo->info.ttd / 10);
	set_last_meal(philo, get_time_in_ms());
	rounds = info.rounds;
	while (get_sim(philo) == 0)
	{
		if (eating(philo) == 0 || sleeping(philo) == 0 || thinking(philo) == 0)
			break;
		if (--rounds == 0)
			decrement_remaining(&philo->info);
	}
	// printf("philo with id = %d has stopped\n", philo->id);
	return (NULL);
}
