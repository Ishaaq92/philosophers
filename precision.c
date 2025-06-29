/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:05:46 by ishaaq            #+#    #+#             */
/*   Updated: 2025/06/29 18:16:14 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    precise_action(int tta)
{
    long    stop_time;
    
    stop_time = get_time_in_ms() + tta;
    while (get_time_in_ms() < stop_time)
        usleep(500);
    return ;
}
