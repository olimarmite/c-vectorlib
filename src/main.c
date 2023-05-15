/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:12:45 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 18:36:33 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int	main(void)
{
	t_vector	vector;
	t_length	i;

	vector_init(&vector, sizeof(char *));
	vector_addback(&vector, &(char *){"Testing the vectors\n"});
	vector_addback(&vector, &(char *){"this is a line that dosnt end with a nl"});
	vector_addback(&vector, &(char *){" but this one does so it is supposed to merge\n"});
	vector_addback(&vector, &(char *){"working ?\n"});
	i = 0;
	while (i < vector_size(&vector))
	{
		printf("%s", *(char **)vector_get(&vector, i));
		i++;
	}
	printf("\n===============================\n");
	vector_insert(&vector, &(char *){"This shit was inserted\n"}, 2);
	i = 0;
	while (i < vector_size(&vector))
	{
		printf("%s", *(char **)vector_get(&vector, i));
		i++;
	}
	printf("\n===============================\n");
	free(vector_erase(&vector, 2));
	i = 0;
	while (i < vector_size(&vector))
	{
		printf("%s", *(char **)vector_get(&vector, i));
		i++;
	}
	vector_destroy(&vector);
}
