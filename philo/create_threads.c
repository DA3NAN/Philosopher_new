/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:47:46 by adnane            #+#    #+#             */
/*   Updated: 2023/06/05 16:07:18 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_thread *thread)
{
	create_philosophers(thread);
	pthread_create(&thread->death_checker, NULL, death_checker, thread);
	if (thread->eat_count != -1)
		pthread_create(&thread->eat_counter, NULL, eat_counter, thread);
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
		thread->info[i].right_fork = &thread->forks[(i + 1)
			% thread->num_philo];
		thread->info[i].thread_info = thread;
		thread->info[i].last_meal = get_period(thread->very_start);
		thread->info[i].ate = 0;
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
	if (thread->eat_count != -1)
		pthread_join(thread->eat_counter, NULL);
}

void	destroy_mutexes(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
		pthread_mutex_destroy(&thread->forks[i]);
	pthread_mutex_destroy(&thread->print);
	pthread_mutex_destroy(&thread->last_meal_mutex);
	pthread_mutex_destroy(&thread->eat_count_mutex);
	pthread_mutex_destroy(&thread->all_ate_mutex);
	pthread_mutex_destroy(&thread->death_mutex);
	pthread_mutex_destroy(&thread->finish_mutex);
}

void	initialize_mutexes(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
		pthread_mutex_init(&thread->forks[i], NULL);
	pthread_mutex_init(&thread->print, NULL);
	pthread_mutex_init(&thread->last_meal_mutex, NULL);
	pthread_mutex_init(&thread->eat_count_mutex, NULL);
	pthread_mutex_init(&thread->all_ate_mutex, NULL);
	pthread_mutex_init(&thread->death_mutex, NULL);
	pthread_mutex_init(&thread->finish_mutex, NULL);
}
