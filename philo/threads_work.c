/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:55 by adnane            #+#    #+#             */
/*   Updated: 2023/05/18 14:48:07 by adnane           ###   ########.fr       */
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

// int	have_ate_more_than_other(t_philosopher *info)
// {
// 	int	i;
// 	int	last_meal_i;
// 	int	diff;

// 	i = -1;
// 	while (++i < info->thread_info->num_philo)
// 	{
// 		last_meal_i =  info->thread_info->info[i].last_meal;
// 		pthread_mutex_lock(&info->thread_info->last_meal_mutex);
// 		diff = info->last_meal - last_meal_i;
// 		pthread_mutex_unlock(&info->thread_info->last_meal_mutex);
// 		if (diff < 0)
// 			return (1);
// 	}
// 	return (0);
// }

void	pick_up_forks(t_philosopher *info)
{
	// if (have_ate_more_than_other(info))
	// 	return ;
	pthread_mutex_lock(info->right_fork);
	print_message(info->thread_info, info->id, "picked up the right fork.");
	pthread_mutex_lock(info->left_fork);
	print_message(info->thread_info, info->id, "picked up the left fork.");
}

void	eat(t_philosopher *info)
{
	print_message(info->thread_info, info->id, "is eating...");
	pthread_mutex_lock(&info->thread_info->last_meal_mutex);
	info->last_meal = get_period(info->thread_info->very_start);
	pthread_mutex_unlock(&info->thread_info->last_meal_mutex);
	usleep(info->thread_info->time_to_eat * 1000);
	pthread_mutex_lock(&info->thread_info->eat_count_mutex);
	if (info->thread_info->eat_count != -1 && info->ate < info->thread_info->eat_count)
		info->ate++;
	pthread_mutex_unlock(&info->thread_info->eat_count_mutex);
}

void	put_down_forks(t_philosopher *info)
{
	pthread_mutex_unlock(info->right_fork);
	pthread_mutex_unlock(info->left_fork);
	print_message(info->thread_info, info->id, "put down both forks.");
}

void	sleep_and_think(t_philosopher *info)
{
	print_message(info->thread_info, info->id, "is sleeping...");
	usleep(info->thread_info->time_to_sleep * 1000);
	print_message(info->thread_info, info->id, "is thinking...");
}
