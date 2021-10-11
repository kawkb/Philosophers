/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:59:38 by kdrissi-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/10 00:08:53 by kdrissi-         ###   ########.fr       */
=======
/*   Updated: 2021/10/09 13:08:49 by kdrissi-         ###   ########.fr       */
>>>>>>> 10e6f321463b0ef428fe88b13f55d6591c2bc4ad
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *str, int index)
{
	t_time currently;

	currently = now() - philo->start;
	pthread_mutex_lock(&philo->print);
	printf("%d time %d id %s\n",currently , index, str);
	pthread_mutex_unlock(&philo->print);
}

void	zzzz(t_time	time)
{
	t_time	this_time;

	this_time = now();
<<<<<<< HEAD
	usleep((time * 1000 * 0.85));
	while (now() <= this_time + time)
		;
=======
	usleep(time  * 1000 * 0.85);
	while (now() < this_time + time)
		continue ;
>>>>>>> 10e6f321463b0ef428fe88b13f55d6591c2bc4ad
}

void	eating(t_philo *philo, int index)
{
	pthread_mutex_lock(philo->fork[index]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork[(index + 1) % philo->nbr); // ta da % philo.nbr;
	print(philo, "has taken a fork");
	philo->last_time_eated[index] = now();
	print(philo, "is eating");
	philo->is_eating[index] = 1;
	zzzz(philo->time_to_eat);
	philo->is_eating[index] = 0;
	pthread_mutex_unlock(philo->fork[index]);
	pthread_mutex_unlock(philo->fork[(index + 1) % philo->nbr]);
	if (philo->check1[index]++ == philo->must_eat_count)
		check2++;
}

void	sleeping(t_philo *philo, int index)
{
	print(philo, "is sleeping", index);
	zzzz(philo->time_to_sleep);
}

void	*life_of_a_philo(void *philo)
{
	int		index;

	philo = (t_philo*)philo;
	index = philo->index;
	while (1)
	{
		eating(philo, index);
		sleeping(philo, index);
		print(philo, "is thinking", index);
	}
}

t_time	time_passed(t_time last_time_eated)
{
	retun(now() - last_time_eated);
}

void	checker(t_philo *philo)
{
	int		i;

	i = 0;
	while(1)
	{
		while (i < philo->nbr)
		{
			if(must_eat_count >= 0 && philo->check2 >= philo->nbr)
			{
				pthread_mutex_lock(&philo->print);
				return;
			}
			if(!philo->is_eating[i] && time_passed(philo->last_time_eated[i]) > philo->time_to_die)
			{
				pthread_mutex_lock(&philo->print);
				printf("%d time %d id died\n", now() -  philo->start, i);
				return;
			}
			i++;
		}
		i = 0; 
	}
}

int		main(int ac, char **av)
{
	t_philo		*philo;

	if (!get_input(ac, av, philo))
		return(1);
	if (!create(philo))
		return(1);
	checker(philo);
	clear_all(philo);
	return(0);
}

