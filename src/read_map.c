#include "lem_in.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/*
** Carry over these defines in project's header
*/
# define START "##start"
# define END "##end"

int ft_get_ants_count(int fd) {
	int i;
	char *buf;

	i = -1;
	if (!get_next_line(fd, &buf))
		return (-1);
	if (buf[0] == '+')
		i++;
	while (buf[++i] != '\0')
		if (buf[i] < '0' || buf[i] > '9')
			break;
	i = ft_atoi(buf);
	ft_strdel(&buf);
	if (i <= 0)
		return (-1);
	return (i);
}

int ft_str_is_numeric(const char *str) {
	int i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int ft_delete_info(char **spl, int w, int res) {
	int i;

	i = -1;
//	while (++i <= w)
//		free(&spl[i]);
//	free(**spl);
	return (res);
}

int ft_count_char(char *str, char c) {
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str) {
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int ft_get_new_vertex(t_graph *graph, char *buf, int *index) {
	char		**v_info;
	t_vertex	*vertex;

	if (ft_count_char(buf, ' ') != 2)
		return (1);
	if (!(v_info = ft_strsplit(buf, ' ')))
		return (1);
	if (!ft_str_is_numeric(v_info[1]) || !ft_str_is_numeric(v_info[2]))
		return (ft_delete_info(v_info, 3, 1));
	vertex = ft_new_verex(index[0], v_info[0]);
	if (*index == -2 || *index == 0)
		ft_add_vertex_front(graph, vertex);
	else
		ft_add_vertex_back(graph, vertex);
	*index += 2;
	return (ft_delete_info(v_info, 3, 0));
}

int ft_get_start_end(t_graph *graph, char *buf, int fd)
{
	static int	start;
	static int	end;
	int			status;

	start = 0;
	end = 0;
	status = !(ft_strcmp(buf, START)) ? 0 : 1;
	status = !(ft_strcmp(buf, END)) ? -2 : status;
	if (status == 1)
		return (0);
	if ((status == 0 && start > 0) || (status == -2 && end > 0))
		return (1);
	ft_strdel(&buf);
	if (!get_next_line(fd, &buf) || !ft_strlen(buf))
		return (1);
	start += (status == 0) ? 1 : 0;
	end += (status == -2) ? 1 : 0;
	status = ft_get_new_vertex(graph, buf, &status);
	return (status);
}

char *ft_get_vertex(t_graph *graph, int fd) {
	char *buf;
	int next_index;
	int err;

	next_index = 2;
	err = 0;
	while (get_next_line(fd, &buf) && \
			ft_strlen(buf) && (buf[0] == '#' || ft_strchr(buf, ' '))) {
		if (buf[0] != '#')
			err = ft_get_new_vertex(graph, buf, &next_index);
		else if (buf[0] == '#' && buf[1] != '#') {
			ft_strdel(&buf);
			continue;
		}
		else
			err = ft_get_start_end(graph, buf, fd);
		//ft_strdel(&buf);
		if (err == 1)
			return (NULL);
	}
	return (buf);
}


int ft_char_in_str(const char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

t_vertex	*ft_find_vertex(t_graph *graph, char *name)
{
	t_vertex	*vertex;
	int 		i;

	i = ft_lstdlen(graph->vertex_list);
	while (i--) {
		vertex = (t_vertex *) graph->vertex_list->content;
		if (!ft_strcmp(vertex->name, name))
			return (vertex);
		graph->vertex_list = graph->vertex_list->next;
	}
	return (NULL);
}

t_forward_list	*ft_add_to_end(t_forward_list *list, void *content, size_t size) {
	if (!list)
		list = ft_lstnew(content, size);
	else
		list->next = ft_lstnew(content, size);
	return (list->next);
}

int 			ft_check_n_add_edge(char *name1, char *name2, t_forward_list *list, t_graph *graph)
{
	t_vertex	*vertex1;
	t_vertex	*vertex2;
	char 		*concat;

	concat = ft_strjoin(name1, name2);
	while (list)
	{
		if (!ft_strcmp(concat, list->content)) {
			ft_strdel(&concat);
			return (1);
		}
		list = list->next;
	}
	if (!(vertex1 = ft_find_vertex(graph, name1)))
		return (0);
	if (!(vertex2 = ft_find_vertex(graph, name2)))
		return (0);
	ft_add_edge(vertex1, vertex2, 0, 0);
	list = ft_add_to_end(list, concat, ft_strlen(concat));
	ft_strdel(&concat);
	concat = ft_strjoin(name2, name1);
	list = ft_add_to_end(list, concat, ft_strlen(concat));
	return (1);
}

int 			ft_get_edges(t_graph *graph, char *buf, int fd)
{
	char			*name1;
	char 			*name2;
	t_forward_list	*edge_list;

	edge_list =	 NULL;
	while (buf && ft_strlen(buf)) {
		if (buf[0] != '#')
		{
			if (ft_count_char(buf, '-') != 1)
				return (0);
			name1 = ft_strsub(buf, 0, ft_char_in_str(buf, '-'));
			name2 = ft_strsub(buf, ft_char_in_str(buf, '-') +  1, ft_strlen(ft_strchr(buf, '-')));
			if (!ft_check_n_add_edge(name1, name2, edge_list, graph))
				return (0);
		}
		ft_strdel(&name1);
		ft_strdel(&name2);
		ft_strdel(&buf);
		get_next_line(fd, &buf);
	}
	ft_strdel(&buf);
	ft_lst_del(&edge_list);
	return (1);
}

int ft_get_graph(t_graph **graph, int fd) {
	char *buf;

	if (!(*graph = (t_graph *) malloc(sizeof(t_graph))))
		return (0);
	(*graph)->vertex_list = NULL;
	if (((*graph)->ants_count = ft_get_ants_count(fd)) == -1)
		return (0);
	if (!(buf = ft_get_vertex(*graph, fd)))
		return (0);
	if (!ft_get_edges(*graph, buf, fd))
		return (0);
	return (1);
}