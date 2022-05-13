/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:40:09 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/13 17:55:55 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(int argc, char **argv, t_philo *philo)
{
	philo->number_philo = ft_atoi(argv[1]);
	philo->number_fork = philo->number_philo;
	philo->time_did = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (philo->number_fork < 1 || philo->number_philo > 250 \
		|| philo->time_did == -1 || philo->time_eat == -1 \
		|| philo->time_sleep == -1)
		return (ft_error("Error: Wrong arguments"));
	philo->nbr_eat = -1;
	if (argc == 6)
	{
		philo->nbr_eat = ft_atoi(argv[5]);
		if (philo->nbr_eat == -1)
			return (ft_error("Error: Wrong arguments"));
	}
	philo->eat_count = 0;
	philo->stop = 0;
	return (0);
}

int	init_philo(int argc, char **argv, t_philo **philo)
{
	*philo = (t_philo *)malloc(sizeof(t_philo));
	if (!(*philo))
		return (ft_error("ERROR: MALLOC (PHILO)"));
	(*philo)->pid = (int *)malloc(sizeof(int) * (*philo)->number_philo);
	if (init_data(argc, argv, *philo) || !(*philo)->pid)
	{
		free(*(void **)philo);
		return (1);
	}
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	(*philo)->sem_printf = sem_open("/sem_print", O_CREAT, 0644, 1);
	(*philo)->sem_fork = sem_open("/sem_forks", O_CREAT, \
								0644, (*philo)->number_fork);
	if ((*philo)->sem_printf <= 0 || (*philo)->sem_fork <= 0)
	{
		free((void *)(*philo)->pid);
		free(*(void **)philo);
		return (ft_error("ERROR: SEMAPHOR OPEN"));
	}
	return (0);
}
