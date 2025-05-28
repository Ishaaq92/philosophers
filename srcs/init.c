/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:17 by ishaaq            #+#    #+#             */
/*   Updated: 2025/05/28 23:32:59 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 1;
	while (i <= table->info.nbr_of_philos)
	{
		philo = &table->philos[i];
		philo->id = i;
		philo->state = HUNGRY;
		philo->fork = &table->forks[i];
		if (i == 1)
			philo->o_fork = &table->forks[table->info.nbr_of_philos];
		else
			philo->o_fork = &table->forks[((i - 1) % table->info.nbr_of_philos)];
		// printf("%d, %d\n", philo->id, ((i - 1) % table->info->nbr_of_philos));
		// for (int i = 0; i < table->info->nbr_of_philos; i++)
		// 	pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(philo->fork, NULL);
		philo->last_meal = get_time_in_ms();
		i ++;
	}
}

t_info	init_info(int ac, char **av)
{
	t_info	info;

	info.start = get_time_in_ms();
	info.nbr_of_philos = ft_atoi(av[1]);
	info.go = 0;
	info.ttd = (long) ft_atoi(av[2]);
	info.tte = (long) ft_atoi(av[3]);
	info.tts = (long) ft_atoi(av[4]);
	return (info);
}

t_table	init_table(int ac, char *av[], t_info info)
{
	t_table			table;
	struct timeval	start;
	int				i;

	i = 1;
	table.info = info;
	table.ready = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table.ready, NULL);
	table.philos = malloc(sizeof(t_philo) * (info.nbr_of_philos + 1));
	if (!table.philos)
		exit(1);
	table.forks = malloc(sizeof(pthread_mutex_t) * (info.nbr_of_philos + 1));
	if (!table.forks)
	{
		free(table.philos);
		exit(1);	
	}
	table.states = malloc(sizeof(t_state *) * (info.nbr_of_philos + 1));
	while (i <= info.nbr_of_philos)
		table.states[i++] = malloc(sizeof(t_state));
	init_philos(&table);
	return (table);
}
