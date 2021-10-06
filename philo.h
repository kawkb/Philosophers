/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:00:16 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/10/06 18:06:34 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

typedef	unsigned long t_time;

typedef     struct  s_philo
{
	pthread_t       *id;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	t_time			start;
	int             nbr;
	int             time_to_eat;
	int             time_to_sleep;
	int             time_to_die;
	int             must_eat_count;
	
}                   t_philo;

void	*life_of_a_philo(t_philo *philo);

#endif