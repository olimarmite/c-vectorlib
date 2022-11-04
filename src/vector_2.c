/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:39 by alde-fre          #+#    #+#             */
/*   Updated: 2022/11/04 15:21:16 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	ft_vector_get(t_vector *vector, t_length index)
{
	t_length	i;
	t_length	j;

	if (index >= ft_vector_size(vector))
		return (NO_OBJ);
	i = index / VECTOR_SECTOR_LENGTH;
	j = index & (VECTOR_SECTOR_LENGTH - 1);
	return (vector->data[i].data[j]);
}
