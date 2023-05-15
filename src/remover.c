/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:24:02 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 19:04:28 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	vector_pop(t_vector *const vector)
{
	t_object	object;

	if (vector->size == 0)
		return (NULL);
	object = malloc(vector->type_size);
	if (object == NULL)
		return (NULL);
	_vec_memcpy(object, vector->data + vector->type_size * (vector->size - 1),
		vector->type_size);
	vector->size--;
	return (object);
}

t_object	vector_erase(t_vector *const vector, t_length const index)
{
	t_object	object;

	if (vector->size == 0 || index >= vector->size)
		return (NULL);
	object = malloc(vector->type_size);
	if (object == NULL)
		return (NULL);
	_vec_memcpy(object, vector->data + vector->type_size * index,
		vector->type_size);
	_vec_memcpy(vector->data + vector->type_size * index,
		vector->data + vector->type_size * (index + 1),
		vector->type_size * (vector->type_size - index));
	vector->size--;
	return (object);
}
