/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/05 05:43:59 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*eat(void *arg)
{
	t_philo			*philo;	
	struct timeval	time;

	if (philo)
	gettimeofday(&time, NULL);
	philo = (t_philo *)arg;
	printf("")
	sleep(philo->t.tte);
}

void	init_philos(t_table *table)
{
	int		i;

	i = 1;
	printf("init_philo\n");
	while (i < table->nbr_of_philos)
	{
		table->philos[i].id = i;
		table->philos[i].state = HUNGRY;
		table->philos[i].fork = NOT_USING;
		table->philos[i].last_meal.tv_sec = 0;
		table->philos[i].last_meal.tv_usec = 0;
		table->philos[i].t = table->t;
		if (i % 2 == 0)
			pthread_create(&table->philos[i].thread, NULL, eat, &table->philos[i]);
		i ++;
	}
}

t_table	init_table(int ac, char *av[])
{
	t_table			table;

	if (ac != 5)
		exit(1);
	table.nbr_of_philos = ft_atoi(av[1]);
	table.philos = malloc(sizeof(t_philo) * table.nbr_of_philos + 1);
	if (!table.philos)
		exit(1);
	table.forks_on_table = ft_atoi(av[1]);
	table.t.ttd = ft_atoi(av[2]);
	table.t.tte = ft_atoi(av[3]);
	table.t.tts = ft_atoi(av[4]);
	init_philos(&table);
	return (table);
}