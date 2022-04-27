/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arman <arman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:33:00 by arman             #+#    #+#             */
/*   Updated: 2022/04/27 17:05:51 by arman            ###   ########.fr       */
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
	while (!p->data->stop)
	{
		print_phil(p, "is thinking");
		pthread_mutex_lock(p->lf);
		print_phil(p, "has taken a fork l");
		pthread_mutex_lock(p->rf);
		print_phil(p, "has taken a fork r");
		print_phil(p, "eating");
		ft_sleep(p);
		p->count_eat++;
		p->t_meal = find_time();
		pthread_mutex_unlock(p->rf);
		pthread_mutex_unlock(p->lf);
	}
	return (args);
}

void	ft_creat_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philo)
	{
		data->start_time = find_time();
		if (pthread_create((philo + i)->pth, NULL, &start, (philo + i)))
			ft_exit(philo, data, "ERROR: FAILED TO CREATE THREAD");
		pthread_detach(*(philo + i)->pth);
		usleep(50);
	}
	if (pthread_create(&data->pth_check, NULL, &start, philo))
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