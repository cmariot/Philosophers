/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:45:49 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/02 13:22:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// A custom usleep function
void	go_to_sleep(t_rules *rules, size_t time)
{
	size_t	start_time;

	if (!rules->dead && !rules->everybody_ate)
	{
		start_time = get_time();
		while (get_time() < start_time + time)
		{
			usleep(500);
		}
	}
	return ;
}

// Take the forks when they are available and wait t_to_eat,
// Print status and use mutex
void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_status(philo, FORK);
	if (philo->rules->nb_philo == 1)
	{
		go_to_sleep(philo->rules, philo->rules->t_die);
		print_status(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		philo->rules->dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->r_philo->fork);
	print_status(philo, FORK);
	print_status(philo, EAT);
	go_to_sleep(philo->rules, philo->rules->t_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_philo->fork);
	return ;
}

// The function called by the threads, will not end until there is a dead
// or if everybody eaten number_of_times_each_philosopher_must_eat
void	*routine(void *add)
{
	t_philo	*philo;

	philo = (t_philo *)add;
	if (philo->id % 2 == 0)
		go_to_sleep(philo->rules, 100);
	while (!philo->rules->dead && !philo->rules->everybody_ate)
	{
		eat(philo);
		print_status(philo, SLEEP);
		go_to_sleep(philo->rules, philo->rules->t_sleep);
		print_status(philo, THINK);
	}
	return (NULL);
}
