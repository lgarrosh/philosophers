#include "philo_bonus.h"

int main(int argc, char **argv)
{
    t_data *philo;
    int     i;

    if (argc < 5 || 6 < argc)
		return (ft_error("ERROR NUMBER OF THE ARGUMENT"));
	init_data(argc, argv, &philo);
    i = -1;
    while (++i < philo->number_philo)
    {
        philo->pid[i] = fork();
        if (philo->pid[i] == -1)
            ft_exit("ljhklhhohkh");
    }
}