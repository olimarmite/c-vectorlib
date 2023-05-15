/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:22 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/15 18:38:48 by alde-fre         ###   ########.fr       */
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

//-Storage class for any types
typedef struct s_vector	t_vector;
//-Type for storing vector length
typedef unsigned int	t_length;
typedef void			*t_object;

void		*_vec_memcpy(void *dest, void *src, t_length const len);
void		*_vec_memmov(void *dest, void *src, t_length len);

t_vector	*vector_init(t_vector *const vector, t_length const type_size);
void		vector_destroy(t_vector *const vector);

int			vector_reserve(t_vector *const vector, t_length const len);
int			vector_resize(t_vector *const vector, t_length const len)
			__attribute__((always_inline));
void		vector_clear(t_vector *const vector)
			__attribute__((always_inline));

t_object	vector_addback(t_vector *const vector, t_object object);
t_object	vector_addfront(t_vector *const vector, t_object object);
t_object	vector_insert(
				t_vector *const vector,
				t_object object,
				t_length const index);

//THIS FUNCTION ALLOCATES MEMORY
t_object	vector_pop(t_vector *const vector)
			__attribute__((always_inline));
//THIS FUNCTION ALLOCATES MEMORY
t_object	vector_erase(t_vector *const vector, t_length const index);
t_object	vector_remove(t_vector *const vector, t_length const index);

t_object	vector_get(t_vector const *const vector, t_length const index)
			__attribute__((always_inline));
t_length	vector_size(t_vector const *const vector)
			__attribute__((always_inline));
t_length	vector_capacity(t_vector const *const vector)
			__attribute__((always_inline));

struct s_vector
{
	void		*data;
	t_length	size;
	t_length	capacity;
	t_length	type_size;
};

#endif
