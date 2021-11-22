/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/22 13:30:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_alive(t_philo *philo)
{
	if (philo->is_alive == 1 || philo->rules->a_philo_died == 0)
		return (1);
	else
		return (0);
}

void	*new_thread(void *philo_add)
{
	t_philo *philo;
	int	timestamp;

	philo = (t_philo *)philo_add;
	printf("Philosopher created, his ID is %d\n", philo->id);
	while (is_alive(philo))
	{
		//Take the left fork
		if (philo->rules->a_philo_died == 0)
		{
			timestamp = get_time() - philo->rules->init_time;
			printf("%d %d has taken a fork\n", timestamp, philo->id);
		}
		//Take the right fork
		if (philo->rules->a_philo_died == 0)
		{
			//if he has the left fork -> take the right fork
			//else drop the left fork
			timestamp = get_time() - philo->rules->init_time;
			printf("%d %d has taken a fork\n", timestamp, philo->id);
		}
		//Eat (time_to_eat)
		if (philo->rules->a_philo_died == 0)
		{
			//Check if the philosopher has 2 forks
			timestamp = get_time() - philo->rules->init_time;
			printf("%d %d is eating\n", timestamp, philo->id);
			usleep(philo->rules->time_to_eat);
			//Drop the 2 forks
		}
		//Sleep (time_to_sleep)
		if (philo->rules->a_philo_died == 0)
		{
			timestamp = get_time() - philo->rules->init_time;
			printf("%d %d is sleeping\n", timestamp, philo->id);
			usleep(philo->rules->time_to_sleep);
		}
		//Think
		if (philo->rules->a_philo_died == 0)
		{
			timestamp = get_time() - philo->rules->init_time;
			printf("%d %d is thinking\n", timestamp, philo->id);
		}
		if (philo->id == 1)
		{
			usleep(1000000);
			timestamp = get_time() - philo->rules->init_time;
			printf("%d %d died\n", timestamp, philo->id);
			philo->is_alive = 0;
			philo->rules->a_philo_died = 1;
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
		if (pthread_join(rules->philo[i++].philo_thread, NULL) == 0)
			break ;
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
