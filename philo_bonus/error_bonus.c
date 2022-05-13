/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:10:09 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/13 13:44:18 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_exit(t_philo **philo, const char *error)
{
	int	i;

	i = -1;
	waitpid(-1, NULL, 0);
	while (++i < (*philo)->number_philo)
		kill((*philo)->pid[i], SIGKILL);
	sem_close((*philo)->sem_printf);
	sem_close((*philo)->sem_fork);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	free((void *)(*philo)->pid);
	(*philo)->pid = NULL;
	free(*(void **)philo);
	*philo = NULL;
	if (error)
		exit(ft_error(error));
	exit(0);
}
