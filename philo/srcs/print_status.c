/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:44:45 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/28 15:07:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Print str on STDERR
int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (i);
}

// Print timestamp X status
// Use a mutex to avoid the print of 2 status at the same time
void	print_status(t_philo *philo, int status)
{
	size_t	timestamp;

	pthread_mutex_lock(&philo->rules->print_status);
	if (status == THREAD_FAILED)
		print_error("Error, pthread_create() failed\n");
	else if (!philo->rules->dead && !philo->rules->everybody_eat)
	{
		timestamp = get_time() - philo->rules->init_time;
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
	pthread_mutex_unlock(&philo->rules->print_status);
	return ;
}
