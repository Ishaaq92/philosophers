/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:32:47 by isahmed           #+#    #+#             */
/*   Updated: 2025/06/04 18:19:50 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_stop(t_table *table)
{
	int	stop;

	pthread_mutex_lock(table->simulation);
	stop = table->info.stop;
	pthread_mutex_unlock(table->simulation);
	return (stop);
}


void	set_stop(t_table *table, int val)
{
	pthread_mutex_lock(table->simulation);	
	table->info.stop = val;
	pthread_mutex_unlock(table->simulation);
}
