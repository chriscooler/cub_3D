#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*d;
	const unsigned char		*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	if (s < d)
		while (++i <= n)
			d[n - i] = s[n - i];
	else
		while (n-- > 0)
			*(d++) = *(s++);
	return (dest);
}
