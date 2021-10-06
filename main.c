/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:59:38 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/10/06 18:27:46 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *str)
{
	t_time currently;

	currently = now() - philo->start;
	pthread_mutex_lock(&philo->print);
	printf("%d time %d id %s\n",currently , philo->id, str);
	pthread_mutex_unlock(&philo->print);
}

void	eating(t_philo *philo)
{
	// take forks;
	pthread_mutex_lock(philo->fork[i]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork[i + 1]); // tada % philo.nbr;
	print(philo, "has taken a fork");
	print(philo, "is eating");
	//wait time to eat time;
	pthread_mutex_unlock(philo->fork[i]);
	pthread_mutex_unlock(philo->fork[i + 1]);
}

void	*life_of_a_philo(t_philo *philo)
{
	while (1)
	{
		eating(philo);
		print(philo, "is sleeping");
		thinking();
	}
}

int		main(int ac, char **av)
{
	t_philo		*philo;

	if (!get_input(ac, av, philo))
		return(1);
	if (!create(philo))
		return;
	checker();
}
// eating sleeping thinking