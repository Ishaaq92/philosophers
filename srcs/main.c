/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/05/28 22:19:29 by isahmed          ###   ########.fr       */
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
	while (i <= info.nbr_of_philos)
		pthread_join(table.philos[i++].thread, ptr);
	printf("ptr has a value \n");
	// free_all(&table, 0);
}
