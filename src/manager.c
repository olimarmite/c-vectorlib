/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:31 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/16 10:22:04 by alde-fre         ###   ########.fr       */
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
	vector->buffer = malloc(type_size);
	if (vector->buffer == NULL)
		return (free(vector->data), NULL);
	vector->size = 0u;
	vector->capacity = VECTOR_DEFAULT_SIZE;
	vector->type_size = type_size;
	return (vector);
}

void	vector_destroy(t_vector *const vector)
{
	free(vector->data);
	free(vector->buffer);
}

t_vector	*vector_copy(t_vector *const vec_dest, t_vector *const vec_src)
{
	if (vec_dest == vec_src)
		return (NULL);
	vec_dest->type_size = vec_src->type_size;
	vector_reserve(vec_dest, vec_src->capacity);
	_vec_memcpy(vec_dest->data, vec_src->data,
		vec_src->type_size * vec_src->size);
	vec_dest->size = vec_src->size;
	return (vec_dest);
}