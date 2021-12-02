/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:03:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/02 14:04:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Destroy the mutex and free the malloc
void	clean_exit(t_rules *rules, pthread_t *thread_id)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(&rules->check_dead);
	pthread_mutex_destroy(&rules->print_status);
	free(rules->philo);
	rules->philo = NULL;
	if (thread_id)
	{
		free(thread_id);
		thread_id = NULL;
	}
	usleep(1000);
	return ;
}
