#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	i = -1;
	if (start + len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof (char));
	if (!sub)
		return (NULL);
	while (++i < len && s[start + i])
		sub[i] = s[start + i];
	sub[i] = 0;
	return (sub);
}
