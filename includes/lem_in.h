#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft_structs.h>
# define START "##start"
# define END "##end"
# define START_MEMORY_SIZE 1024

enum				e_color
{
					white,
					grey,
					black
};

typedef struct		s_vertex
{
	t_list			*edge_in_list;
	t_list			*edge_out_list;
	struct s_vertex	*parrent;
	char			*name;
	int				weight;
	int				potecial;
    int				id;
	enum e_color	color;
	int				ant_id;
}					t_vertex;

typedef struct 		s_edge
{
	t_vertex		*start;
	t_vertex		*end;
	int				flow;
    int				cost;
	unsigned int 	param;
	int 			oriented;
}					t_edge;

typedef struct 		s_path
{
	t_vertex		*head;
	long int		price;
	long int		ant_count;
}					t_path;

typedef struct		s_graph
{
	t_list			*vertex_list;
	t_vertex		*source;
	t_vertex		*sink;
	int				vertex_count;
	int				ants_count;
	size_t			path_lenght;
	int				pash_count;
}					t_graph;

int					ft_get_ants_count(t_mem *mem);
int					ft_count_char(char *str, char c);
int					ft_char_in_str(char *str, char c);
int					ft_get_valid_nbr(const char *str);
int					ft_get_next_pointer(t_mem *mem);
void				ft_print_mem(t_mem **mem);
t_graph				*ft_init_graph(void);
t_mem				*ft_init_memory(void);
int					ft_print_error(long int error_code);
void				ft_set_edge(t_edge *edge, t_vertex *start, t_vertex *end, unsigned int param);
t_edge				*ft_new_edge(t_vertex *start, t_vertex *end, unsigned int param);
t_vertex 			*ft_new_verex(int vertex_id, char* name);
int					ft_add_edge(t_vertex *start, t_vertex *end, unsigned int param);
t_vertex			*ft_add_vertex_back(t_graph *graph, t_vertex *vertex);
void				ft_remove_edge(t_edge **edge);
void				ft_split_edge(t_edge **edge);
void				ft_remove_vertex(t_graph **graph, t_vertex **vertex);
void				ft_convert_graph_to_oriented(t_graph *graph);
void				ft_split_vertex(t_graph *graph);
void				ft_split_all_edges(t_vertex *vertex);
int					ft_min_cost_flow(t_graph *graph);
void				ft_reverse_edge_vertex(t_vertex *start,  t_vertex *end);
t_path				ft_new_path(t_vertex *path_head, t_vertex *source);
void				ft_push_ant(t_path *path_list, t_graph *graph, int *id);
long int 			ft_set_ant_to_pash(size_t total_ant, t_path *path_list, int pash_count);
t_path 				*ft_new_path_list(t_graph *graph);
int					ft_accept_path(t_graph *graph);
int					ft_get_pash_len(const t_graph *graph, t_vertex *vertex);
void				ft_del_graph(t_graph **graph);
void				ft_remove_zero_flow(t_graph *graph);
int					ft_get_vertex(t_graph *graph, t_mem *mem, t_set **vset);
int					ft_get_edges(t_mem *mem, t_set *vset);
int					ft_set_insert_vertex(t_set **set, t_vertex *vertex);
t_vertex			*ft_set_get_vertex(t_set *set, char *value);
int					ft_get_graph(t_graph *graph, t_mem *mem, int fd);
#endif