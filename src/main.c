#include "libft.h"
#include "lem_in.h"

int main() {
	int size = 5;
	int i;
	int j;
	t_edge **matrix;
	t_vertex *vertex_list;


	vertex_list = (t_vertex*)malloc(sizeof(t_vertex) * size);
	i = 0;

	while (i < size)
	{
		vertex_list[i] = *ft_new_verex(2 * i, "A");
		++i;
	}
	ft_print_vertex(&vertex_list, size);
	ft_printf("\n");

	matrix = (t_edge**)malloc(sizeof(t_edge*) * size);
	i = 0;
	while (i < size)
		matrix[i++] = (t_edge*)malloc(sizeof(t_edge) * size);

	i = 0;
	while (i < size){
		j = 0;
		while (j < size)
		{
			matrix[i][j] = *ft_new_edge(vertex_list + i, vertex_list + j, (i + j) % 2);
			++j;
		}
		++i;
	}
	ft_print_matrix(&matrix, size);
	ft_printf("\n");

    ft_printf("Hello, World!\n");
    return 0;
}
