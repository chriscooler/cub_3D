#include "libft.h"

signed long long	ft_atol(const char *str)
{
	signed long long	n;
	int					sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - 48;
		str++;
	}		
	return ((signed long long)n * sign);
}
