#include "../include/philo.h"

t_data *init_data(int argc, char **argv)
{
	t_data *basic;

	basic = (t_data *)malloc(sizeof(t_data));
	if (!basic)
	{
		ft_error("ERROR: FAILED TO GET MEMORY");
		return (NULL);
	}
	basic->stop = 0;
	basic->start_time = find_time();
	basic->number_philo = ft_atoi(argv[1]);
	basic->number_fork = basic->number_philo;
	basic->time_did = ft_atoi(argv[2]);
	basic->time_eat = ft_atoi(argv[3]);
	basic->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		basic->nbr_eat = ft_atoi(argv[5]);
	else
		basic->nbr_eat = -2;
	if (basic->number_philo == -1 || basic->time_did == -1 || basic->nbr_eat == -1
		|| basic->time_eat == -1 || basic->time_sleep == -1)
	{
		ft_error("ERROR: INVALIDE ARGUMENT");
		free((void *)basic);
		return(NULL);
	}
	return (basic);
}

int	init_philos(t_philo **philo, t_data *data)
{
	pthread_mutex_t *forks;
	pthread_t		*pth;

	*philo = (t_philo *)malloc(sizeof(t_philo) * data->number_philo);
	if (!(*philo))
		return (1);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
				* data->number_fork);
	if (!forks)
	{
		free((void *)philo);
		return (1);
	}
	pth = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philo);
	if (!pth)
	{
		free((void *)philo);
		free((void *)forks);
		return (1);
	}
	init_philo(*philo, data,  forks, pth);
	return (0);
}

void	init_philo(t_philo *philo, t_data *data, pthread_mutex_t *forks, pthread_t *pth)
{
	int				i;
	long long int	time;

	i = -1;
	time = find_time();
	while(++i < data->number_philo)
	{
		if (i == 0)
		{
			(philo + i)->lf = forks + data->number_philo - 1;
			(philo + i)->rf = forks + i;
		}
		else
		{
			(philo + i)->lf = forks + i - 1;
			(philo + i)->rf = forks + i;
		}
		(philo + i)->pth = pth + i;
		(philo + i)->index = i + 1;
		(philo + i)->count_eat = 0;
		(philo + i)->data = data;
		(philo + i)->t_meal = time;
		pthread_mutex_init((philo + i)->lf, NULL);
	}
	if (pthread_mutex_init(&data->print_mut, NULL))
		ft_error("qwqwfqwf");
}