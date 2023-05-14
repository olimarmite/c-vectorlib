/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:39 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/14 14:57:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	vector_get(t_vector const *const vector, t_length const index)
{
	if (index >= vector->size)
		return (NULL);
	return (vector->data + index * vector->type_size);
}
