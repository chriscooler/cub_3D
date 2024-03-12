
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*out_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	out_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!out_str)
		return (NULL);
	while (s1 && s1[i])
	{
		out_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		out_str[i++] = s2[j];
		j++;
	}
	out_str[i] = '\0';
	return (out_str);
}
