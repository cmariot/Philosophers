/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:41:21 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/27 16:22:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// If a philosopher don't eat after time_to_die, he'll die.
void	check_dead(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_lock(&rules->check_dead);
		if (get_time() - rules->philo[i].last_meal > (size_t)rules->t_die)
		{
			print_status(&rules->philo[i], DIED);
			rules->dead = 1;
		}
		pthread_mutex_unlock(&rules->check_dead);
		if (rules->dead == 1)
			return ;
		i++;
	}
}

// Compare the number of time each philosopher ate with
// number_of_times_each_philosopher_must_eat
void	check_eat(t_rules *rules)
{
	int	philosophers_who_have_all_eat;
	int	i;

	i = 0;
	philosophers_who_have_all_eat = 0;
	while (i < rules->nb_philo)
	{
		if (rules->philo[i].eat_counter == rules->must_eat)
			philosophers_who_have_all_eat++;
		i++;
	}
	if (philosophers_who_have_all_eat == rules->nb_philo)
		rules->everybody_eat = 1;
}

// Loop ends when there is a dead,
// or when everybody has eaten number_of_times_each_philosopher_must_eat
void	check_end(t_rules *rules)
{
	while (1)
	{
		check_dead(rules);
		if (rules->dead)
			break ;
		if (rules->must_eat != -1)
		{
			check_eat(rules);
			if (rules->everybody_eat == 1)
				break ;
		}
	}
}
