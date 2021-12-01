/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/01 12:03:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// The philo program takes 4 (the 5th is optional) arguments :
// ./philo [nb_philo] [t_die] [t_eat] [t_sleep]
// [optional : number_of_times_each_philosopher_must_eat]
int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc == 5 || argc == 6)
	{
		if (init_rules(&rules, argv, argc))
			create_threads(&rules);
		return (0);
	}
	else
	{
		print_fd("Usage : ./philo [nb_philo] ", 2);
		print_fd("[t_die] [t_eat] [t_sleep] ", 2);
		print_fd("[optional : must_eat]\n", 2);
		return (-1);
	}
}
