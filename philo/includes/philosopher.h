/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/22 10:50:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo {
	pthread_t		philo_thread;
	int				id;
	int				is_alive;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules {
	int		number_of_philosophers;
	int		number_of_forks;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		min_number_of_eat;
	t_philo	*philo;
	size_t	init_time;
	int		a_philo_died;
}	t_rules;

int		main(int argc, char **argv);
void	init_rules(t_rules *rules, char **argv, int argc);
size_t	get_time(void);

#endif
