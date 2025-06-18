/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:26 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/16 19:47:26 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = table->philos;
	i = 0;
	while (++i <= table->info.nbr_of_philos)
	{
		printf("here");
		pthread_create(&philos[i].thread, NULL, routine, NULL);	
	}
}

void	join_thread(t_table *table)
{
	t_philo	*philos;
	int		i;
	void	*ptr;

	philos = table->philos;
	i = 0;
	ptr = NULL;
	while (++i < table->info.nbr_of_philos)
	{
		pthread_join(philos[i].thread, ptr);
	}
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
