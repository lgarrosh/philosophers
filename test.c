/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:40:09 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/06 18:58:28 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "semaphore.h"

void	funct(void)
{
	int	i;
	while (1)
	{
		usleep(3000000);
		printf("%d pid\n", getpid());
	}
}

int	main(void)
{
	int	pid[3];
	int status;

	pid[0] = fork();
	if (pid[0] == 0)
		funct();
	pid[1] = fork();
	if (pid[1] == 0)
		funct();
	pid[2] = fork();
	if (pid[2] == 0)
		funct();
	waitpid(-1, &status, 0);
	printf("%d pid\n", status);
	WIFEXITED(&status);
	waitpid(-1, &status, 0);
	printf("%d pid\n", status);
	waitpid(-1, &status, 0);
	printf("%d pid\n", status);
	return (1);
}
