/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/19 17:34:20 by ishaaq           ###   ########.fr       */
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
	usleep(table->info.tte * 1000 / 2);
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

void	free_all(t_table *table)
{
	int		i;
	t_info	info;
	t_philo	*philos;

	i = 0;
	info = table->info;
	philos = table->philos;
	while (++i <= info.nbr_of_philos)
		free(philos[i].fork);
	free(philos);
	free(info.print);
	free(info.sim);
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
   monitoring(&table);
   start(&table);
   join_thread(&table);
   free_all(&table);
}
