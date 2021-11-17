/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/17 13:44:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_alive(t_philo *philo)
{
	if (philo->is_alive == 1)
		return (1);
	else
		return (0);
}

void	*new_thread(void *philo_add)
{
	t_philo *philo;

	philo = (t_philo *)philo_add;
	printf("Philosopher created, his ID is %d\n", philo->id);
	while (is_alive(philo))
	{
		//Take the left fork
		//Take the right fork
		//Eat (time_to_eat)
		//Drop forks
		//Sleep (time_to_sleep)
		//Think
		if (philo->id == 1)
		{
			usleep(1000000);
			printf("philo 1 is dead\n");
			philo->is_alive = 0;
		}
	}
	return (NULL);
}

void	create_threads(t_rules *rules)
{
	int	i;

	//Create a thread for each philosopher
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_create(&rules->philo[i].philo_thread, NULL, &new_thread, &rules->philo[i]);
		i++;
	}
	//Wait the end of the threads
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		int test;

		test = pthread_join(rules->philo[i].philo_thread, NULL);
		if (test == 0)
			break ;
		i++;
	}
}

void *free_rules(t_rules **rules)
{
	free((*rules)->philo);
	(*rules)->philo = NULL;
	free(*rules);
	*rules = NULL;
	return (NULL);
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
		free_rules(&rules);
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
