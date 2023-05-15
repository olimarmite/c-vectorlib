/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:39 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 18:13:03 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	vector_addback(t_vector *const vector, t_object object)
{
	if (vector->size + 1 > vector->capacity)
		if (vector_resize(vector, vector->capacity + vector->capacity / 2))
			return (NULL);
	_vec_memcpy(vector->data + vector->type_size * vector->size,
		object, vector->type_size);
	vector->size++;
	return (vector->data + vector->type_size * vector->size);
}

t_object	vector_addfront(t_vector *const vector, t_object object)
{
	if (vector->size + 1 > vector->capacity)
		if (vector_resize(vector, vector->capacity + vector->capacity / 2))
			return (NULL);
	_vec_memmov(vector->data + vector->type_size, vector->data,
		vector->type_size * vector->size);
	_vec_memcpy(vector->data, object, vector->type_size);
	vector->size++;
	return (vector->data);
}

t_object	vector_insert(
				t_vector *const vector,
				t_object object,
				t_length const index)
{
	if (vector->size + 1 > vector->capacity)
		if (vector_resize(vector, vector->capacity + vector->capacity / 2))
			return (NULL);
	_vec_memmov(
		vector->data + vector->type_size * (index + 1),
		vector->data + vector->type_size * index,
		vector->type_size * (vector->size - index));
	_vec_memcpy(vector->data + vector->type_size * index,
		object, vector->type_size);
	vector->size++;
	return (vector->data);
}
