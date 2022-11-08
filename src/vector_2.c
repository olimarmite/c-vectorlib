/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:39 by alde-fre          #+#    #+#             */
/*   Updated: 2022/11/08 13:59:50 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_object	ft_vector_get(t_vector *vector, t_length index)
{
	if (index >= ft_vector_size(vector))
		return (NO_OBJ);
	return (vector->data[index]);
}
