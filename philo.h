/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:29:22 by ishaaq            #+#    #+#             */
/*   Updated: 2025/03/02 10:33:56 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
};

typedef struct s_philo
{
	enum e_state	state; 
}   t_philo;

typedef struct s_table
{
	t_philo	*philosophers;
	int		nbr_of_philos;
	int		forks_on_table;
	int		ttd;
	int		tte;
	int		tts;
}	t_table;


# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

#endif