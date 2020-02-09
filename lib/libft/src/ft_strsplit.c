/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:39:33 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 19:21:28 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_word_count(const char *str, char c)
{
	char	*ptr;
	int		count;

	ptr = (char*)str;
	count = 0;
	if (*ptr != c && *ptr)
		++count;
	while (*ptr)
	{
		if (*ptr == c && *(ptr + 1) != c && *(ptr + 1))
			++count;
		++ptr;
	}
	return (count);
}

static int	get_word_len(const char *str, char c)
{
	int len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

static char	*ft_strncpy_plus(char *dst, char **src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (**src && len)
	{
		*(dst++) = *((*src)++);
		--len;
	}
	while (len--)
		*(dst++) = 0;
	return (tmp);
}

static void	*free_tab(char **tab, int i)
{
	while (i)
	{
		free(tab[--i]);
		tab[i] = NULL;
	}
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*ptr;
	int		len;
	int		word_count;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	ptr = (char*)s;
	if (!(tab = (char**)malloc(sizeof(s) * (word_count + 1))))
		return (NULL);
	tab[word_count] = NULL;
	while (++i < word_count)
	{
		while (*ptr == c)
			++ptr;
		len = get_word_len(ptr, c);
		if (!(tab[i] = ft_strnew(len * sizeof(*s))))
			return (free_tab(tab, i));
		tab[i][len] = 0;
		tab[i] = ft_strncpy_plus(tab[i], &ptr, len);
	}
	return (tab);
}
