#include "../include/philo.h"

t_data *init_data(int argc, char **argv)
{
	t_data *basic;

	basic = (t_data *)malloc(sizeof(t_data));
	basic->number = ft_atoi(argv[1]);
	basic->time_did = ft_atoi(argv[2]);
	basic->time_eat = ft_atoi(argv[3]);
	basic->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		basic->nbr_eat = ft_atoi(argv[5]);
	else
		basic->nbr_eat = -2;
	if (basic->number == -1 || basic->time_did == -1 || basic->nbr_eat == -1
		|| basic->time_eat == -1 || basic->time_sleep == -1)
	{
		ft_error("ERROR: INVALIDE ARGUMENT");
		free((void *)basic);
		return(NULL);
	}
	return (basic);
}