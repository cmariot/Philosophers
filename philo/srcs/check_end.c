/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:41:21 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/02 12:20:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Compare the number of time each philosopher ate with
// number_of_times_each_philosopher_must_eat
int	check_eat(t_rules *rules)
{
	int	philosophers_who_have_all_eat;
	int	i;

	i = 0;
	philosophers_who_have_all_eat = 0;
	pthread_mutex_lock(&rules->check_dead);
	while (i < rules->nb_philo)
	{
		if (rules->philo[i].eat_counter >= rules->must_eat)
			philosophers_who_have_all_eat++;
		i++;
	}
	pthread_mutex_unlock(&rules->check_dead);
	if (philosophers_who_have_all_eat != rules->nb_philo)
		return (0);
	else
	{
		rules->everybody_ate = 1;
		return (1);
	}
}

// If a philosopher don't eat after time_to_die, he'll die.
int	check_dead(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&rules->check_dead);
	while (i < rules->nb_philo)
	{
		if (get_time() > rules->philo[i].last_meal + (size_t)rules->t_die)
		{
			print_status(&rules->philo[i], DIED);
			rules->dead = 1;
			pthread_mutex_unlock(&rules->check_dead);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&rules->check_dead);
	return (0);
}

// Loop ends when there is a dead,
// or when everybody has eaten number_of_times_each_philosopher_must_eat
void	check_end(t_rules *rules)
{
	while (1)
	{
		if (check_dead(rules) == 1)
			break ;
		if (rules->must_eat != -1)
			if (check_eat(rules) == 1)
				break ;
	}
}
