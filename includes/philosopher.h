/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/26 20:39:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo {
	int	number_of_philosophers;
	int	number_of_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_number_of_eat;
}	t_philo;

int		main(int argc, char **argv);
void	init_struct(t_philo *philo, char **argv, int argc);

#endif
