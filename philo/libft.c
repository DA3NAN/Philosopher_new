/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:41:13 by adnane            #+#    #+#             */
/*   Updated: 2023/05/31 17:24:33 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long double	result;
	int			sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + ((char)*str - 48);
		if (result >= 9223372036854775807UL && sign > 0)
			return (-1);
		else if (result >= 9223372036854775808UL && sign < 0)
			return (0);
		str++;
	}
	return ((int)result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_sleep(int time_in_ms)
{
	int	time_initiale;

	time_initiale = get_period(0);
	while (get_period(time_initiale) < time_in_ms)
		usleep(200);
}
