/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:00:29 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/06 19:26:05 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_phil(t_philo *p, const char *str)
{
	long long int	time;

	time = find_time();
	sem_wait(p->sem_printf);
	sem_wait(p->sem_data);
	if (!p->stop)
		printf("%lld %d %s\n", time - p->start_time, p->index, str);
	sem_post(p->sem_data);
	sem_post(p->sem_printf);
}

static int	nujobilo(t_philo *p)
{
	int				i;
	long long int	time;

	time = find_time();
	i = -1;
	if (time - p->t_meal > p->time_did)
	{
		printf("%lld %d %s\n", time - p->start_time \
			, p->index, "is died");
		return (1);
	}
	if (p->nbr_eat != -2)
	{
		if (p->eat_count == p->nbr_eat)
			return (1);
	}
	return (0);
}

void	*check_philo(void *args)
{
	t_philo			*p;

	p = (t_philo *)args;
	while (1)
	{
		sem_wait(p->sem_printf);
		sem_wait(p->sem_data);
		if (nujobilo(p))
			exit (0);
		sem_wait(p->sem_data);
		sem_post(p->sem_printf);
		usleep(1000);
	}
	return (NULL);
}
