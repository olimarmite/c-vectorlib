/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:12:45 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/14 18:31:19 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	main(void)
{
	t_vector	vector;

	vector_init(&vector, sizeof(char *));
	vector_add(&vector, &(char *){"Testing the vectors\n"});
	vector_add(&vector, &(char *){"this is a line that dosnt end with a nl"});
	vector_add(&vector, &(char *){" but this one does so it is supposed to merge\n"});
	vector_add(&vector, &(char *){"working ?\n"});
	while (vector_size(&vector))
	{
		printf("%s", *(char **)vector_pop(&vector));
		fflush(NULL);
	}
	vector_destroy(&vector);
}
