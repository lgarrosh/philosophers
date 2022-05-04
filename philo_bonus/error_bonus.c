#include "philo_bonus.h"

int ft_error(const char *error)
{
	int len;

	len = 0;
	while (error[len])
		len++;
	write(2, error, len);
	write(1, "\n", 1);
	return (1);
}

void	ft_exit(t_data *data, const char *error)
{
	
	exit(0);
}