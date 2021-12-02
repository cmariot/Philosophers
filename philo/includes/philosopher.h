/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/02 10:39:41 by cmariot          ###   ########.fr       */
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
# define THREAD_FAILED 6

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
	int				must_eat;
	int				everybody_ate;
	int				dead;
	size_t			init_time;
	pthread_mutex_t	print_status;
	pthread_mutex_t	check_dead;
	t_philo			*philo;
}	t_rules;

// in the file main.c
int				main(int argc, char **argv);
int				usage(void);

// in the file init_rules.c
int				init_rules(t_rules *rules, char **argv, int argc);
int				init_philo(t_rules *rules);
unsigned int	atou(char *str);

// in the file get_time.c
size_t			get_time(void);

// in the file create_threads.c
int				create_threads(t_rules *rules);
void			wait_threads(pthread_t *thread_id, t_rules *rules);

//in the file routine.c
void			*routine(void *add);
void			eat(t_philo *philo);
void			go_to_sleep(t_rules *rules, size_t time);

// in the file print_status.c
void			print_status(t_philo *philo, int status);
int				print_fd(char *str, int fd);

// in the file check_end.c
void			check_end(t_rules *rules);
int				check_dead(t_rules *rules);
int				check_eat(t_rules *rules);

// in the file clean_exit.c
void			clean_exit(t_rules *rules, pthread_t *thread_id);

#endif
