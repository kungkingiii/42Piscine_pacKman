#include "../so_long.h"

size_t	ft_c_arr_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}