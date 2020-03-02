#include "libft.h"
#include "lem_in.h"

void	ft_add_to_hash(t_hash **hashtab, void *content, void *cmp_ptr, int hash)
{
	unsigned int i;
	t_hash *temp;

	i = hash;
	temp = hashtab[i];
	if (hashtab[i] == NULL)
	{
		hashtab[i] = (t_hash *) malloc(sizeof(t_hash));
		hashtab[i]->next = NULL;
	}
	else
	{
		while (hashtab[i]->next)
			hashtab[i] = hashtab[i]->next;
		hashtab[i]->next = (t_hash *) malloc(sizeof(t_hash));
		hashtab[i] = hashtab[i]->next;
		hashtab[i]->next = NULL;
	}
	hashtab[i]->cmp_ptr = cmp_ptr;
	hashtab[i]->content = content;
	if (temp)
		hashtab[i] = temp;
}

void	ft_add_to_coord_hash(t_hash **hashtab, t_vertex *vertex, t_coord *coord)
{
	unsigned int i;
	t_hash *temp;

	i = (coord->x + coord->y) % HASH_SIZE;
	temp = hashtab[i];
	if (hashtab[i] == NULL)
	{
		hashtab[i] = (t_hash *) malloc(sizeof(t_hash));
		hashtab[i]->next = NULL;
	}
	else
	{
		while (hashtab[i]->next)
			hashtab[i] = hashtab[i]->next;
		hashtab[i]->next = (t_hash *) malloc(sizeof(t_hash));
		hashtab[i] = hashtab[i]->next;
		hashtab[i]->next = NULL;
	}
	hashtab[i]->cmp_ptr = ft_memalloc(sizeof(coord));
	ft_memcpy((void *)hashtab[i]->cmp_ptr, (void *)coord, sizeof(coord));
	hashtab[i]->content = (void *)vertex;
	if (temp)
		hashtab[i] = temp;
}