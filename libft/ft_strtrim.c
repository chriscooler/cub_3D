#include "libft.h"

int	is_in_charset(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_charset(set, s1[start]))
		start++;
	while (end > start && is_in_charset(set, s1[end - 1]))
		end--;
	out = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (start < end)
		out[i++] = s1[start++];
	out[i] = 0;
	return (out);
}
