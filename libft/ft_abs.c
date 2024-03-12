#include "libft.h"

int	ft_abs(int n)
{
	return (n * (((n > 0) << 1) - 1));
}

double	ft_abs_d(double d)
{
	if (d < 0)
		return (d * -1);
	return (d);
}
