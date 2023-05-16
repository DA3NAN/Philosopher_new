/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:20:02 by adnane            #+#    #+#             */
/*   Updated: 2023/05/16 22:43:57 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_thread	thread;

	parse_arguments(ac, av);
	thread.num_philo = ft_atoi(av[1]);
	allocate(&thread);
}
