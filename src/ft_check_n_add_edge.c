#include "lem_in.h"
#include "libft.h"

void		ft_add_to_end(t_list **list, void **content, size_t size)
{
	t_list	*temp;

	if (!(*list))
		*list = ft_lstdnew(*content, size);
	else
	{
		temp = ft_lstdnew(*content, size);
		ft_lstd_push_back(list, temp);
	}
	ft_memdel((void **)content);
}

static int ft_vertex_cmp(char *str1, char *str2, int id1, int id2)
{
	if (str1[0] == str2[0] && str1[1] == str2[1])
	{
		if (!ft_strcmp(str1, str2) && \
		!((id1 == 0 && id2 == -2) || (id1 == -2 && id2 == 0)))
			return (1);
	}
	return (0);
}

static int 	ft_check_repeat(t_list **list, t_vertex *v1, t_vertex *v2)
{
	int		res;
	char	*str1;
	char	*str2;
	t_list	*head;

	str1 = ft_strjoin(v1->name, v2->name);
	str2 = ft_strjoin(v2->name, v1->name);
	head = NULL;
	res = 0;
	while ((*list) && (*list)->next != head)
	{
		if ((res = ft_vertex_cmp(str1, (*list)->content, v1->id, v2->id)))
			break ;
		if ((res = ft_vertex_cmp(str2, (*list)->content, v1->id, v2->id)))
			break ;
		if (!head)
			head = *list;
		*list = (*list)->next;
	}
	ft_memdel((void **)&str2);
	if (!res)
		ft_add_to_end(list, (void **)&str1, ft_strlen(str1));
	return (res);
}

static int 	ft_clear_names(char **name1, char **name2, int res)
{
	ft_memdel((void **)name1);
	ft_memdel((void **)name2);
	return (res);
}

int			ft_check_n_add_edge(char **name1, char **name2, t_list **list, \
			t_graph *graph)
{
	t_vertex	*vertex1;
	t_vertex	*vertex2;


	if (!ft_strcmp(*name1, *name2))
		return (ft_clear_names(name1, name2, 1));

	if (!(vertex1 = ft_find_vertex_by_name(graph, *name1)))
		return (ft_clear_names(name1, name2, 0));
	if (!(vertex2 = ft_find_vertex_by_name(graph, *name2)))
		return (ft_clear_names(name1, name2, 0));
	if (ft_check_repeat(list, vertex1, vertex2))
		return (ft_clear_names(name1, name2, 1));
	ft_add_edge(vertex1, vertex2, 0, 0);

//	concat = ft_strjoin(*name2, *name1);
//	ft_add_to_end(list, (void **)&concat, ft_strlen(concat));
	return (ft_clear_names(name1, name2, 1));
}