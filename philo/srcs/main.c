/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/30 14:28:06 by cmariot          ###   ########.fr       */
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
		print_error("Usage : ./philo [nb_philo] ");
		print_error("[t_die] [t_eat] [t_sleep] ");
		print_error("[optional : must_eat]\n");
		return (-1);
	}
}
