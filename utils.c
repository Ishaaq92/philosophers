/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:30:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/14 17:43:39 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*print_state(t_philo *philo, enum e_state s)
{
	int	id;

	id = philo->id;
	if (get_sim(philo) == 1)
		return (NULL);
	pthread_mutex_lock(philo->info.print);
	if (s == EATING)
		printf("%ld %d is eating\n", diff(get_start(philo),
				get_time_in_ms()), id);
	else if (s == THINKING)
		printf("%ld %d is thinking\n", diff(get_start(philo),
				get_time_in_ms()), id);
	else if (s == SLEEPING)
		printf("%ld %d is sleeping\n", diff(get_start(philo),
				get_time_in_ms()), id);
	else if (s == HUNGRY)
		printf("%ld %d has taken a fork\n", diff(get_start(philo),
				get_time_in_ms()), id);
	else if (s == DEAD || get_sim(philo) == 1)
	{
		printf("%ld %d died\n", diff(get_start(philo), get_time_in_ms()), id);
		set_sim(&philo->info, 1);
		return (pthread_mutex_unlock(philo->info.print), NULL);
	}
	return (pthread_mutex_unlock(philo->info.print), philo);
}

void	free_all(t_table *table)
{
	int		i;
	t_info	info;
	t_philo	*philos;

	i = 0;
	info = table->info;
	philos = table->philos;
	while (++i <= info.nbr_of_philos)
	{
		pthread_mutex_destroy(philos[i].fork);
		pthread_mutex_destroy(philos[i].m_last_meal);
		pthread_mutex_destroy(philos[i].m_start);
		free(philos[i].fork);
		free(philos[i].m_last_meal);
		free(philos[i].m_start);
	}
	free(philos);
	free(info.print);
	free(info.sim);
	free(info.stop);
}

long	diff(long t0, long t1)
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
