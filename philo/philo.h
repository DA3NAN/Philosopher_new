/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:16:53 by adnane            #+#    #+#             */
/*   Updated: 2023/05/16 22:42:51 by adnane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philosopher
{
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_thread		*thread_info;
	int					id;
}	t_philosopher;

typedef struct s_thread
{
	pthread_mutex_t		*forks;
	t_philosopher		*info;
	pthread_t			*philosophers;
	int					num_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					very_start;
}	t_thread;

int		parse_arguments(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	allocate(t_thread *thread);

#endif
