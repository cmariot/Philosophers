/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:08:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/25 11:14:41 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned int	ft_atou(char *str)
{
	unsigned int	number;
	int				number_len;
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			printf("Error : philo only supports unsigned int arguments.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
		{
			printf("Error : philo only supports unsigned int arguments.\n");
			exit(EXIT_FAILURE);
		}
	}
	if (number_len > 10)
	{
		printf("Error : an argument is too big\n");
		exit(EXIT_FAILURE);
	}
	return (number);
}

void	init_struct(t_philo *philo, char **argv, int argc)
{
	philo->number_of_philosophers = ft_atou(argv[1]);
	philo->time_to_die = ft_atou(argv[2]);
	philo->time_to_eat = ft_atou(argv[3]);
	philo->time_to_sleep = ft_atou(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atou(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = 0;
}
