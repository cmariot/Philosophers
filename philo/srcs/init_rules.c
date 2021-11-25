/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:08:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 18:14:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//Get the time in seconds and microseconds since midnight, January 1, 1970.
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

//If an argument is negative or too long print a message and exit
void	atou_errors(int ref)
{
	if (ref == 1)
		printf("Error : philo only supports unsigned int arguments.\n");
	else if (ref == 2)
		printf("Error : an argument is too big\n");
	exit(EXIT_FAILURE);
}

//Convert an array of char to an unsigned int
unsigned int	atou(char *str)
{
	unsigned int	number;
	int				number_len;
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			atou_errors(1);
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
			atou_errors(1);
	}
	if (number_len > 10)
		atou_errors(2);
	return (number);
}

// The philo structure contains an ID, a pointer to the structure rules,
// and some useful variables for the threads
void	init_philo(t_rules *rules)
{
	int	i;

	rules->philo = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!rules->philo)
	{
		printf("Error, during the malloc of rules->philo\n");
		exit(EXIT_FAILURE);
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
}

// The rules structure contains the program arguments, a pointer on philo
// and some general variables used by the program
void	init_rules(t_rules *rules, char **argv, int argc)
{
	rules->nb_philo = atou(argv[1]);
	rules->t_die = atou(argv[2]);
	rules->t_eat = atou(argv[3]);
	rules->t_sleep = atou(argv[4]);
	if (argc == 6)
		rules->min_eat = atou(argv[5]);
	else
		rules->min_eat = -1;
	if (rules->nb_philo <= 0 || rules->t_die <= 0
		|| rules->t_eat <= 0 || rules->t_sleep <= 0
		|| rules->min_eat == 0 || rules->min_eat < -1)
	{
		printf("Error, invalid argument(s), they must be positive and > 0.\n");
		exit(EXIT_FAILURE);
	}
	rules->everybody_eat = 0;
	rules->dead = 0;
	pthread_mutex_init(&rules->print, NULL);
	pthread_mutex_init(&rules->check, NULL);
	init_philo(rules);
	rules->init_time = get_time();
	return ;
}
