/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:02:37 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/05/05 20:09:17 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long int	ft_char(const char *st, int i, int c)
{
	long long int	num;
	long long int	f;

	num = 0;
	f = 922337203685477580;
	if (!((48 <= st[i]) && (st[i] <= 57)))
		return (-1);
	while ((48 <= st[i]) && (st[i] <= 57))
	{
		if ((i == 19) && (st[i] == '7') && (c == -1))
			return (-1);
		if ((num - f) > 0)
			return (-2);
		else if ((((num - f) - 7) * -1) >= (st[i] - 48))
			num = 10 * num + (st[i] - 48);
		else
			return (-2);
		i++;
	}
	if (st[i] != '\0')
		return (-1);
	return (num);
}

long long int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	long long int	q;

	i = 0;
	s = 1;
	while (1)
	{
		while (((9 <= str[i]) && (str[i] <= 13)) || (str[i] == ' '))
			i++;
		if (str[i] == '-')
		{
			s = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		q = ft_char(str, i, s);
		if (q < 0)
			return (-1);
		return (q * s);
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long int	find_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_sleep(long long int time)
{
	long long int	tmp;

	tmp = find_time();
	while (1)
	{
		if ((find_time() - tmp) >= time)
			break ;
		usleep(100);
	}
}
