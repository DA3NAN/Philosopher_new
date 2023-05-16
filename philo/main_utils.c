/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:39:34 by adnane            #+#    #+#             */
/*   Updated: 2023/05/16 22:40:11 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	allocate(t_thread *thread)
{
	thread->philosophers = malloc(thread->num_philo * sizeof(pthread_t));
	thread->forks = malloc(thread->num_philo * sizeof(pthread_mutex_t));
	thread->info = malloc(thread->num_philo * sizeof(t_philosopher));
}
