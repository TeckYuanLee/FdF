#include "fdf.h"

int		abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	abs_float(float n)
{
	if (n < 0.0)
		return (-n);
	return (n);
}