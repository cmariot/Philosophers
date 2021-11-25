/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:03:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 18:35:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	clean_exit(t_rules *rules, pthread_t *thread_id)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->check);
	free(rules->philo);
	if (thread_id)
		free(thread_id);
}
