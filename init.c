/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:13:00 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/29 21:09:14 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_info *info, int ac, char **av)
{
	info->nbr_of_philos = ft_atoi(av[1]);
	info->ttd = ft_atoi(av[2]);
	info->tte = ft_atoi(av[3]);
	info->tts = ft_atoi(av[4]);
	info->rounds = -1;
	if (ac == 6)
		info->rounds = ft_atoi(av[5]);
	if (info->nbr_of_philos <= 0 || info->ttd <= 0 || info->tte < 0 || info->tts < 0 || info->rounds < -1 || info->rounds == 0)
		exit(1);
	info->print = malloc(sizeof(pthread_mutex_t));
	info->sim = malloc(sizeof(pthread_mutex_t));
	info->stop = malloc(sizeof(int));
	*info->stop = 0;
	if (!info->print || !info->sim)
		exit(1);
	pthread_mutex_init(info->print, NULL);
	pthread_mutex_init(info->sim, NULL);
}

void	init_table(t_table *table, t_info *info)
{
	table->info = *info;
	table->philos = malloc(sizeof(t_philo) * (info->nbr_of_philos + 1));
}

void	init_philos(t_table *table, t_info *info)
{
	int		i;
	t_philo	*philos;

	philos = table->philos;
	i = 0;
	philos[0].id = -1;
	philos[0].o_fork = NULL;
	while (++i <= info->nbr_of_philos)
	{
		philos[i].id = i;
		philos[i].info = *info;
		philos[i].start = -1;
		philos[i].last_meal = -1;
		philos[i].m_start = malloc(sizeof(pthread_mutex_t));
		philos[i].m_last_meal = malloc(sizeof(pthread_mutex_t));
		philos[i].fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i].fork, NULL);
		pthread_mutex_init(philos[i].m_start, NULL);
		pthread_mutex_init(philos[i].m_last_meal, NULL);
	}
	i = 1;
	while (++i <= info->nbr_of_philos)
		philos[i].o_fork = philos[i - 1].fork;
	philos[1].o_fork = philos[info->nbr_of_philos].fork;
}
