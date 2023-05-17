/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:47:46 by adnane            #+#    #+#             */
/*   Updated: 2023/05/17 15:14:29 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_thread *thread)
{
	create_philosophers(thread);
	// create_death_checker(thread);
	pthread_create(&thread->death_checker, NULL, death_checker, thread);
	join_philosophers(thread);
	destroy_mutexes(thread);
}

void	create_philosophers(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
	{
		thread->info[i].id = i;
		thread->info[i].left_fork = &thread->forks[i];
		thread->info[i].right_fork = &thread->forks[(i + 1) % thread->num_philo];
		thread->info[i].thread_info = thread;
		thread->info[i].last_meal = get_period(thread->very_start);
		pthread_create(&thread->philosophers[i],
			NULL, philosopher, &thread->info[i]);
	}
}

void	join_philosophers(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
		pthread_join(thread->philosophers[i], NULL);
	pthread_join(thread->death_checker, NULL);
}

void	destroy_mutexes(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
		pthread_mutex_destroy(&thread->forks[i]);
}

void	initialize_mutexes(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
		pthread_mutex_init(&thread->forks[i], NULL);
	pthread_mutex_init(&thread->print, NULL);
	pthread_mutex_init(&thread->last_meal_mutex, NULL);
}
