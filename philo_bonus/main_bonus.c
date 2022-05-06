/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:31:56 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/06 19:18:07 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, \
			NULL, &check_philo, philo))
		ft_error("ERROR: Failed to create the thread");
	while (1)
	{
		sem_wait(philo->sem_fork);
		print_phil(philo, "has taken a fork");
		sem_wait(philo->sem_fork);
		print_phil(philo, "has taken a fork");
		print_phil(philo, "is eating");
		ft_sleep(philo->time_eat);
		philo->t_meal = find_time();
		philo->eat_count ++;
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		print_phil(philo, "is sleeping");
		ft_sleep(philo->time_sleep);
		print_phil(philo, "is tanking");
	}
	if (pthread_join(philo->check_monitor, NULL))
		ft_error("Error: Failed to join the thread");
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		i;

	if (argc < 5 || argc > 6)
		return (ft_error("ERROR: WRONG NUMBER OF ARGUMENTS"));
	if (init_philo(argc, argv, &philo))
		return (1);
	i = -1;
	philo->start_time = find_time();
	while (++i < philo->number_philo)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			ft_exit(&philo, "ERROR: FORK");
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			philo->t_meal = find_time();
			start(philo);
		}
	}
	ft_exit(&philo, NULL);
	return (0);
}
