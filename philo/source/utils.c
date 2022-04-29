#include "../include/philo.h"

long long int	find_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	print_phil(t_philo *p, const char *str)
{
	long long int tmp;

	pthread_mutex_lock(&p->data->print_mut);
	if (!p->data->stop)
	{
		tmp = find_time();
		printf("%lld %ld %s\n", tmp - p->data->start_time, p->index, str);
	}
	pthread_mutex_unlock(&p->data->print_mut);
}

void	ft_sleep(long long int time, t_data *d)
{
	long long int tmp;

	tmp = find_time();
	while (!d->stop)
	{
		if ((find_time() - tmp) >= time)
			break;
		usleep(50);
	}
}

void	*check_philo(void *args)
{
	t_philo	*p;
	int		i;
	int		check;

	p = (t_philo *)args;
	while (!p->data->stop)
	{
		i = -1;
		check = 1;
		while (++i < p->data->number_philo)
		{
			if (find_time() - (p + i)->t_meal > p->data->time_did)
			{
				print_phil((p + i), "did");
				p->data->stop = 1;
			}
		}
		i = -1;
		if(p->data->nbr_eat > 0)
			while (++i < p->data->number_philo)
				if ((p + i)->count_eat != p->data->nbr_eat)
					check = 0;
		if (check == 1 && p->data->nbr_eat > 0)
			p->data->stop = 1;
	}
	return (p);
}