#include "libft.h"
#include "lem_in.h"

int ft_get_next_pointer(t_mem *mem)
{
	int i;
	int len;

	if (!mem->current)
		mem->current = mem->head;
	else
		mem->current = mem->endl;
//	else if (mem->endl)
//		mem->current = mem->endl + 1;
	//i = ft_char_in_str(mem->current, '\n');
	if ((mem->endl = ft_strch(mem->current, '\n'))) {
		*mem->endl = 0;
		mem->endl++;
	}
	else
		return (0);
//	mem->current[i] = '\0';
//	mem->endl = mem->current + i;
	return (1);
}