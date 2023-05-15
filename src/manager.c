/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:31 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 11:39:29 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_init(t_vector *const vector, t_length const type_size)
{
	if (type_size == 0)
		return (NULL);
	vector->data = malloc(type_size * VECTOR_DEFAULT_SIZE);
	if (vector->data == NULL)
		return (NULL);
	vector->size = 0u;
	vector->capacity = VECTOR_DEFAULT_SIZE;
	vector->type_size = type_size;
	return (vector);
}

void	vector_destroy(t_vector *const vector)
{
	free(vector->data);
}
