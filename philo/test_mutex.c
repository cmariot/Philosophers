/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:19:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/23 14:45:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

int	pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

int	main(void)
{
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	return (0);
}
