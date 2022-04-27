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
	tmp = find_time();
	printf("%lld %s %ld\n", tmp - p->data->start_time, str, p->index);
	pthread_mutex_unlock(&p->data->print_mut);
}

void	ft_sleep(t_philo *p)
{
	long long int tmp;

	tmp = find_time();
	while ((find_time() - tmp) < p->data->time_eat)
	{
		usleep(50);
	}
}

void	*check_philo(void *p)
{
	while (1)
	{}
	return (p);
}