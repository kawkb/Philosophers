/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:00:16 by kdrissi-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/10 00:09:53 by kdrissi-         ###   ########.fr       */
=======
/*   Updated: 2021/10/06 22:49:40 by kdrissi-         ###   ########.fr       */
>>>>>>> 10e6f321463b0ef428fe88b13f55d6591c2bc4ad
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
	pthread_t		supervisor;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	t_time			*last_time_eated;
	t_time			start;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_time			time_to_die;
	int				*check1;
	int				check2;
	int				must_eat_count;
	int				kayna;
	int				*is_eating;
	int             nbr;
	int				index;
	
}                   t_philo;

void	*life_of_a_philo(t_philo *philo);

#endif