/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:36:03 by adnane            #+#    #+#             */
/*   Updated: 2023/06/01 15:09:41 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_int(char *str)
{
	int			i;
	long long	num;

	i = 0;
	while (str[i])
	{
		if (i > 10)
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num < 0 || num > INT_MAX)
		return (0);
	return (1);
}

int	is_num(char **argv)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	x = 4;
	if (argv[5])
		x++;
	while (i <= x)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j])
				&& !(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo <number_of_philosophers> ");
		printf("<time_to_die> <time_to_eat> <time_to_sleep> ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!is_num(argv)
		|| !is_valid_int(argv[2]) || ft_atoi(argv[2]) == 0
		|| !is_valid_int(argv[4]) || ft_atoi(argv[4]) == 0
		|| !is_valid_int(argv[3]) || ft_atoi(argv[3]) == 0
		|| !is_valid_int(argv[1]) || ft_atoi(argv[1]) == 0
		|| (argv[5] && !is_valid_int(argv[5])))
	{
		printf("All arguments must be strictly positive integers.\n");
		return (1);
	}
	return (0);
}
