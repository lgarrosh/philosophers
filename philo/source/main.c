/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arman <arman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:33:00 by arman             #+#    #+#             */
/*   Updated: 2022/04/26 23:07:44 by arman            ###   ########.fr       */
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

void philosophers(t_data *data)
{
	t_philo	*philo;

	if (init_philos(&philo, data))
		exit(ft_error("test"));
}