/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/04 17:23:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*new_thread(void *philo_add)
{
	t_philo *philo;

	philo = (t_philo *)philo_add;
	printf("Philosopher created, his ID is %d\n", philo->id);
	while (1)
	{
	}
	return (NULL);
}

void	create_threads(t_rules *rules)
{
	int	i;

	//Create a thread for each philosopher
	printf("Creation des threads pour chaque philosopher\n");
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_create(&rules->philo[i].philo_thread, NULL, new_thread, &rules->philo[i]);
		i++;
	}
	//Wait the end of the threads
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_join(rules->philo[i].philo_thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rules	*rules;

	if (argc == 5 || argc == 6)
	{
		rules = malloc(sizeof(t_rules));
		if (!rules)
		{
			printf("Error : Malloc rules in main()\n");
			return (-1);
		}
		init_rules(rules, argv, argc);
		create_threads(rules);
		free(rules);
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
