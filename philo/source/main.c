#include "../include/philo.h"

int pth_create(pthread_t *t);
void *test(void *p);

int main()
{
	int i = 0;
    pthread_t pth[30000];
	for (size_t i = 0; i < 30000; i++)
		if(pth_create(&pth[i]) != 0)
			i = 1;
	printf("%d\n", i);
	pthread_join(pth[29999], NULL);
    return (0);
}

int pth_create(pthread_t *t)
{
	int i;
	i = pthread_create(t, NULL, &test, NULL);
	printf("%ld\n", *t);
	return (i);
}

void *test(void *p)
{
	// pthread_mutex_t mutex;

	// pthread_mutex_lock(&mutex);

	usleep(1000000);

	// pthread_mutex_unlock(&mutex);

	return (p);
}