#ifndef VECTOR_H
# define VECTOR_H

# define VECTOR_SECTOR_LENGTH 8
# define NO_OBJ ((t_object)0)

# include <stdlib.h>
# include <stdint.h>

/* TYPEDEF */
typedef struct s_vector	t_vector;
typedef struct s_sector	t_sector;
typedef unsigned int	t_length;
typedef void *	t_object;

/* FUNCTIONS */
/* fastest memcpy */
void	_ft_memcpy(void *dest, void *src, unsigned int len);
void	_ft_vector_resize(t_vector *vector, t_length len);

t_vector	*ft_vector_create(void);
void		ft_vector_destroy(t_vector *vector);
t_object	ft_vector_add(t_vector *vector, t_object object);
t_object	ft_vector_pop(t_vector *vector);
t_length	ft_vector_size(t_vector *vector);

t_object	ft_vector_get(t_vector *vector, t_length index);

/* STRUCTURES */
struct s_sector
{
	t_object	data[VECTOR_SECTOR_LENGTH];
};

struct s_vector
{
	t_sector	*data;
	t_length	vec_len;
	t_length	sec_len;
};

#endif
