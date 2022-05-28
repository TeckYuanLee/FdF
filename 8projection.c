#include "fdf.h"

void	apply_perspective(t_coor *coor, double Z0)
{
	coor->x = (coor->x * Z0) / (Z0 + coor->z);
	coor->y = (coor->y * Z0) / (Z0 + coor->z);
}

void	apply_iso(t_coor *coor, float iso_rad_const)
{
	t_coor	tmp;

	tmp.x = coor->x;
	tmp.y = coor->y;
	coor->x = (tmp.x - tmp.y) * cos(iso_rad_const);
	coor->y = -(coor->z) + (tmp.x + tmp.y) * sin(iso_rad_const);
	coor->z = coor->z;
}

void	switch_projection(int *projection)
{
	if (*projection == ISOMETRIC)
		*projection = PERSPECTIVE;
	else
		*projection = ISOMETRIC;
}
