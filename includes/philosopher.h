/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/04 15:54:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo {
	pthread_t	philo_thread;
	int			id;
	int			number_of_philosophers;
	int			number_of_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			min_number_of_eat;
}	t_philo;

typedef struct s_rules {
	int		number_of_philosophers;
	int		number_of_forks;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		min_number_of_eat;
	t_philo	*philo;
}	t_rules;

int		main(int argc, char **argv);
void	init_rules(t_rules *rules, char **argv, int argc);

#endif
