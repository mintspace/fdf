/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:53:56 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/07 19:54:20 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_fit(int x, int y, t_fgroup *fgroup)
{
	if (x > 2400  + fgroup->move_x + fgroup->land_width
		|| y > 2400 + fgroup->move_y + fgroup->land_height
		|| x < 0 - fgroup->move_x - fgroup->land_width
		|| y < 0 - fgroup->move_y - fgroup->land_height)
		return (0);
	return (1);
}

void bres_line(float x0, float y0, float x1, float y1, t_fgroup *fgroup)
{
	float	d_x;
	float	d_y;
	float	step_x;
	float	step_y;
	int		z0;
	int		z1;

	z0 = fgroup->land[(int)y0][(int)x0] * fgroup->scale_z;
	z1 = fgroup->land[(int)y1][(int)x1] * fgroup->scale_z;
	fgroup->color = (fgroup->land[(int)y0][(int)x0] != 0) ? 0xff0000 : 0x34e8eb;
	zoom_scale(&x0, &y0, &x1, &y1, fgroup);
	if (fgroup->perspective == 1)
	{
		isometric(&x0, &y0, z0, fgroup->rot);
		isometric(&x1, &y1, z1, fgroup->rot);
	}
	d_x = x1 - x0;
	d_y = y1 - y0;
	step_x = d_x / MAX(ft_abs(d_x), ft_abs(d_y));
	step_y = d_y / MAX(ft_abs(d_x), ft_abs(d_y));
	while (((int)(x0 - x1) || (int)(y0 - y1)) && is_fit(x0, y0, fgroup))
	{
		mlx_pixel_put(fgroup->mlx_ptr, fgroup->win_ptr,
		x0 + fgroup->move_x, y0 + fgroup->move_y, fgroup->color);
		x0 += step_x;
		y0 += step_y;
	}
}
