/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/11/25 18:14:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5

typedef struct s_philo {
	int				id;
	int				eat_counter;
	size_t			last_meal;
	pthread_mutex_t	fork;
	struct s_philo	*r_philo;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules {
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				min_eat;
	int				everybody_eat;
	int				dead;
	size_t			init_time;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
}	t_rules;

// in the file main.c
int				main(int argc, char **argv);
int				usage(void);

// in the file init_rules.c
void			init_rules(t_rules *rules, char **argv, int argc);
void			init_philo(t_rules *rules);
unsigned int	atou(char *str);
void			atou_errors(int ref);
size_t			get_time(void);

// in the file create_threads.c
void			create_threads(t_rules *rules);

//in the file routine.c
void			*routine(void *add);

// in the file print_status.c
void			print_status(t_philo *philo, int status);

// in the file check_dead.c
void			check_dead(t_rules *rules);

// in the file clean_exit.c
void			clean_exit(t_rules *rules, pthread_t *thread_id);

#endif
