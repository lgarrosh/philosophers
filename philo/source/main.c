/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:33:00 by arman             #+#    #+#             */
/*   Updated: 2022/05/04 15:30:21 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_data *data;

	if (argc < 5 || 6 < argc)
		return (ft_error("ERROR NUMBER OF THE ARGUMENT"));
	else if (!(data = init_data(argc, argv)))
		return (1);
	philosophers(data);
	return (0);
}

void *start(void *args)
{
	t_philo *p;

	p = (t_philo *)args;
	while (1)
	{
		taken_fork(p);
		print_phil(p, "is sleeping");
		ft_sleep(p->data->time_sleep);
		print_phil(p, "is thinking");
	}
	return (NULL);
}

void	ft_creat_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	data->start_time = find_time();
	while (++i < data->number_philo)
	{
		philo->start_philo = find_time();
		(philo + i)->t_meal = find_time();
		if (pthread_create((philo + i)->pth, NULL, &start, (philo + i)))
			ft_exit(philo, data, "ERROR: FAILED TO CREATE THREAD");
		pthread_detach(*(philo + i)->pth);
		usleep(50);
	}
	if (pthread_create(&data->pth_check, NULL, &check_philo, philo))
		ft_exit(philo, data, "ERROR: FAILED TO CREATE THREAD");
	pthread_join(data->pth_check, NULL);
}

void philosophers(t_data *data)
{
	t_philo	*philo;

	if (init_philos(&philo, data))
		exit(ft_error("test"));
	ft_creat_thread(philo, data);
}