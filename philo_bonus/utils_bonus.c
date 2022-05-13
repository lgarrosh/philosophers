/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:00:29 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/13 14:11:41 by lgarrosh         ###   ########.fr       */
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
	t_philo	*p;
	char	*name;

	p = (t_philo *)args;
	while (1)
	{
		sem_wait(p->sem_printf);
		sem_wait(p->sem_data);
		if (nujobilo(p))
			break ;
		sem_post(p->sem_data);
		sem_post(p->sem_printf);
		usleep(1000);
	}
	sem_close(p->sem_data);
	name = make_n_name("philo", p->index);
	sem_unlink(name);
	free(name);
	exit (0);
	return (NULL);
}

char	*make_n_name(char *name, int n)
{
	char	*result;
	int		num;
	int		i;

	i = 0;
	num = n;
	while (num)
	{
		num /= 10;
		++i;
	}
	result = malloc(sizeof(char) * (i + ft_strlen(name) + 1));
	if (result == NULL)
		return (NULL);
	num = -1;
	while (++num < i)
		result[num] = name[num];
	while (n)
	{
		result[i++] = n % 10 + '0';
		n /= 10;
	}
	result[i] = 0;
	return (result);
}
