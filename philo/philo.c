/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:20:02 by adnane            #+#    #+#             */
/*   Updated: 2023/05/17 12:58:30 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_thread	thread;

	if (parse_arguments(ac, av))
		return (1);
	thread.num_philo = ft_atoi(av[1]);
	allocate(&thread);
	set_thread_params(&thread, av);
	initialize_mutexes(thread);
	create_threads(&thread);
	return (0);
}
