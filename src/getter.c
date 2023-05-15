/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:43:22 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 11:39:20 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	vector_get(t_vector const *const vector, t_length const index)
{
	if (index >= vector->size)
		return (NULL);
	return (vector->data + index * vector->type_size);
}

t_length	vector_size(t_vector const *const vector)
{
	return (vector->size);
}

t_length	vector_capacity(t_vector const *const vector)
{
	return (vector->capacity);
}
