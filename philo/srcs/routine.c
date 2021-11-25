/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:45:49 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 18:12:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	go_to_sleep(t_rules *rules, size_t time)
{
	size_t	current_time;

	current_time = get_time();
	while (!rules->dead)
	{
		if (get_time() - current_time >= time)
			break ;
		usleep(100);
	}
}

void	eat(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&philo->fork);
	print_status(philo, FORK);
	if (rules->nb_philo == 1)
	{
		go_to_sleep(rules, rules->t_die);
		print_status(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		rules->dead++;
		return ;
	}
	pthread_mutex_lock(&philo->r_philo->fork);
	print_status(philo, FORK);
	pthread_mutex_lock(&rules->check);
	print_status(philo, EAT);
	philo->eat_counter++;
	philo->last_meal = get_time();
	go_to_sleep(rules, rules->t_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_philo->fork);
	pthread_mutex_unlock(&rules->check);
}

void	*routine(void *add)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)add;
	rules = (t_rules *)philo->rules;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!rules->dead && !rules->everybody_eat)
	{
		eat(philo);
		print_status(philo, SLEEP);
		go_to_sleep(rules, rules->t_sleep);
		print_status(philo, THINK);
	}
	return (NULL);
}
