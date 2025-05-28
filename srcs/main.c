/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/05/28 15:22:32 by isahmed          ###   ########.fr       */
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

int main(int ac, char *av[])
{
	t_table	table;
	int		i;
	void	*ptr;

	i = 1;
	table = init_table(ac, av);
	start(&table);
	ptr = NULL;
	while (i <= table.nbr_of_philos)
	{
		pthread_join(table.philos[i].thread, ptr);
		i++;
	}
	// while (!ptr)
	// 	continue;
	printf("ptr has a value \n");
	free_all(&table, 0);
}
