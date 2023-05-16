/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:12:45 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/16 10:24:16 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int	main(void)
{
	t_vector	vector;
	t_vector	vector2;
	t_length	i;

	vector_init(&vector, sizeof(char *));
	vector_addback(&vector, &(char *){"Testing the vectors\n"});
	vector_addback(&vector, &(char *){"this is a line that dosnt end with a nl"});
	vector_addback(&vector, &(char *){" but this one does so it is supposed to merge\n"});
	vector_addback(&vector, &(char *){"working ?\n"});
	i = 0;
	while (i < vector_size(&vector))
	{
		printf(" + %s", *(char **)vector_get(&vector, i));
		i++;
	}
	printf("\n===============================\n");
	vector_init(&vector2, sizeof(char *));
	vector_copy(&vector2, &vector);
	vector_erase(&vector2, 2);
	i = 0;
	while (i < vector_size(&vector))
	{
		printf(" - %s", *(char **)vector_get(&vector, i));
		i++;
	}
	i = 0;
	while (i < vector_size(&vector2))
	{
		printf(" + %s", *(char **)vector_get(&vector2, i));
		i++;
	}
	vector_destroy(&vector2);
	vector_destroy(&vector);
}
