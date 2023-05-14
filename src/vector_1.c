/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:31 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/14 18:22:31 by alde-fre         ###   ########.fr       */
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

t_object	vector_add(t_vector *const vector, t_object object)
{
	if (vector->size >= vector->capacity)
		if (_vector_resize(vector, vector->capacity + vector->capacity / 2))
			return (NULL);
	_vec_memcpy(vector->data + vector->type_size * vector->size,
		object, vector->type_size);
	vector->size++;
	return (object);
}

t_object	vector_pop(t_vector *const vector)
{
	if (vector->size == 0)
		return (NULL);
	vector->size--;
	return (vector->data + vector->type_size * vector->size);
}

t_length	vector_size(t_vector const *const vector)
{
	return (vector->size);
}
