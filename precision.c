/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:05:46 by ishaaq            #+#    #+#             */
/*   Updated: 2025/07/11 19:47:05 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    precise_action(int tta)
{
    long    stop_time;
    
    stop_time = get_time_in_ms() + tta;
    // Check for simulation
    while (get_time_in_ms() < stop_time)
        usleep(500);
    return ;
}
