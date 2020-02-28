#include "lem_in.h"
#include <stdlib.h>

t_hash	**ft_init_hash(int size)
{
	t_hash	**hashtab;

	if (!(hashtab = (t_hash **)malloc(sizeof(t_hash *) * size)))
		return (NULL);
	while (size--)
		hashtab[size] = NULL;
	return (hashtab);
}