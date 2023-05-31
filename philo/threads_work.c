/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:55 by adnane            #+#    #+#             */
/*   Updated: 2023/05/31 14:05:58 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_philosopher	*info;

	info = (t_philosopher *)arg;
	if (info->id % 2 != 0)
		usleep(info->thread_info->time_to_eat * 1000);
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
	pthread_mutex_lock(info->left_fork);
	print_message(info->thread_info, info->id, "picked up left fork.");
	pthread_mutex_lock(info->right_fork);
	print_message(info->thread_info, info->id, "picked up rigth fork.");
}

void	eat(t_philosopher *info)
{
	print_message(info->thread_info, info->id, "is eating...");
	pthread_mutex_lock(&info->thread_info->last_meal_mutex);
	info->last_meal = get_period(info->thread_info->very_start);
	pthread_mutex_unlock(&info->thread_info->last_meal_mutex);
	ft_sleep(info->thread_info->time_to_eat);
	pthread_mutex_lock(&info->thread_info->eat_count_mutex);
	if (info->thread_info->eat_count != -1
		&& info->ate < info->thread_info->eat_count)
		info->ate++;
	pthread_mutex_unlock(&info->thread_info->eat_count_mutex);
}

void	put_down_forks(t_philosopher *info)
{
	pthread_mutex_unlock(info->right_fork);
	pthread_mutex_unlock(info->left_fork);
	print_message(info->thread_info, info->id, "put Down both forks.");
}

void	sleep_and_think(t_philosopher *info)
{
	print_message(info->thread_info, info->id, "is sleeping...");
	ft_sleep(info->thread_info->time_to_sleep);
	print_message(info->thread_info, info->id, "is thinking...");
}
