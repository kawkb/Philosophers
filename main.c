/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:59:38 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/10/04 13:14:53 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	
}

int		main(int ac, char **av)
{
	int			i;
	t_thread	*th;

	i = 0;
	if (ac == 6 || ac == 5)
	{
		while ( i <= ac)
		{
			pthread_create(th, NULL, &routine, NULL);
		}
	}
	else
		//check errors
}