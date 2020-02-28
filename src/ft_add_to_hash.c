#include "libft.h"
#include "lem_in.h"

void	ft_add_to_hash(t_hash **hashtab, void *content, char *name)
{
	int i;
	t_hash *temp;

	i = ft_hash(name, HASHTAB_SIZE);
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
	hashtab[i]->name = name;
	hashtab[i]->hash = i;
	hashtab[i]->content = content;
	if (temp)
		hashtab[i] = temp;
}