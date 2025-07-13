/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:05:46 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/12 10:51:16 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    precise_action(t_philo *philo, int tta)
{
    long    stop_time;
    
    stop_time = get_time_in_ms() + tta;
    // Check for simulation
    while (get_time_in_ms() < stop_time && get_sim(philo) == 0)
        usleep(500);
    return ;
}
