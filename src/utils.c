#include "vector.h"

void	_ft_memcpy(void *dest, void *src, unsigned int len)
{
	void	*ptr;

	ptr = src + len;
	while (src < ptr - 64)
	{
		*((uint64_t *)dest) = *((uint64_t *)src);
		src += 8;
		dest += 8;
	}
	while (src < ptr - 32)
	{
		*((uint32_t *)dest) = *((uint32_t *)src);
		src += 4;
		dest += 4;
	}
	while (src < ptr - 16)
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
	t_sector	*data;

	data = malloc(sizeof(t_sector) * len);
	_ft_memcpy(data, vector->data, sizeof(t_sector) * len);
	free(vector->data);
	vector->vec_len = len;
	vector->data = data;
}




