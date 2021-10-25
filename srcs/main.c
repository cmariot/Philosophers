/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/25 11:29:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
