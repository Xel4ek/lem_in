

#ifndef LEM_IN_H
#define LEM_IN_H

#include <libft_structs.h>

enum e_color{
	white,
	grey,
	black
};

typedef struct	s_graph
{
	t_list*		vertex_list;
}				t_graph;

typedef struct	s_vertex
{
	int			id;
	t_list		*edge_in_list;
	t_list		*edge_out_list;
	enum e_color	color;
	struct s_vertex *parrent;
	char		*name;
}				t_vertex;

typedef struct s_edge
{
	t_vertex		*start;
	t_vertex		*end;
	int 			oriented;
	int				flow;
}				t_edge;

t_graph *mygraph(void);
void ft_print_graph(const t_graph *graph);
void 	ft_print_vertex(t_vertex *vertex);
void	ft_set_edge(t_edge *edge, t_vertex *start, t_vertex *end, int flow, int oriented);
t_edge	*ft_new_edge(t_vertex *start, t_vertex *end, int flow, int oriented);
void ft_print_matrix(t_edge ***matrix, int size);
t_vertex *ft_new_verex(int vertex_id, char* name);
void ft_print_vertex_all(t_vertex **vertex_list_link, int size);
void ft_set_vertex(t_vertex *vertex, int vertex_id, const char *name);
int ft_add_edge(t_vertex *start, t_vertex *end, int flow, int oriented);
void ft_print_egde(t_edge *edge);
void ft_print_egde_list(t_list *egde_list);
void ft_add_vertex(t_graph *graph, t_vertex *vertex);
void ft_remove_edge(t_edge **edge);
void ft_split_edge(t_edge **edge);
void ft_remove_vertex(t_graph **graph, t_vertex **vertex);
void ft_convert_graph_to_oriented(t_graph **graph);
void ft_split_vertex(t_graph **graph, t_vertex **vertex);
void ft_split_all_edges(t_vertex *vertex);
int ft_graph_dfs(t_graph *graph, int target_id);
void	*ft_queue_pop(t_list **queue);
#endif