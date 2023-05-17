/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:12:45 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/17 13:44:33 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

static inline void	myvec_print(t_object object)
{
	printf("%s", *(char **)object);
}

int	main(void)
{
	t_vector	vector;
	t_vector	vector2;

	vector_init(&vector, sizeof(char *));
	vector_addback(&vector, &(char *){"zero\n"});
	vector_addback(&vector, &(char *){"un\n"});
	vector_addback(&vector, &(char *){"deux\n"});
	vector_addback(&vector, &(char *){"trois\n"});
	vector_addback(&vector, &(char *){"quatre\n"});
	vector_addback(&vector, &(char *){"cinq\n"});
	vector_addback(&vector, &(char *){"six\n"});
	vector_addback(&vector, &(char *){"sept\n"});

	vector_for_each(&vector, &myvec_print);
	printf("\n===============================\n");

	vector2 = vector_subvec(&vector, 3, 3);
	vector_addfront(&vector2, vector_get(&vector, 1u));

	vector_for_each(&vector2, &myvec_print);

	vector_destroy(&vector2);
	vector_destroy(&vector);
}
