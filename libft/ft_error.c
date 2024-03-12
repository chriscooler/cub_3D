#include "libft.h"

int	ft_error(char *prog, char *msg, int ret, void *to_free)
{
	write(2, "Error\n", 6);
	free(to_free);
	write(2, prog, ft_strlen(prog));
	write(2, " : ", 3);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (ret);
}
