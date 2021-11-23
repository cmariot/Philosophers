/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:19:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/23 07:24:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

int	pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

int	main(void)
{
	pthread_mutex_t *left_fork = NULL;

	pthread_mutex_init(left_fork, NULL);
	return (0);
}
