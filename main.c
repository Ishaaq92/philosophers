/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/20 12:43:28 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start(t_table *table)
{
	t_philo	*philos;
	int		i;

	pthread_mutex_lock(table->info.sim);
	philos = table->philos;
	if (table->info.nbr_of_philos == 1)
		return (pthread_mutex_unlock(table->info.sim), single_philo(table));
	i = 0;
	while (++i <= table->info.nbr_of_philos)
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	usleep(table->info.tte * 1000 / 2);
	pthread_mutex_unlock(table->info.sim);
	monitoring(table);
	return(NULL);
}

static void	join_thread(t_table *table)
{
	t_philo	*philos;
	int		i;
	void	*ptr;

	i = 0;
	philos = table->philos;
	ptr = NULL;
	while (++i <= table->info.nbr_of_philos)
		pthread_join(philos[i].thread, ptr);
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
}

int	main(int ac, char **av)
{
	t_info	info;
	t_table	table;
	
	if (ac != 5 && ac != 6)
		return (1);
   init_info(&info, ac, av);
   init_table(&table, &info);
   init_philos(&table, &info);
   start(&table);
   join_thread(&table);
   free_all(&table);
}
