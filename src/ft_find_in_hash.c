#include "libft.h"
#include "lem_in.h"

t_vertex *ft_find_in_hash(t_hash **hashtab, char *name)
{
	//t_vertex	*vertex;
	int 		hash;
	int 		i;
	t_hash 		*temp;

	hash = ft_hash(name, HASHTAB_SIZE);
	i = hash;// % HASHTAB_SIZE;
	if (!hashtab[i])
		return (NULL);
	/*if (!(hashtab[hash]->next))
		return (hashtab[hash]->vertex);*/
	temp = hashtab[i];
	while (temp)
	{
		//if (temp->hash == hash)
		//{
			if (!ft_strcmp(temp->name, name))
				break ;
		//}
		temp = temp->next;
	}
	if (temp)
		return (temp->vertex);
	return (NULL);
}