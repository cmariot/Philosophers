/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:08:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/25 11:27:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	atou_errors(int ref, t_philo *philo)
{
	if (ref == 1)
		printf("Error : philo only supports unsigned int arguments.\n");
	else if (ref == 2)
		printf("Error : an argument is too big\n");
	free(philo);
	exit(EXIT_FAILURE);
}

unsigned int	ft_atou(char *str, t_philo *philo)
{
	unsigned int	number;
	int				number_len;
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			atou_errors(1, philo);
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
			atou_errors(1, philo);
	}
	if (number_len > 10)
		atou_errors(2, philo);
	return (number);
}

void	init_struct(t_philo *philo, char **argv, int argc)
{
	philo->number_of_philosophers = ft_atou(argv[1], philo);
	philo->time_to_die = ft_atou(argv[2], philo);
	philo->time_to_eat = ft_atou(argv[3], philo);
	philo->time_to_sleep = ft_atou(argv[4], philo);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atou(argv[5], philo);
	else
		philo->number_of_times_each_philosopher_must_eat = 0;
}
