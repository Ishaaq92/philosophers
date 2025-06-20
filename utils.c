/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:30:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/20 11:46:47 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo		*print_state(t_philo *philo, enum e_state s)
{
	int	id;

	id = philo->id;
	if (get_sim(philo) == 1)
		exit(1);
	pthread_mutex_lock(philo->info.print);
	if (s == EATING)
		printf("%ld %d is eating\n", time_diff(get_start(philo), get_time_in_ms()), id);
	else if (s == THINKING)
		printf("%ld %d is thinking\n", time_diff(get_start(philo), get_time_in_ms()), id);
	else if (s == SLEEPING)
		printf("%ld %d is sleeping\n", time_diff(get_start(philo), get_time_in_ms()), id);
	else if (s == HUNGRY)
		printf("%ld %d has taken a fork\n", time_diff(get_start(philo), get_time_in_ms()), id);
	else if (s == DEAD)
	{
		printf("%ld %d has died\n", time_diff(get_start(philo), get_time_in_ms()), id);
		return (NULL);
	}
	pthread_mutex_unlock(philo->info.print);
	return (philo);
}

long	time_diff(long t0, long t1)
{
	return (t1 - t0);
}

long int	get_time_in_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		total = (total * 10) + (nptr[i] - 48);
		i ++;
	}
	return (sign * total);
}

