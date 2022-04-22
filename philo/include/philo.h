#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo
{
    size_t number;
    size_t time_did;
    size_t time_eat;
    size_t time_sleep;
}			t_philo;

//liba.c
long long int	ft_atoi(const char *str);

#endif