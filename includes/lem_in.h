#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft_structs.h>
# define START "##start"
# define END "##end"
# define HASH_SIZE 1024
# define START_MEMORY_SIZE 256

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
	int 			x;
	int 			y;
}					t_vertex;

typedef struct 		s_edge
{
	t_vertex		*start;
	t_vertex		*end;
    int				flow;
    int				cost;
	int 			oriented;
}					t_edge;

typedef struct 		s_path
{
	t_vertex		*head;
	int				price;
	int				ant_count;
}					t_path;

typedef struct		s_graph
{
	t_list			*vertex_list;
	t_vertex		*source;
	t_vertex		*sink;
	int				vertex_count;
	int				ants_count;
	int				pash_count;
	int				path_lenght;

}					t_graph;

typedef struct 		s_hash
{
	void 			*cmp_ptr;
	void 			*content;
	struct	s_hash	*next;
}					t_hash;

typedef	struct		s_edgename
{
	char 			*name1;
	char 			*name2;
}					t_edgename;

typedef	struct		s_coord
{
	int 			x;
	int 			y;
}					t_coord;

typedef struct		s_hptrs
{
	t_hash 			**vhash;
	t_hash 			**chash;
}					t_hptrs;

int					ft_get_graph(t_graph **graph, t_mem *mem, int fd);
int					ft_get_vertex(t_graph *graph, t_mem *mem, t_hptrs *hptrs);
int					ft_get_edges(t_graph *graph, t_mem *mem, t_hash **hashtab);
int					ft_check_n_add_edge(t_edgename *e_names, \
					t_hash **edge_hash, t_hash **hashtab);
int					ft_get_ants_count(t_mem *mem);
int					ft_count_char(char *str, char c);
int					ft_char_in_str(char *str, char c);
int					ft_get_valid_nbr(const char *str);
void				ft_add_to_hash(t_hash **hashtab, void *content, \
					void *cmp_ptr, unsigned int hash);
void				ft_add_to_coord_hash(t_hash **hashtab, t_vertex *vertex, \
					t_coord *coord);
t_vertex			*ft_find_vertex_in_hash(t_hash **hashtab, char *name, \
					unsigned int hash);
int					ft_find_edge_in_hash(t_hash **hashtab, char *name, \
					unsigned int hash);
int					ft_find_coord_in_hash(t_hash **hashtab, t_coord *coord);
int					ft_delete_edge_hash(t_hash **edge_hash, int res);
int					ft_delete_hashtab(t_hash **hashtab, int res);
int					ft_delete_coord_hash(t_hash **hashtab, int res);
t_hash				**ft_init_hash(int size);
int					ft_get_next_pointer(t_mem *mem);
void				ft_print_mem(t_mem **mem);
t_graph				*ft_init_graph(void);
t_mem				*ft_init_memory(void);
int					ft_print_error(int error_code);
void				ft_set_edge(t_edge *edge, t_vertex *start, t_vertex *end, \
					int flow, int oriented, int cost);
t_edge				*ft_new_edge(t_vertex *start, t_vertex *end, int flow, \
					int oriented, int cost);
t_vertex 			*ft_new_verex(int vertex_id, char* name);
int					ft_add_edge(t_vertex *start, t_vertex *end, int flow, \
					int oriented, int cost);
t_vertex			*ft_add_vertex_back(t_graph *graph, t_vertex *vertex);
void				ft_remove_edge(t_edge **edge);
void				ft_split_edge(t_edge **edge);
void				ft_remove_vertex(t_graph **graph, t_vertex **vertex);
void				ft_convert_graph_to_oriented(t_graph **graph);
void				ft_split_vertex(t_graph *graph);
void				ft_split_all_edges(t_vertex *vertex);
int					ft_min_cost_flow(t_graph *graph);
void				ft_reverse_edge_vertex(t_vertex *start,  t_vertex *end);
t_path				*ft_new_path(t_vertex *path_head);
t_path				*ft_find_shortest_path(t_list *path_list);
void				ft_push_ant(t_list *path_list, t_graph *graph, int *id);
void				ft_add_ant(t_path *path);
int					ft_set_ant_to_pash(int total_ant, t_list *path_list);
t_list				*ft_new_path_list(t_graph *graph);
int					ft_accept_path(t_graph *graph);
int					ft_get_pash_len(const t_graph *graph, t_vertex *vertex);
void				ft_del_graph(t_graph **graph);
void				ft_remove_zero_flow(t_graph *graph);
#endif