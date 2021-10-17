/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/16 15:53:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;

	if (argc == 5 || argc == 6)
	{
		number_of_philosophers = ft_atou(argv[1]);
		time_to_die = ft_atou(argv[2]);
		time_to_eat = ft_atou(argv[3]);
		time_to_sleep = ft_atou(argv[4]);
		number_of_times_each_philosopher_must_eat = 0;
		if (argc == 6)
			number_of_times_each_philosopher_must_eat = ft_atou(argv[5]);
		printf("1 = %d\n2 = %d\n3 = %d\n4 = %d\n5 = %d\n",
			number_of_philosophers, time_to_die, time_to_eat, time_to_sleep,
			number_of_times_each_philosopher_must_eat);
	}
	else
	{
		printf("Usage :\n");
		return (0);
	}
}
