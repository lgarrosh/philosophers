#include "philo_bonus.h"

void	init_data(int argc, char **argv, t_data **data)
{
	t_data *philo;

	philo = (t_data *)malloc(sizeof(t_data));
	if (!philo)
		exit (ft_error("ERROR: FAILED TO GET MEMORY"));
	memset((void *)philo, 0, sizeof(t_data));
	philo->number_philo = ft_atoi(argv[1]);
	philo->number_fork = philo->number_philo;
	philo->time_did = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->nbr_eat = ft_atoi(argv[5]);
	else
		philo->nbr_eat = -2;
	if (philo->number_philo == -1 || philo->time_did == -1 || philo->nbr_eat == -1
		|| philo->time_eat == -1 || philo->time_sleep == -1)
	{
		free((void *)philo);
		exit (ft_error("ERROR: INVALIDE ARGUMENT"));
	}
	*data = philo;
	init_philo(*data);
}

void	init_philo(t_data *philo)
{
	philo->pid = (int *)malloc(sizeof(int) * philo->number_fork);
	if (!philo->pid)
		ft_error("ouhouhoh");
	philo->block_fork = sem_open("/block_print", O_CREAT, 0644, 1);
	philo->block_fork = sem_open("/block_forks", O_CREAT, \
								0644, philo->number_fork);
	if (philo->block_fork <= 0 || philo->block_fork <= 0)
		ft_error("Error: semaphore open error");
}