/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:43:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/16 15:55:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned int	ft_atou(char *str)
{
	unsigned int	number;
	int				number_len;
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	number = 0;
	number_len = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i++] - '0');
		number_len++;
	}
	if (number_len > 10)
		return (0);
	return (number);
}
