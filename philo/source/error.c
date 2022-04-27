#include "../include/philo.h"

int ft_error(const char *error)
{
	perror(error);
	return (1);
}

void	ft_exit(t_philo *philo, t_data *data, const char *error)
{
	int i;

	i = -1;
	while (++i < data->number_philo)
	{
		free((void *)(philo + i)->lf);
		(philo + i)->lf = NULL;
		free((void *)(philo + i)->pth);
		(philo + i)->pth = NULL;
	}
	free((void *)data);
	free((void *)philo);
	if (error)
		exit(ft_error(error));
}