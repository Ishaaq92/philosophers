/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:30:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/18 21:20:23 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo		*print_state(t_philo *philo, enum e_state state)
{
	int	id;

	id = philo->id;
	pthread_mutex_lock(philo->info.print);
	if (state == EATING)
		printf("%ld %d is eating\n", time_diff(philo->start, get_time_in_ms()), id);
	else if (state == THINKING)
		printf("%ld %d is thinking\n", time_diff(philo->start, get_time_in_ms()), id);
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

