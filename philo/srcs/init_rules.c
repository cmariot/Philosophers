/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:08:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/04 11:08:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Convert an array of char to an unsigned int
unsigned int	atou(char *str)
{
	unsigned int	number;
	int				number_len;
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (-2);
	number = 0;
	number_len = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = (number * 10) + (str[i++] - '0');
			number_len++;
		}
		else
			return (-2);
	}
	if (number_len > 10)
		return (-2);
	return (number);
}

// The philo structure contains an ID, a pointer to the structure rules,
// and some useful variables for the threads
int	init_philo(t_rules *rules)
{
	int	i;

	rules->philo = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!rules->philo)
	{
		print_fd("Error, during the malloc of rules->philo\n", 2);
		return (-1);
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].rules = rules;
		rules->philo[i].eat_counter = 0;
		if (rules->philo[i].id == rules->nb_philo)
			rules->philo[i].r_philo = &rules->philo[0];
		else
			rules->philo[i].r_philo = &rules->philo[i + 1];
		pthread_mutex_init(&(rules->philo[i].fork), NULL);
		i++;
	}
	return (0);
}

// The rules structure contains the program arguments, a pointer on philo
// and some general variables used by the program
int	init_rules(t_rules *rules, char **argv, int argc)
{
	rules->nb_philo = atou(argv[1]);
	rules->t_die = atou(argv[2]);
	rules->t_eat = atou(argv[3]);
	rules->t_sleep = atou(argv[4]);
	if (argc == 6)
		rules->must_eat = atou(argv[5]);
	else
		rules->must_eat = -1;
	if (rules->nb_philo <= 0 || rules->nb_philo > 10000
		|| rules->t_eat <= 0 || rules->t_sleep <= 0 || rules->t_die <= 0
		|| rules->must_eat == 0 || rules->must_eat < -1)
	{
		if (rules->nb_philo > 10000)
			print_fd("Error, too much philosophers.\n", 2);
		else
			print_fd("Error, arguments must be > 0 and <= INT_MAX.\n", 2);
		return (0);
	}
	rules->everybody_ate = 0;
	rules->dead = 0;
	pthread_mutex_init(&rules->print_status, NULL);
	pthread_mutex_init(&rules->check_dead, NULL);
	if (init_philo(rules) == -1)
		return (0);
	return (1);
}
