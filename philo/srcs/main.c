/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:04:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 15:16:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Print an error message if the number of arguments isn't correct */
int	usage(void)
{
	printf("Usage : ./philo [nb_philo] ");
	printf("[t_die] [t_eat] [t_sleep] ");
	printf("[optional : min_nb_of_eat]\n");
	return (-1);
}

/*	The philo program takes 4 (the 5th is optional) arguments :
 *	./philo [nb_philo] [t_die] [t_eat] [t_sleep] [opt : min_nb_of_eat] */
int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
		return (usage());
	else
	{
		init_rules(&rules, argv, argc);
		create_threads(&rules);
		return (0);
	}
}
