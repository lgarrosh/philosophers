#include "../include/philo.h"

int ft_error(const char *error)
{
	int len;

	len = 0;
	while (error[len])
		len++;
	write(2, error, len);
	write(1, "\n", 1);
	return (1);
}

void	ft_exit(t_philo *philo, t_data *data, const char *error)
{
	int	i;

	i = -1;
	while (++i < philo->data->number_fork)
		pthread_mutex_destroy((philo + i)->lf);
	pthread_mutex_destroy(&philo->data->print_mut);
	pthread_mutex_destroy(&philo->data->data_mut);
	free((void *)philo);
	philo = NULL;
	free((void *)data->forks);
	data->forks = NULL;
	free((void *)data->pth);
	data->pth = NULL;
	free((void *)data);
	if (error)
		exit(ft_error(error));
	exit(0);
}