/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:22 by alde-fre          #+#    #+#             */
/*   Updated: 2022/11/08 14:00:03 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define NO_OBJ (0)

# include <stdlib.h>
# include <stdint.h>

/* TYPEDEF */
typedef struct s_vector	t_vector;
typedef unsigned int	t_length;
typedef void *			t_object;

/* FUNCTIONS */
/* fastest memcpy */
void		_ft_memcpy(void *dest, void *src, unsigned int len);
void		_ft_vector_resize(t_vector *vector, t_length len);

t_vector	*ft_vector_create(t_length base_size);
void		ft_vector_destroy(t_vector *vector);
t_object	ft_vector_add(t_vector *vector, t_object object);
t_object	ft_vector_pop(t_vector *vector);
t_length	ft_vector_size(t_vector *vector);

t_object	ft_vector_get(t_vector *vector, t_length index);

/* STRUCTURES */
struct s_vector
{
	t_object	*data;
	t_length	obj_len;
	t_length	total_len;
};

#endif