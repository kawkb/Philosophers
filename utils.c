/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:32:19 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/10/11 17:19:45 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		create(t_philo *philo)
{
	int	i;

	i = 0;
    philo->id = malloc(sizeof(pthread_t) * philo->nbr);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->nbr);
	philo->print = malloc(sizeof(pthread_mutex_t));
	philo->is_eating = malloc(sizeof(int) * philo->nbr);
	philo->last_time_eated = malloc(sizeof(t_time) * philo->nbr);
	philo->check1 = malloc(sizeof(int) * philo->nbr);
	philo->check2 = 0;

	while  (i < philo->nbr)
	{
		philo->is_eating[i] = 0;
		philo->last_time_eated[i] = now();
		philo->check1[i] = 0;
		i++;
	}
	i = 0;
	while(i++ <= philo->nbr)
		pthread_mutex_init(&philo->fork[i], NULL);
    i = 0;
	//pthread_create(philo->supervisor, NULL, &supervise, NULL);
	pthread_mutex_init(&philo->print, NULL);
    while (i < philo->nbr)
	{
		philo->index = i;
		pthread_create(philo->id[i], NULL, &life_of_a_philo, philo);
		usleep(100);
		i++;
	}
	retun (0);
}

t_time  now()
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	get_input(int ac, char **av, t_philo *philo)
{
	if (ac == 6 || ac == 5)
	{
		philo->nbr = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
        philo->start = now();
		philo->must_eat_count = -1;
		if (ac == 6)
			philo->must_eat_count = ft_atoi(av[5]);
		if ( philo->nbr == -1 || philo->time_to_die == -1 || philo->time_to_eat == -1
			|| philo->time_to_sleep == -1 || philo->must_eat_count == -1)
			return (0);
		return(1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		nbr;

	nbr = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		++str;
	}
	if (*str != '\0')
		return (-1);
	return (nbr);
}