/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/26 11:53:25 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_table *table)
{
	int		i;

	i = 1;
	printf("init_philo\n");
	while (i <= table->nbr_of_philos)
	{
		table->philos[i].id = i;
		printf("f: ID = %d\n", table->philos[i].id);
		table->philos[i].state = HUNGRY;
		table->philos[i].fork = &table->forks[i];
		pthread_mutex_init(table->philos[i].fork, NULL);
		table->philos[i].last_meal.tv_sec = 0;
		table->philos[i].last_meal.tv_usec = 0;
		i ++;
	}
}

t_table	init_table(int ac, char *av[])
{
	t_table			table;

	if (ac != 5)
		exit(1);
	table.nbr_of_philos = ft_atoi(av[1]);
	table.philos = malloc(sizeof(t_philo) * (table.nbr_of_philos + 1));
	if (!table.philos)
		exit(1);
	table.forks = malloc(sizeof(pthread_mutex_t) * (table.nbr_of_philos + 1));
	if (!table.forks)
	{
		free(table.philos);
		exit(1);	
	}
	table.ttd = ft_atoi(av[2]);
	table.tte = ft_atoi(av[3]);
	table.tts = ft_atoi(av[4]);
	init_philos(&table);
	return (table);
}
