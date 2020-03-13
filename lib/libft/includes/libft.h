/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:17:51 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:22:32 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft_structs.h"
# define HIMAGIC	0x8080808080808080L
# define LOMAGIC	0x0101010101010101L
# define HASHSIZE	12037
# define INITHASHSIZE 16
# define MAX_FD 1024
# define BUFF_SIZE 1024

void			ft_striter(char *s, void (*f)(char *));
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strclr(char *s);
char			*ft_strcat(char *dst, const char *src);
int				ft_isascii(int ch);
int				ft_isdigit(int ch);
int				ft_isprint(int ch);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy (char *dst, const char *src, size_t len);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str1, const char *str2);
char			*ft_strnstr(const char *big, const char *little,\
							size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int ch);
int				ft_isalnum(int ch);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
void			ft_swap(int *a, int *b);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_forward_list	*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_forward_list **alst,
					void (*del)(void *, size_t));
void			ft_lstdel(t_forward_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_forward_list **alst,
					t_forward_list *new);
void			ft_lstiter(t_forward_list *lst,
					void (*f)(t_forward_list *elem));
t_forward_list	*ft_lstmap(t_forward_list *lst,
					t_forward_list *(*f)(t_forward_list *elem));
void			ft_putendl_fd(char const *s, int fd);
char			*ft_itoa_base(int nbr, int base);
int				ft_atoi_base(const char *str, int base);
char			*ft_strcapitalize(char *str);
int				ft_lstlen(const t_forward_list *list);
void			ft_sort_str_table(char **tab, int size);
int				get_next_line(const int fd, char **line);
t_forward_list	*ft_lstappend(t_forward_list *head, t_forward_list *new);
void			ft_lst_del(t_forward_list **alst);
char			*ft_memjoin(void const *src1, void const *src2,
					size_t size1, size_t size2);
int				ft_ceil(long double nbr);
int				ft_unbrlen(uintmax_t nbr, int base);
int				ft_nbrlen(intmax_t nbr);
char			*ft_strjoin_free_first(char **s1, char const *s2);
char			*ft_strjoin_free_second(char const *s1, char **s2);
char			*ft_strch(const char *str, int ch);
size_t			ft_putstr_ptr_fd(const int fd, char const *start,
					char const *finish);
void			ft_lstditer(t_list *list, void (*f)());
int				ft_lstdlen(const t_list *list);
void			ft_lstd_push_front(t_list **head, t_list *new);
t_list			*ft_lstdnew(void const *content, size_t content_size);
void			ft_lstd_pop_front(t_list **head);
void			ft_lstd_del(t_list **list);
char			*ft_strcat_end(char *dst, const char *src);
void			ft_lstd_push_back(t_list **head, t_list *new);
void			ft_str_to_lstd(char *string, t_list **list1, t_list **list2);
void			ft_lstditer_two(t_list *list1, t_list *list2,
					void (*f)(t_list *elem));
void			ft_quick_sort(int *start, int *finish);
unsigned int	ft_hash_old(const char *string, unsigned int size);
void			ft_hash_del(t_list **hash_table, unsigned size);
size_t			ft_max(size_t first, size_t second);
int				ft_abs(int digit);
int				ft_min(int first_digit, int second_digit);
void			ft_lstd_pop_front_head_only(t_list **head);
char			*ft_strcpy_end(char *dst, const char *src);
t_list			*ft_lstd_wrap(void *content, size_t content_size);
t_heap			*ft_heap_merge(t_heap *first, t_heap *second);
t_heap			*ft_wrap_heap(int key, void *value);
void			*ft_pop_min_heap(t_heap **heap, int *key);
t_heap			*ft_heap_add(t_heap *heap, t_heap *new_item);
int				fast_get_next_line(const int fd, char **line, \
				t_mem *const memory);
int				fast_read_in_memory(const int fd, t_mem *const memory);
t_hash			*ft_hash_init(size_t size);
int				ft_hash_insert(t_hash *hash_tab, t_hash new);
t_hash			ft_hash(const char *string, unsigned int size);
int				ft_set_insert(t_set **set, char *content);
void			*ft_set_isexist(t_set *set, size_t key);
t_set			*ft_init_set(size_t size);
void			*ft_set_get_value(t_set *set, char *value);
t_set			*ft_set_update(t_set *set);
void			ft_hash_destroy(t_hash **hashtab, size_t size);
void			ft_set_destroy(t_set **set);
long long int	ft_ceil_ll(long double nbr);
#endif
