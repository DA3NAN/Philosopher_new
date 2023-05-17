/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:47:46 by adnane            #+#    #+#             */
/*   Updated: 2023/05/17 13:03:29 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_thread *thread)
{
	create_philosophers(thread);
	join_philosophers(thread);
	destroy_mutexes(thread);
}

void	create_philosophers(t_thread *thread)
{
	int	i;

	i = 0;
	while (++i < thread->num_philo)
	{
		thread->info[i].id = i;
		thread->info[i].left_fork = &thread->forks[i];
		thread->info[i].right_fork = &thread->forks[(i + 1) % thread->num_philo];
		thread->info[i].thread_info = thread;
		pthread_create(&thread->philosophers[i],
			NULL, philosopher, &thread->info[i]);
	}
}

void	join_philosophers(t_thread *thread)
{
	int	i;

	i = 0;
	while (++i < thread->num_philo)
		pthread_join(thread->philosophers[i], NULL);
}

void	destroy_mutexes(t_thread *thread)
{
	int	i;

	i = 0;
	while (++i < thread->num_philo)
		pthread_mutex_destroy(&thread->forks[i]);
}

void	initialize_mutexes(t_thread thread)
{
	int	i;

	i = 0;
	while (++i < thread.num_philo)
		pthread_mutex_init(&thread.forks[i], NULL);
	pthread_mutex_init(&thread.print, NULL);
}
