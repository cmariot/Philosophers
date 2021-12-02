/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:44:45 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/01 16:56:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Print a string on the file descriptor fd
int	print_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		if (write(fd, &str[i++], 1) == -1)
			return (-1);
	return (i);
}

// Print an integer on STDOUT
int	ft_putnbr(int n)
{
	long int	nb;
	char		*base_dec;
	int			i;

	nb = n;
	base_dec = "0123456789";
	i = 0;
	if ((nb >= 0) && (nb <= 9))
	{
		i = write(1, &base_dec[nb], 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		i = write(1, &base_dec[nb % 10], 1);
	}
	return (i);
}

// Print timestamp X status
// Use a mutex to avoid the print of 2 status at the same time
void	print_status(t_philo *philo, int status)
{
	size_t	timestamp;

	pthread_mutex_lock(&philo->rules->print_status);
	if (status == THREAD_FAILED)
		print_fd("Error, pthread_create() failed\n", 2);
	else if (!philo->rules->dead && !philo->rules->everybody_ate)
	{
		timestamp = get_time() - philo->rules->init_time;
		ft_putnbr(timestamp);
		print_fd(" ", 1);
		ft_putnbr(philo->id);
		if (status == FORK && !philo->rules->dead)
			print_fd(" has taken a fork\n", 1);
		else if (status == EAT && !philo->rules->dead)
			print_fd(" is eating\n", 1);
		else if (status == SLEEP && !philo->rules->dead)
			print_fd(" is sleeping\n", 1);
		else if (status == THINK && !philo->rules->dead)
			print_fd(" is thinking\n", 1);
		else if (status == DIED && !philo->rules->dead)
			print_fd(" died\n", 1);
	}
	pthread_mutex_unlock(&philo->rules->print_status);
}
