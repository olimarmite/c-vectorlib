#include "vector.h"

t_vector	*ft_vector_create(void)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	vector->data = malloc(sizeof(t_sector));
	vector->vec_len = 1;
	vector->sec_len = 0;
	return (vector);
}

void	ft_vector_destroy(t_vector *vector)
{
	free(vector->data);
	free(vector);
}

t_object	ft_vector_add(t_vector *vector, t_object object)
{
	if (vector->sec_len >= VECTOR_SECTOR_LENGTH)
	{
		_ft_vector_resize(vector, vector->vec_len + 1);
		vector->sec_len = 0;
	}
	vector->data[vector->vec_len - 1].data[vector->sec_len] = object;
	vector->sec_len++;
	return (object);
}

t_object	ft_vector_pop(t_vector *vector)
{
	t_object	object;

	if (vector->vec_len == 1 && vector->sec_len == 0)
		return (NO_OBJ);
	vector->sec_len--;
	object = vector->data[vector->vec_len - 1].data[vector->sec_len];
	if (vector->vec_len > 1 && vector->sec_len == 0)
	{
		_ft_vector_resize(vector, vector->vec_len - 1);
		vector->sec_len = VECTOR_SECTOR_LENGTH - 1;
	}
	return (object);
}

t_length	ft_vector_size(t_vector *vector)
{
	return ((vector->vec_len - 1) * VECTOR_SECTOR_LENGTH + vector->sec_len);
}

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

