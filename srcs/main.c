/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/26 22:18:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_thread(void *str)
{
	int	i;

	i = 0;
	printf("Test %p\n", str);
	while (1)
	{
	}
	pthread_detach(str);
	return (NULL);
}

void	create_threads(t_philo *philo, char **argv)
{
	pthread_t	*thread;
	int			i;
	void		*test;

	thread = malloc(sizeof(pthread_t) * philo->number_of_philosophers);
	if (!thread)
	{
		printf("Error, cannot create threads\n");
		free(philo);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		test = argv[i + 1];
		pthread_create(&thread[i], NULL, philo_thread, &test);
		printf("Philosopher %d created\n", i + 1);
		test = NULL;
		i++;
	}
	while (1)
	{
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
		{
			printf("Error : Malloc philo int main()\n");
			return (-1);
		}
		init_struct(philo, argv, argc);
		printf("Success\n");
		create_threads(philo, argv);
		free(philo);
		return (0);
	}
	else
	{
		printf("Usage : ./philo [number_of_philosophers] ");
		printf("[time_to_die] [time_to_eat] [time_to_sleep] ");
		printf("[optional : number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
}
