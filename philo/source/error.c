/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:04:01 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/05 16:04:12 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_error(const char *error)
{
	int	len;

	len = 0;
	while (error[len])
		len++;
	write(2, error, len);
	write(1, "\n", 1);
	return (1);
}

void	ft_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->number_fork)
		pthread_mutex_destroy((philo + i)->lf);
	pthread_mutex_destroy(&philo->data->print_mut);
	pthread_mutex_destroy(&philo->data->data_mut);
	free((void *)philo->data->forks);
	free((void *)philo->data->pth);
	free((void *)philo->data);
	free((void *)philo);
}
