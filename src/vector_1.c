/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:31 by alde-fre          #+#    #+#             */
/*   Updated: 2022/11/08 14:00:36 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*ft_vector_create(t_length base_size)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	vector->data = malloc(sizeof(t_object) * base_size);
	vector->obj_len = 0;
	vector->total_len = base_size;
	return (vector);
}

void	ft_vector_destroy(t_vector *vector)
{
	free(vector->data);
	free(vector);
}

t_object	ft_vector_add(t_vector *vector, t_object object)
{
	if (vector->obj_len >= vector->total_len)
		_ft_vector_resize(vector, vector->total_len * 2);
	vector->data[vector->obj_len] = object;
	vector->obj_len++;
	return (object);
}

t_object	ft_vector_pop(t_vector *vector)
{
	t_object	object;

	if (vector->obj_len == 0)
		return (NO_OBJ);
	vector->obj_len--;
	object = vector->data[vector->obj_len];
	if (vector->obj_len > 1 && vector->obj_len < vector->total_len / 2)
		_ft_vector_resize(vector, vector->total_len / 2);
	return (object);
}

t_length	ft_vector_size(t_vector *vector)
{
	return (vector->obj_len);
}
