/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:25:21 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 16:51:58 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vector_reserve(t_vector *const vector, t_length const len)
{
	void	*data;

	if (len == vector->capacity)
		return (1);
	if (len > vector->capacity)
	{
		data = malloc(vector->type_size * len);
		if (data == NULL)
			return (1);
		_vec_memcpy(data, vector->data, vector->type_size * vector->size);
		free(vector->data);
		vector->data = data;
		vector->capacity = len;
	}
	return (0);
}

int	vector_resize(t_vector	*vector, t_length const len)
{
	if (vector_reserve(vector, len))
		return (1);
	vector->size = len;
	return (0);
}

void	vector_clear(t_vector *const vector)
{
	vector->size = 0u;
}
