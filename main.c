/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:59:38 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/10/05 20:02:13 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	//lock the fork[i] and lock the fork[i + 1]; pthread_mutex_lock
	// printf("is eating!\n")
	//wait time to eat time;
	//unlock the forks; pthread_mutex_unlock
	//repeat;
	printf("%is sleeping!\n");
	printf("is thinking!\n");	
}

void	day_in_life_of_a_philo(pthread_t *philo, pthread_mutex_t *fork)
{
	eating();
	sleeping();
	thinking();
}
int	get_input(int ac, char **av, t_philo *philo)
{
	if (ac == 6 || ac == 5)
	{
		philo->nbr = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo->must_eat_count = ft_atoi(av[5]);
		if ( philo->nbr == -1 || philo->time_to_die == -1 || philo->time_to_eat == -1
			|| philo->time_to_sleep == -1 || philo->must_eat_count == -1)
			return (0);
		return(1);
	}
	return (0);
}
int		initiate(t_philo *philo)
{
	int	i;
	
	i = 0;
	while(i++ <= philo->nbr)
		pthread_mutex_init(&philo->fork[i], NULL)
}
int		allocate(t_philo	*philo)
{
	int	i;

	i = 0;
	philo->id = malloc(sizeof(pthread_t) * philo->nbr);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->nbr);

	
}

int		main(int ac, char **av)
{
	t_philo		*philo;

	if (!get_input(ac, av, philo))
		return(1);
	if(!allocate(philo))
		return(1);
	if (!initiate(philo))
		return(1);
	if (!create(philo))
		return;
}
// eating sleeping thinking