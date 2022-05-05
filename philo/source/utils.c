/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:26:49 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/05 18:58:33 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_phil(t_philo *p, const char *str)
{
	long long int	time;

	time = find_time();
	pthread_mutex_lock(&p->data->print_mut);
	pthread_mutex_lock(&p->data->data_mut);
	if (!p->data->stop)
		printf("%lld %ld %s\n", time - p->data->start_time, p->index, str);
	pthread_mutex_unlock(&p->data->data_mut);
	pthread_mutex_unlock(&p->data->print_mut);
}

void	print_eating(t_philo *p)
{
	long long int	time;

	time = find_time();
	pthread_mutex_lock(&p->data->print_mut);
	pthread_mutex_lock(&p->data->data_mut);
	if (!p->data->stop)
	{
		printf("%lld %ld %s\n", time - p->data->start_time \
			, p->index, "has taken a fork");
		printf("%lld %ld %s\n", time - p->data->start_time \
			, p->index, "is eating");
		p->t_meal = find_time();
	}
	pthread_mutex_unlock(&p->data->data_mut);
	pthread_mutex_unlock(&p->data->print_mut);
}

void	taken_fork(t_philo *p)
{
	pthread_mutex_lock(p->lf);
	print_phil(p, "has taken a fork");
	pthread_mutex_lock(p->rf);
	print_eating(p);
	ft_sleep(p->data->time_eat);
	pthread_mutex_lock(&p->data->data_mut);
	p->count_eat++;
	pthread_mutex_unlock(&p->data->data_mut);
	pthread_mutex_unlock(p->rf);
	pthread_mutex_unlock(p->lf);
}

void	*check_philo(void *args)
{
	t_philo			*p;

	p = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&p->data->data_mut);
		if (nujobilo(p))
			return (NULL);
		pthread_mutex_unlock(&p->data->data_mut);
		usleep(1000);
	}
	return (NULL);
}

int	nujobilo(t_philo *p)
{
	int				i;
	int				stop;
	long long int	time;

	time = find_time();
	stop = 1;
	i = -1;
	while (++i < p->data->number_philo)
	{
		if (time - (p + i)->t_meal > p->data->time_did)
		{
			p->data->stop = 1;
			printf("%lld %ld %s\n", time - p->data->start_time \
				, (p + i)->index, "is died");
			return (1);
		}
		if (p->data->nbr_eat != -2)
		{
			if ((p + i)->count_eat < p->data->nbr_eat)
				stop = 0;
			if ((i + 1) == p->data->number_philo && stop)
				return (p->data->stop = 1);
		}
	}
	return (0);
}
