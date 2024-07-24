/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:09:22 by packmanich        #+#    #+#             */
/*   Updated: 2024/07/24 09:34:29 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void	*computation(void *add);

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	long		value1;
	long		value2;

	value1 = 5;
	value2 = 2;

	// computation((void *) &value1);
	// computation((void *) &value2);
	pthread_create(&thread1, NULL, computation, (void *) &value1);
	pthread_create(&thread2, NULL, computation, (void *) &value2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}

void *computation(void *add)
{
	long sum = 0;
	long	*add_num = (long *)(add);
	
	for (long i = 1; i < 1000000000; i++)
		sum += *add_num;
	printf("add: %ld\n", *add_num);
	return (NULL);
}
