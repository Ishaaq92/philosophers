/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:25:04 by ishaaq            #+#    #+#             */
/*   Updated: 2025/04/14 20:31:47 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

void	print_state(t_table *table, int id, enum e_state state)
{
	time_t	start;

	start = table->start;
	if (state == EATING)
		printf("%ld %d is eating\n", time_diff(start, get_time_in_ms()), id);
	else if (state == THINKING)
		printf("%ld %d is thinking\n", time_diff(start, get_time_in_ms()), id);
	else if (state == SLEEPING)
		printf("%ld %d is sleeping\n", time_diff(start, get_time_in_ms()), id);
	else if (state == HUNGRY)
		printf("%ld %d has taken a fork\n", time_diff(start, get_time_in_ms()), id);
	else if (state == DEAD)
	{
		printf("%ld %d died\n", time_diff(start, get_time_in_ms()), id);
		free_all(table, 0);
		// Free everything first: Possible leak.
	}
	return ;
}

void	free_all(t_table *table, int error)
{
	free(table->philos);
	free(table->forks);
	if (error == 1)
		exit(1);
	pthread_exit(NULL);
}

time_t	time_diff(time_t t0, time_t t1)
{
	return (t1 - t0);
}

long int	get_time_in_ms(void)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return (t1.tv_sec * 1000 + t1.tv_usec / 1000);
}