/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:55 by adnane            #+#    #+#             */
/*   Updated: 2023/05/17 15:22:07 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_philosopher	*info;

	info = (t_philosopher *)arg;
	while (1)
	{
		pick_up_forks(info);
		eat(info);
		put_down_forks(info);
		sleep_and_think(info);
	}
}

void	pick_up_forks(t_philosopher *info)
{
	if (info->id % 2 != 0)
	{
		pthread_mutex_lock(info->left_fork);
		print_message(info->thread_info->very_start, info->id,
			"picked up the left fork.", &info->thread_info->print);
		pthread_mutex_lock(info->right_fork);
		print_message(info->thread_info->very_start, info->id,
			"picked up the right fork.", &info->thread_info->print);
	}
	else
	{
		pthread_mutex_lock(info->right_fork);
		print_message(info->thread_info->very_start, info->id,
			"picked up the right fork.", &info->thread_info->print);
		pthread_mutex_lock(info->left_fork);
		print_message(info->thread_info->very_start, info->id,
			"picked up the left fork.", &info->thread_info->print);
	}
}

void	eat(t_philosopher *info)
{
	print_message(info->thread_info->very_start, info->id,
		"is eating...", &info->thread_info->print);
	pthread_mutex_lock(&info->thread_info->last_meal_mutex);
	info->last_meal = get_period(info->thread_info->very_start);
	pthread_mutex_unlock(&info->thread_info->last_meal_mutex);
	usleep(info->thread_info->time_to_eat * 1000);
}

void	put_down_forks(t_philosopher *info)
{
	pthread_mutex_unlock(info->right_fork);
	print_message(info->thread_info->very_start, info->id,
		"put down the right fork.", &info->thread_info->print);
	pthread_mutex_unlock(info->left_fork);
	print_message(info->thread_info->very_start, info->id,
		"put down the left fork.", &info->thread_info->print);
}

void	sleep_and_think(t_philosopher *info)
{
	print_message(info->thread_info->very_start, info->id,
		"is sleeping...", &info->thread_info->print);
	usleep(info->thread_info->time_to_sleep * 1000);
	print_message(info->thread_info->very_start, info->id,
		"is thinking...", &info->thread_info->print);
}
