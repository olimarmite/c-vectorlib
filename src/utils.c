/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:35 by alde-fre          #+#    #+#             */
/*   Updated: 2022/11/08 14:07:27 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	_ft_memcpy(void *dest, void *src, unsigned int len)
{
	void	*ptr;

	ptr = src + len;
	while (src < ptr - 8)
	{
		*((uint64_t *)dest) = *((uint64_t *)src);
		src += 8;
		dest += 8;
	}
	while (src < ptr - 4)
	{
		*((uint32_t *)dest) = *((uint32_t *)src);
		src += 4;
		dest += 4;
	}
	while (src < ptr - 2)
	{
		*((uint16_t *)dest) = *((uint16_t *)src);
		src += 2;
		dest += 2;
	}
	while (src < ptr)
		*(uint8_t *)dest++ = *(uint8_t *)src++;
}

void	_ft_vector_resize(t_vector	*vector, t_length len)
{
	t_object	*data;

	data = malloc(sizeof(t_object) * len);
	if (len > vector->total_len)
		_ft_memcpy(data, vector->data, sizeof(t_object) * vector->total_len);
	else
		_ft_memcpy(data, vector->data, sizeof(t_object) * len);
	free(vector->data);
	vector->total_len = len;
	vector->data = data;
}
