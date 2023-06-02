/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:20:02 by adnane            #+#    #+#             */
/*   Updated: 2023/06/02 18:49:35 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_thread	thread;

	if (parse_arguments(ac, av))
		return (1);
	thread.num_philo = ft_atoi(av[1]);
	if (!allocate(&thread))
		return (1);
	set_thread_params(&thread, av);
	initialize_mutexes(&thread);
	create_threads(&thread);
	free_all(&thread);
	return (0);
}
