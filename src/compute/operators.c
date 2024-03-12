#include "../cub3d.h"

double	vec_cross(double *v1, double *v2)
{
	return (v1[0] * v2[1] - v1[1] * v2[0]);
}

void	sub_vec(double *v1, double *v2, double *res)
{
	res[0] = (v2[0] - v1[0]);
	res[1] = (v2[1] - v1[1]);
}

void	add_vec(double *v1, double *v2, double *res)
{
	res[0] = (v2[0] + v1[0]);
	res[1] = (v2[1] + v1[1]);
}

double	dot(double *v1, double *v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1]);
}

void	vec_mult(double *v, double c, double *res)
{
	res[0] = v[0] * c;
	res[1] = v[1] * c;
}
