/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:25:04 by ishaaq            #+#    #+#             */
/*   Updated: 2025/04/14 16:48:12 by isahmed          ###   ########.fr       */
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

void	free_all(t_table *table, int error)
{
	free(table->philos);
	free(table->forks);
	if (error == 1)
		exit(1);
	exit(0);
}

time_t	time_val_diff(time_t t0, time_t t1)
{
	return (t1 - t0);
}

void	print_ts(struct timeval t, int id)
{
	printf("%ld %d has ", t.tv_sec*1000000 + t.tv_usec, id);
}

long int	get_time_in_ms(void)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return (t1.tv_sec * 1000 + t1.tv_usec / 1000);
}