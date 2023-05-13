/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:12:45 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/14 00:02:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_vector	vector;

	vector_init(&vector, sizeof(char *));

	char str[] = "OUI CECI EST UN TEST";
	char *str1 = "OUI CElui si ossi EST UN TEST";
	vector_add(&vector, &(char *){"oui"});
	vector_add(&vector, &"non");
	vector_add(&vector, &str);
	vector_add(&vector, &str1);
	vector_add(&vector, &(char *){"celui ci l'est encore plus"});

	for (t_length i = 0; i < vector_size(&vector); i++)
		printf("%u::%s\n", i, *((char **)(vector_get(&vector, i))));
	
	vector_destroy(&vector);
}