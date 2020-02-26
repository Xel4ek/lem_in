#include "libft.h"
#include "lem_in.h"

void		ft_add_to_hash(t_hash **hashtab, t_vertex *vertex)
{
	int hash;
	int i;
	t_hash *temp;

	hash = ft_hash(vertex->name, HASHTAB_SIZE);
	i = hash;// % HASHTAB_SIZE;
	temp = hashtab[i];
	if (!hashtab[i])
	{
		hashtab[i] = (t_hash *) malloc(sizeof(t_hash));
		hashtab[i]->next = NULL;
	}
	else
	{
		while (hashtab[i]->next)
			hashtab[i] = hashtab[hash]->next;
		hashtab[i]->next = (t_hash *) malloc(sizeof(t_hash));
		hashtab[i] = hashtab[hash]->next;
		hashtab[i]->next = NULL;
	}
	hashtab[i]->name = vertex->name;
	hashtab[i]->hash = hash;
	hashtab[i]->vertex = vertex;
	if (temp)
		hashtab[i] = temp;
}