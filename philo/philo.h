/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnane <adnane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:16:53 by adnane            #+#    #+#             */
/*   Updated: 2023/05/17 23:30:29 by adnane           ###   ########.fr       */
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
	int					last_meal;
	int					ate;
}	t_philosopher;

typedef struct s_thread
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		last_meal_mutex;
	pthread_mutex_t		eat_count_mutex;
	pthread_mutex_t		info_mutex;
	t_philosopher		*info;
	pthread_t			*philosophers;
	pthread_t			death_checker;
	pthread_t			eat_counter;
	int					num_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					eat_count;
	int					all_ate;
	int					very_start;
}	t_thread;

int		parse_arguments(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		get_period(int start_ms);
void	print_message(t_thread *thread, int id, char *message);
void	free_all(t_thread *thread);
void	allocate(t_thread *thread);
void	set_thread_params(t_thread *thread, char **av);
void	create_threads(t_thread *thread);
void	initialize_mutexes(t_thread *thread);
void	create_philosophers(t_thread *thread);
void	*death_checker(void *arg);
void	*eat_counter(void *arg);
void	join_philosophers(t_thread *thread);
void	destroy_mutexes(t_thread *thread);
void	*philosopher(void *arg);
void	pick_up_forks(t_philosopher *info);
void	eat(t_philosopher *info);
void	put_down_forks(t_philosopher *info);
void	sleep_and_think(t_philosopher *info);

#endif
