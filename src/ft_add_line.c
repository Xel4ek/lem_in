#include "libft.h"

void	ft_add_line(char **line1, char **line2)
{
	if (!(*line1) && (*line2))
	{
		*line1 = ft_strdup(*line2);
		*line1 = ft_strjoin_free_first(line1, "\n");
		return ;
	}
	if (!(*line2))
		return ;
	*line1 = ft_strjoin_free_first(line1, *line2);
	*line1 = ft_strjoin_free_first(line1, "\n");
	ft_memdel((void **)line2);
}