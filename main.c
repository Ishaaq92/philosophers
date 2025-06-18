/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/18 21:13:36 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = table->philos;
	i = 0;
	pthread_mutex_lock(table->info.sim);
	while (++i <= table->info.nbr_of_philos)
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	pthread_mutex_unlock(table->info.sim);
}

void	join_thread(t_table *table)
{
	t_philo	*philos;
	int		i;
	void	*ptr;

	i = 0;
	philos = table->philos;
	ptr = NULL;
	while (++i <= table->info.nbr_of_philos)
		pthread_join(philos[i].thread, ptr);
	if (ptr)
		printf("ptr has a value");
}

int	main(int ac, char **av)
{
	t_info	info;
	t_table	table;
	
	if (ac != 5)
		return (1);
   init_info(&info, av);
   init_table(&table, &info);
   init_philos(&table, &info);
   start(&table);
   join_thread(&table);
}
