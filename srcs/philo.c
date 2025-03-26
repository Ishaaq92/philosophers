/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/26 11:45:06 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start(t_table *table)
{
	t_state			state;
	int				i;

	i = 1;
	state.philo = table->philos;
	state.table = table;
	while (i < table->nbr_of_philos)
	{
		if (table->philos->id % 2 == 0)
		{
			// pthread_mutex_lock(&table->forks[i]);
			printf("philo %d is eating\n", table->philos->id);
		}
		i ++;
	}
}

void	print_table_data(t_table *table)
{
	printf("Philo ID: %d\n", table->philos[1].id);
}

int main(int ac, char *av[])
{
	struct timeval	t0;
	struct timeval	t1;
	t_table			table;

	gettimeofday(&t0, NULL);
	table = init_table(ac, av);
	gettimeofday(&t1, NULL);

	// print_table_data(&table);

	// start(&table);
	// printf("%ld %ld\n", t1.tv_sec - t0.tv_sec, t1.tv_usec - t0.tv_usec);
	free_all(&table, 0);
}
