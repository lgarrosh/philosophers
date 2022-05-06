/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:35:09 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/06 19:22:28 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "semaphore.h"
# include <signal.h>

typedef struct s_philo
{
	int				number_philo;
	int				number_fork;
	int				time_did;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
	int				eat_count;
	int				stop;
	int				*pid;
	sem_t			*sem_printf;
	sem_t			*sem_data;
	sem_t			*sem_fork;
	long long int	start_time;
	int				index;
	long long int	t_meal;
	pthread_t		check_monitor;
}			t_philo;

//liba_bonus.c
long long int	ft_atoi(const char *str);
int				ft_strlen(const char *str);
long long int	find_time(void);
void			ft_sleep(long long int time);
//error_bonus.c
int				ft_error(const char *error);
void			ft_exit(t_philo **philo, const char *error);
//init_bonus.c
int				init_data(int argc, char **argv, t_philo *philo);
int				init_philo(int argc, char **argv, t_philo **philo);
//utils_bonus.c
void			print_phil(t_philo *p, const char *str);
void			print_eating(t_philo *p);
void			*check_philo(void *args);

#endif