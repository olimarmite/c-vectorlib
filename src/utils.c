/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:35 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/14 18:25:24 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	_vec_memcpy(void *dest, void *src, t_length const len)
{
	void	*ptr;

	ptr = src + len;
	while (src <= ptr - 8)
	{
		*((uint64_t *)dest) = *((uint64_t *)src);
		src += 8;
		dest += 8;
	}
	if (src <= ptr - 4)
	{
		*((uint32_t *)dest) = *((uint32_t *)src);
		src += 4;
		dest += 4;
	}
	if (src <= ptr - 2)
	{
		*((uint16_t *)dest) = *((uint16_t *)src);
		src += 2;
		dest += 2;
	}
	if (src < ptr)
		*(uint8_t *)dest++ = *(uint8_t *)src++;
}

int	_vector_resize(t_vector	*vector, t_length len)
{
	void	*data;

	if (len == vector->capacity)
		return (1);
	data = malloc(vector->type_size * len);
	if (data == NULL)
		return (1);
	if (len > vector->capacity)
		_vec_memcpy(data, vector->data, vector->type_size * vector->capacity);
	else
		_vec_memcpy(data, vector->data, vector->type_size * len);
	free(vector->data);
	vector->capacity = len;
	vector->data = data;
	return (0);
}
