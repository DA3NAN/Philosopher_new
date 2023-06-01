/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_eat_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:20:28 by adnane            #+#    #+#             */
/*   Updated: 2023/06/01 15:47:23 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*died(t_thread *thread, int i)
{
	print_message(thread, thread->info[i].id, "died");
	pthread_mutex_lock(&thread->death_mutex);
	thread->died = 1;
	pthread_mutex_unlock(&thread->death_mutex);
	pthread_mutex_lock(&thread->finish_mutex);
	thread->finish = 1;
	pthread_mutex_unlock(&thread->finish_mutex);
	return (NULL);
}

static void	ate_enough(t_thread *thread)
{
	pthread_mutex_lock(&thread->print);
	pthread_mutex_lock(&thread->all_ate_mutex);
	thread->all_ate = 1;
	pthread_mutex_unlock(&thread->all_ate_mutex);
	printf("|%d| All philosophers have eaten enough.\n",
		get_period(thread->very_start));
	pthread_mutex_lock(&thread->finish_mutex);
	thread->finish = 1;
	pthread_mutex_unlock(&thread->finish_mutex);
	pthread_mutex_unlock(&thread->print);
	return ;
}

void	*death_checker(void *arg)
{
	t_thread	*thread;
	int			i;
	int			curr;
	int			finish;

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
				died(thread, i);
		}
		pthread_mutex_lock(&thread->finish_mutex);
		finish = thread->finish;
		pthread_mutex_unlock(&thread->finish_mutex);
		if (finish == 1)
			return (NULL);
	}
}

static void	check_for_count(t_thread *thread, int done_eating_count)
{
	int	i;
	int	ec;
	int	ate;

	i = -1;
	while (++i < thread->num_philo)
	{
		pthread_mutex_lock(&thread->eat_count_mutex);
		ec = thread->eat_count;
		ate = thread->info[i].ate;
		pthread_mutex_unlock(&thread->eat_count_mutex);
		if (ate >= ec)
			done_eating_count++;
		if (done_eating_count == thread->num_philo)
			ate_enough(thread);
	}
}

void	*eat_counter(void *arg)
{
	t_thread	*thread;
	int			done_eating_count;
	int			finish;

	thread = (t_thread *)arg;
	done_eating_count = 0;
	while (1)
	{
		done_eating_count = 0;
		check_for_count(thread, done_eating_count);
		pthread_mutex_lock(&thread->finish_mutex);
		finish = thread->finish;
		pthread_mutex_unlock(&thread->finish_mutex);
		if (finish == 1)
			return (NULL);
	}
}
