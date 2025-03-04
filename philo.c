/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:25 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/02 10:59:19 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		total = (total * 10) + (nptr[i] - 48);
		i ++;
	}
	return (sign * total);
}

void    *your_turn(void *arg)
{
	while (1)
	{
		printf("Your turn\n");
		sleep(2);
	}
}

void    my_turn(void)
{
	printf("hello world\n");
	while (1)
	{
		printf("My turn\n");
		sleep(1);
	}
}

t_table	init_philos(t_table *table)
{
	t_philo	philosopher;
	int		i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		table->philosophers[i].state = ;
	}
}


t_table	init_table(int ac, char *av[])
{
	t_table			table;

	if (ac != 4)
	exit(1);
	table.nbr_of_philos = ft_atoi(av[1]);
	table.forks_on_table = ft_atoi(av[1]);
	table.ttd = ft_atoi(av[2]);
	table.tte = ft_atoi(av[3]);
	table.tts = ft_atoi(av[4]);
	init_philos(&table);
	return (table);
}

int main(int ac, char *av[])
{
	pthread_t		*threads;
	int				i;
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
	// gettimeofday(&t1, NULL);
	printf("%d %d %d %d %d \n", table.nbr_of_philos, table.forks_on_table, table.ttd, table.tte, table.tts);
	printf("%ld %d\n", t1.tv_sec- t0.tv_sec, t1.tv_usec-t0.tv_usec);
}
