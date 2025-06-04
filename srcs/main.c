/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/04 14:58:11 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	print_table_data(t_table *table)
// {
// 	printf("Philo ID: %d\n", table->philos[1].id);
// 	// printf("Philo ID: %d\n", table->philos[1].fork);
// 	printf("Philo last meal seconds: %ld\n", table->philos[1].last_meal.tv_sec);
// 	printf("Philo last meal mseconds: %ld\n", table->philos[1].last_meal.tv_usec);
// 	printf("Philo state: %d\n", table->philos[1].state);
// }

void	*checks(void *arg)
{
	t_table	*table;
	t_philo	*philos;

	table = (t_table *) arg;	
	philos = table->philos;
	int		i;

	table = (t_table *)arg;
	i = 0;
	pthread_mutex_lock(table->ready);
	pthread_mutex_unlock(table->ready);
	while (42)
	{
		if (time_diff(philos[i].last_meal, get_time_in_ms()) >= table->info.ttd)
			return (printf("%d has died   --monitoring\n", i), NULL);
	}
}

void	monitoring(t_table *table)
{
	pthread_t	*monitor;

	monitor = malloc(sizeof(pthread_t));
	pthread_create(monitor, NULL, checks, table);
}

int main(int ac, char *av[])
{
	t_table	table;
	t_info	info;
	void	*ptr;
	int		i;

	if (ac != 5)
		exit(1);
	info = init_info(ac, av);
	table = init_table(ac, av, info);
	start(&table);
	ptr = NULL;
	i = 1;
	monitoring(&table);
	while (i <= info.nbr_of_philos)
		pthread_join(table.philos[i++].thread, ptr);
	printf("ptr has a value \n");
	free_all(&table, 0);
}
