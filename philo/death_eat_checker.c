/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_eat_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:20:28 by adnane            #+#    #+#             */
/*   Updated: 2023/05/17 16:54:39 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_checker(void *arg)
{
	t_thread	*thread;
	int			i;
	int			curr;

	thread = (t_thread *)arg;
	while (1)
	{
		i = -1;
		while (++i < thread->num_philo)
		{
			pthread_mutex_lock(&thread->last_meal_mutex);
			curr = get_period(thread->very_start) - thread->info[i].last_meal;
			pthread_mutex_unlock(&thread->last_meal_mutex);
			if (curr >= thread->time_to_die)
			{
				print_message(thread, thread->info[i].id, "died");
				exit(0);
			}
		}
		usleep(1000);
	}
}

static void	check_for_count(t_thread *thread, int done_eating_count)
{
	int	i;

	i = -1;
	while (++i < thread->num_philo)
	{
		pthread_mutex_lock(&thread->eat_count_mutex);
		if (thread->info[i].ate >= thread->eat_count)
			done_eating_count++;
		if (done_eating_count == thread->num_philo)
		{
			pthread_mutex_lock(&thread->print);
			thread->all_ate = 1;
			printf("|%d| All philosophers have eaten enough.\n",
				get_period(thread->very_start));
			pthread_mutex_unlock(&thread->print);
			exit (0);
		}
		pthread_mutex_unlock(&thread->eat_count_mutex);
	}
}

void	*eat_counter(void *arg)
{
	t_thread	*thread;
	int			done_eating_count;

	thread = (t_thread *)arg;
	done_eating_count = 0;
	while (1)
	{
		done_eating_count = 0;
		check_for_count(thread, done_eating_count);
		usleep(1000);
	}
}
