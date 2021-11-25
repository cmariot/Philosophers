/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:16:11 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 18:18:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Wait the end of all the threads to continue,
// The main program will not stop until all the threads are closed
void	wait_threads(pthread_t *thread_id, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
}

// Error management for the create_threads function
void	create_threads_errors(int error, t_rules **rules, pthread_t **thread_id)
{
	if (error == 1)
	{
		printf("Error, the malloc of thread_id in create_threads() failed\n");
		clean_exit(*rules, *thread_id);
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		printf("Error, cannot create thread in create_threads()\n");
		clean_exit(*rules, *thread_id);
		exit(EXIT_FAILURE);
	}
}

// Create a thread for each philosopher and launch the routine() in the threads
void	create_threads(t_rules *rules)
{
	pthread_t	*thread_id;
	int			i;

	thread_id = malloc(sizeof(pthread_t) * rules->nb_philo);
	if (!thread_id)
		create_threads_errors(1, &rules, &thread_id);
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_create(&thread_id[i], NULL, &routine, &rules->philo[i]))
			create_threads_errors(2, &rules, &thread_id);
		pthread_mutex_lock(&rules->check);
		rules->philo[i].last_meal = rules->init_time;
		pthread_mutex_unlock(&rules->check);
		i++;
	}
	check_dead(rules);
	wait_threads(thread_id, rules);
	clean_exit(rules, thread_id);
	return ;
}
