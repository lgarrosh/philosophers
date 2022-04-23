#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data
{
    int number;
    int time_did;
    int time_eat;
    int time_sleep;
	int nbr_eat;
}			t_data;

typedef struct s_philo
{
	int	index;
}			t_philo;


//main.c
void			philosophers(t_data *data);
//liba.c
long long int	ft_atoi(const char *str);
//init.c
t_data			*init_data(int argc, char **argv);
//error.c
int				ft_error(const char *error);

#endif