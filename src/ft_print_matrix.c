#include "lem_in.h"
#include "libft.h"

void ft_print_matrix(t_edge ***matrix, int const size)
{
	int row;
	int column;

	row = -1;
	while (++row < size)
	{
		column = -1;
		while (++column < size)
			ft_printf("{(%d, %d), %2d} \t",
					(*matrix)[row][column].start->id,
					(*matrix)[row][column].end->id,
					(*matrix)[row][column].flow);
		ft_printf("\n");
	}
}