#include "../include/philo.h"

int ft_error(const char *error)
{
	perror(error);
	return (1);
}