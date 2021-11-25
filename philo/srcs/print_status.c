/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:44:45 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 17:37:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_philo *philo, int status)
{
	size_t	timestamp;

	timestamp = get_time() - philo->rules->init_time;
	pthread_mutex_lock(&philo->rules->print);
	if (!philo->rules->dead && !philo->rules->everybody_eat)
	{
		printf("%lu %d ", timestamp, philo->id);
		if (status == FORK)
			printf("has taken a fork\n");
		else if (status == EAT)
			printf("is eating\n");
		else if (status == SLEEP)
			printf("is sleeping\n");
		else if (status == THINK)
			printf("is thinking\n");
		else if (status == DIED)
			printf("died\n");
	}
	pthread_mutex_unlock(&philo->rules->print);
}
