/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/04 17:28:43 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start(t_table *table)
{
	t_state		*states;
	int			i;

	i = 0;
	states = table->states;
	pthread_mutex_lock(table->ready);
	while (++i <= table->info.nbr_of_philos)
	{
		states[i].id = i;
		states[i].table = table;
		states[i].philo = &table->philos[i];
		pthread_create(&table->philos[i].thread, NULL, routine, &states[i]);
	}
	table->info.t0 = get_time_in_ms();
	pthread_mutex_unlock(table->ready);
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
