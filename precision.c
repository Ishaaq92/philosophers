/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:05:46 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/20 09:11:56 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    precise_action(t_philo *philo, int tta)
{
    long    stop_time;
    (void) philo ;
    stop_time = get_time_in_ms() + tta;
    while (get_time_in_ms() < stop_time)
    {
        usleep(100);
    }
    return ;
}