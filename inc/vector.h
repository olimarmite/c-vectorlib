/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:22 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/14 18:31:35 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef VECTOR_DEFAULT_SIZE
#  define VECTOR_DEFAULT_SIZE 64
# endif

/* TYPEDEF */
typedef struct s_vector	t_vector;
typedef unsigned int	t_length;
typedef void *const		t_object;

/* FUNCTIONS */
void		_vec_memcpy(void *dest, void *src, t_length const len);
int			_vector_resize(t_vector *const vector, t_length const len);

t_vector	*vector_init(t_vector *const vector, t_length const type_size);
void		vector_destroy(t_vector *const vector);
t_object	vector_add(t_vector *const vector, t_object object);
t_object	vector_pop(t_vector *const vector);
t_length	vector_size(t_vector const *const vector)
			__attribute__((always_inline));

t_object	vector_get(t_vector const *const vector, t_length const index)
			__attribute__((always_inline));

/* STRUCTURES */
struct s_vector
{
	void		*data;
	t_length	size;
	t_length	capacity;
	t_length	type_size;
};

#endif
