/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:42:51 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/05 16:53:30 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_philo;
	int				number_fork;
	int				time_did;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
	int				stop;
	pthread_t		pth_check;
	pthread_t		*pth;
	pthread_mutex_t	print_mut;
	pthread_mutex_t	data_mut;
	pthread_mutex_t	*forks;
	long long int	start_time;
}			t_data;

typedef struct s_philo
{
	size_t			index;
	long long int	t_meal;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	pthread_t		*pth;
	int				count_eat;
	t_data			*data;
	long long int	start_philo;
}			t_philo;

//main.c
int				philosophers(t_data *data);
void			*start(void *args);
int				ft_creat_thread(t_philo *philo, t_data *data);
//liba.c
long long int	ft_atoi(const char *str);
int				ft_strlen(const char *str);
void			ft_sleep(long long int time);
long long int	find_time(void);
//init.c
int				init_data(int argc, char **argv, t_data **basic);
int				init_philo(t_philo *philo, t_data *data);
int				init_philos(t_philo **philo, t_data *data);
//error.c
int				ft_error(const char *error);
void			ft_free(t_philo *philo);
//utils.c
void			print_phil(t_philo *p, const char *str);
void			print_eating(t_philo *p);
void			*check_philo(void *args);
void			taken_fork(t_philo *p);
int				nujobilo(t_philo *p);

#endif