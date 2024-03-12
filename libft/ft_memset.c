#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)dest;
	while (n--)
		*(p++) = (unsigned char)c;
	return (dest);
}
