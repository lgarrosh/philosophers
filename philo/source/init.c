/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:04:25 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/05 16:54:49 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_data(int argc, char **argv, t_data **basic)
{
	*basic = (t_data *)malloc(sizeof(t_data));
	if (!*basic)
		return (ft_error("ERROR: FAILED TO GET MEMORY"));
	memset(*(void **)basic, 0, sizeof(t_data));
	(*basic)->stop = 0;
	(*basic)->number_philo = ft_atoi(argv[1]);
	(*basic)->number_fork = (*basic)->number_philo;
	(*basic)->time_did = ft_atoi(argv[2]);
	(*basic)->time_eat = ft_atoi(argv[3]);
	(*basic)->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*basic)->nbr_eat = ft_atoi(argv[5]);
	else
		(*basic)->nbr_eat = -2;
	if ((*basic)->number_philo == -1 || (*basic)->time_did == -1
		|| (*basic)->nbr_eat == -1 || (*basic)->time_eat == -1
		|| (*basic)->time_sleep == -1)
	{
		free(*(void **)basic);
		return (ft_error("ERROR: INVALIDE ARGUMENT"));
	}
	return (0);
}

int	init_philos(t_philo **philo, t_data *data)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * data->number_philo);
	if (!(*philo))
		return (1);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* data->number_fork);
	if (!data->forks)
	{
		free((void *)philo);
		return (1);
	}
	data->pth = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philo);
	if (!data->pth)
	{
		free((void *)philo);
		free((void *)data->forks);
		return (1);
	}
	if (init_philo(*philo, data))
	{
		ft_free(*philo);
		return (1);
	}
	return (0);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philo)
	{
		if (i == 0)
		{
			(philo + i)->lf = data->forks + data->number_philo - 1;
			(philo + i)->rf = data->forks + i;
		}
		else
		{
			(philo + i)->lf = data->forks + i - 1;
			(philo + i)->rf = data->forks + i;
		}
		(philo + i)->pth = data->pth + i;
		(philo + i)->index = i + 1;
		(philo + i)->count_eat = 0;
		(philo + i)->data = data;
		if (pthread_mutex_init((philo + i)->lf, NULL))
			return (ft_error("ERROR: FAILED TO INIT MUTEX"));
	}
	return (0);
}
