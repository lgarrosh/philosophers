#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
# include "semaphore.h"

typedef struct s_data
{
	int				number_philo;
	int				number_fork;
	int				time_did;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
    int				num_eat_count;
	int				stop;
    int				*pid;
    sem_t			*block_printf;
	sem_t			*block_fork;
	long long int	start_time;
    int				index;
	long long int	t_meal;
	pthread_t		check_monitor;
}			t_data;

#endif