

#ifndef LEM_IN_H
#define LEM_IN_H

typedef struct s_vertex {
	int id;
	char *name;
}				t_vertex;

typedef struct s_edge {
	t_vertex*		start;
	t_vertex*		end;
	int		flow;
}				t_edge;


void	ft_set_edge(t_edge *edge, t_vertex *start, t_vertex *end, int flow);
t_edge	*ft_new_edge(t_vertex *start, t_vertex *end, int flow);
void ft_print_matrix(t_edge ***matrix, int size);
t_vertex *ft_new_verex(int vertex_id, char* name);
void ft_print_vertex(t_vertex **vertex_list, int size);
void ft_set_vertex(t_vertex *vertex, int vertex_id, const char *name);

#endif