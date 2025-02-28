#include "philo.h"

void    *your_turn(void *arg)
{
	while (1)
	{
		printf("Your turn\n");
		sleep(2);
	}
}

void    my_turn(void)
{
	printf("hello world\n");
	while (1)
	{
		printf("My turn\n");
		sleep(1);
	}
}

int main(int ac, char *av[])
{
	pthread_t	*threads;
	int			i;

	threads	= malloc(sizeof(pthread_t) * 4);	
	i = 1;	
	while (i < 3)
	{
		pthread_create(&threads[i++], NULL, your_turn, NULL);
	}
	sleep(10);
	// my_turn();
	// your_turn();
	
}
