/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:39:34 by adnane            #+#    #+#             */
/*   Updated: 2023/06/02 18:39:18 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocate(t_thread *thread)
{
	thread->philosophers = malloc(thread->num_philo * sizeof(pthread_t));
	if (!thread->philosophers)
		return (0);
	thread->forks = malloc(thread->num_philo * sizeof(pthread_mutex_t));
	if (!thread->forks)
		return (free(thread->philosophers), 0);
	thread->info = malloc(thread->num_philo * sizeof(t_philosopher));
	if (!thread->info)
		return (free(thread->philosophers), free(thread->forks), 0);
	return (1);
}

void	set_thread_params(t_thread *thread, char **av)
{
	thread->very_start = get_period(0);
	thread->time_to_die = ft_atoi(av[2]);
	thread->time_to_sleep = ft_atoi(av[4]);
	thread->time_to_eat = ft_atoi(av[3]);
	thread->eat_count = -1;
	thread->all_ate = 0;
	thread->died = 0;
	thread->finish = 0;
	if (av[5])
		thread->eat_count = ft_atoi(av[5]);
}

int	get_period(int start_ms)
{
	struct timeval	current_time;
	int				current_ms;

	gettimeofday(&current_time, NULL);
	current_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (current_ms - start_ms);
}

void	print_message(t_thread *thread, int id, char *message)
{
	pthread_mutex_lock(&thread->print);
	pthread_mutex_lock(&thread->death_mutex);
	pthread_mutex_lock(&thread->all_ate_mutex);
	if (!thread->all_ate && !thread->died)
		printf("|%d| Philosopher %d %s\n",
			get_period(thread->very_start), id + 1, message);
	pthread_mutex_unlock(&thread->print);
	pthread_mutex_unlock(&thread->death_mutex);
	pthread_mutex_unlock(&thread->all_ate_mutex);
}

void	free_all(t_thread *thread)
{
	if (thread->philosophers)
		free(thread->philosophers);
	if (thread->forks)
		free(thread->forks);
	if (thread->info)
		free(thread->info);
}
