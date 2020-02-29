

#ifndef LEM_IN_H
#define LEM_IN_H

#include <libft_structs.h>

enum e_color{
	white,
	grey,
	black
};

typedef struct	s_vertex
{

	t_list		*edge_in_list;
	t_list		*edge_out_list;
	struct s_vertex *parrent;
	char		*name;
	int			weight;
	int			potecial;
    int			id;
	enum e_color	color;
	int			ant_id;
	int			x;
	int			y;
	int			test;

}				t_vertex;

typedef struct s_edge
{
	t_vertex		*start;
	t_vertex		*end;
    int				flow;
    int				cost;
	int 			oriented;
//	int 			pash;
}				t_edge;

typedef struct s_path
{
	t_vertex *head;
	int		price;
	int		ant_count;
}			t_path;

typedef struct	s_graph
{
	t_list		*vertex_list;
	t_vertex 	*source;
	t_vertex 	*sink;
	int			vertex_count;
	int 		sink_id;
	int			source_id;
	int			ants_count;
	int			pash_count;
	int			path_lenght;

}				t_graph;

typedef struct	s_gptr
{
	t_graph 	*graph;
	t_vertex	*vertex1;
	t_vertex 	*vertex2;
	char 		*name1;
	char 		*name2;
}				t_gptr;

typedef struct	s_map
{
	int 		fd;
	int			size;
	t_list 		*map;
}				t_map;

typedef struct 		s_hash
{
	int 			hash;
	char 			*name;
	void 			*content;
	struct	s_hash	*next;
}					t_hash;

typedef	struct		s_edgename
{
	char 			*name1;
	char 			*name2;
}					t_edgename;


# define START "##start"
# define END "##end"
# define HASHTAB_SIZE 1024

int			ft_get_graph(t_graph **graph, t_map *map);
char 		*ft_get_vertex(t_graph *graph, t_map *map, t_hash **hashtab);
int			ft_get_edges(t_graph *graph, char *buf,t_map *map, t_hash **hashtab);
int			ft_check_n_add_edge(t_edgename *e_names, t_hash **edge_hash, \
			t_graph *graph, t_hash **hashtab);
int			ft_get_ants_count(t_map *map);
t_vertex	*ft_find_vertex_by_name(t_graph *graph, char *name);
t_vertex	*ft_find_vertex_by_id(t_graph *graph, int id);
t_vertex	*ft_find_vertex_by_coo(t_graph *graph, int x, int y);
int			ft_count_char(char *str, char c);
int			ft_char_in_str(char *str, char c);
int			ft_get_valid_nbr(const char *str);
void		ft_add_to_map(t_map *map, char **line, int size);
void		ft_print_map(t_map *map);
int			ft_check_start_end(t_graph *graph);
void		ft_add_to_hash(t_hash **hashtab, void *content, char *name);
t_vertex	*ft_find_vertex_in_hash(t_hash **hashtab, char *name);
t_vertex 	*ft_add_and_return_vertex_front(t_graph *graph, t_vertex **vertex);
t_vertex 	*ft_add_and_return_vertex_back(t_graph *graph, t_vertex **vertex);
int			ft_find_edge_in_hash(t_hash **hash, char *name);
int 		ft_delete_edge_hash(t_hash **edge_hash, int res);
int 		ft_delete_hashtab(t_hash **hashtab, int res);
t_hash		**ft_init_hash(int size);

t_graph *mygraph(void);
void ft_print_graph(const t_graph *graph);
void 	ft_print_vertex(t_vertex *vertex);
void	ft_set_edge(t_edge *edge, t_vertex *start, t_vertex *end, int flow, int oriented, int cost);
t_edge	*ft_new_edge(t_vertex *start, t_vertex *end, int flow, int oriented, int cost);
void ft_print_matrix(t_edge ***matrix, int size);
t_vertex *ft_new_verex(int vertex_id, char* name);
void ft_print_vertex_all(t_vertex **vertex_list_link, int size);
void ft_set_vertex(t_vertex *vertex, int vertex_id, const char *name);
int ft_add_edge(t_vertex *start, t_vertex *end, int flow, int oriented, int cost);
void ft_print_egde(t_edge *edge);
void ft_print_egde_list(t_list *egde_list);
void ft_add_vertex_back(t_graph *graph, t_vertex *vertex);
void ft_remove_edge(t_edge **edge);
void ft_split_edge(t_edge **edge);
void ft_remove_vertex(t_graph **graph, t_vertex **vertex);
void ft_convert_graph_to_oriented(t_graph **graph);
void ft_split_vertex(t_graph *graph);//, t_vertex **vertex);
void ft_split_all_edges(t_vertex *vertex);
void	*ft_queue_pop(t_list **queue);

void ft_print_egde_fd(int fd, t_edge *edge);
void ft_print_egde_list_dot(int fd, t_list *egde_list);
void ft_save_digraph_as_dot(int fd, const t_graph *graph);
void ft_save_digraph_as_dot2(int fd, const t_graph *graph);
void ft_print_vertex_dot(int fd, t_vertex *vertex);
void ft_save_graph_as_dot(int fd, const t_graph *graph);

void ft_print_not_oriented_egde_fd(int fd, t_edge *edge);
void ft_print_not_oriented_egde_list_dot(int fd, t_list *egde_list);
t_list			*ft_queue_new(void *content);
void ft_add_vertex_front(t_graph *graph, t_vertex *vertex);
void ft_split_all_graph_edge(t_graph *graph);
void ft_reset_edge_oriented(t_graph *graph);

void ft_reverse_edge(t_edge **edge);

int ft_min_cost_flow(t_graph *graph);
void ft_reverse_edge_vertex(t_vertex *start,  t_vertex *end);

void ft_squeeze_graph(t_graph *graph);
t_path *ft_new_path(t_vertex *path_head);
t_path *ft_find_shortest_path(t_list *path_list);
void ft_push_ant(t_list *path_list, t_graph *graph, int *id);
void ft_add_ant(t_path *path);
int ft_set_ant_to_pash(int total_ant, t_list *path_list);
t_list * ft_new_path_list(t_graph *graph);
int ft_accept_path(t_graph *graph);
int ft_get_pash_len(const t_graph *graph, t_vertex *vertex);
void ft_del_graph(t_graph **graph);
void ft_ford_bellman(t_graph *graph);
void	*ft_queue_min_pop(t_list **queue);
void ft_remove_zero_flow(t_graph *graph);

t_graph *mygraph(void);
#endif