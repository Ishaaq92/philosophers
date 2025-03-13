/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/13 07:40:18 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int ac, char *av[])
{
	struct timeval	t0;
	struct timeval	t1;
	t_table			table;
	
	table = init_table(ac, av);	
	gettimeofday(&t0, NULL);
	// threads	= malloc(sizeof(pthread_t) * 4);	
	// i = 1;	
	// while (i < 3)
	// {
	// 	pthread_create(&threads[i++], NULL, your_turn, NULL);
	// }
	// sleep(10);
	gettimeofday(&t1, NULL);
	printf("%ld %d\n", t1.tv_sec - t0.tv_sec, t1.tv_usec - t0.tv_usec);
	free_all(&table);
}
