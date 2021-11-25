/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:41:21 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 18:08:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	check_dead(t_rules *rules)
{
	int	i;

	while (!rules->everybody_eat)
	{
		i = 0;
		while (!rules->dead && i++ < rules->nb_philo)
		{
			pthread_mutex_lock(&rules->check);
			if (get_time() - rules->philo[i].last_meal > (size_t)rules->t_die)
			{
				print_status(&rules->philo[i], DIED);
				rules->dead = 1;
			}
			pthread_mutex_unlock(&rules->check);
			usleep(100);
		}
		if (rules->dead == 1)
			break ;
		i = 0;
		while (rules->min_eat != -1 && i < rules->nb_philo
			&& rules->philo[i].eat_counter >= rules->min_eat)
			i++;
		if (i == rules->nb_philo)
			rules->everybody_eat = 1;
	}
}
