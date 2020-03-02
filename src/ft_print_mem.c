#include "libft.h"

void	ft_print_mem(t_mem **mem)
{
	int	i;
	int	len;

	(*mem)->current = (*mem)->head;
	i = ft_strlen((*mem)->current);
	len = 0;
	while (i)
	{
		(*mem)->current[i] = '\n';
		(*mem)->current += i + 1;
		len += i;
		i = ft_strlen((*mem)->current);
	}
	ft_printf ("%s\n", (*mem)->head);
	ft_memdel((void **)&(*mem)->head);
	ft_memdel((void **)mem);
}