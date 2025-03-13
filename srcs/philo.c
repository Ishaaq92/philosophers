/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/13 08:44:42 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int ac, char *av[])
{
	struct timeval	t0;
	struct timeval	t1;
	t_table			table;
	
	gettimeofday(&t0, NULL);
	table = init_table(ac, av);
	// if (i % 2 == 0)
	// 	pthread_create(&table->philos[i].thread, NULL, eat, &state);
	gettimeofday(&t1, NULL);
	printf("%ld %d\n", t1.tv_sec - t0.tv_sec, t1.tv_usec - t0.tv_usec);
	free_all(&table, 0);
}
