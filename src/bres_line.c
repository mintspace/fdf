/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:53:56 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/10 12:20:44 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_fit(int x, int y, t_fgroup *fgroup)
{
	if (x > 2400 + fgroup->move_x + fgroup->land_width
		|| y > 2400 + fgroup->move_y + fgroup->land_height
		|| x < 0 - fgroup->move_x - fgroup->land_width
		|| y < 0 - fgroup->move_y - fgroup->land_height)
		return (0);
	return (1);
}

void	bres_line(t_cord cord, t_fgroup *fgroup)
{
	cord.z0 = fgroup->land[(int)cord.y0][(int)cord.x0] * fgroup->scale_z;
	cord.z1 = fgroup->land[(int)cord.y1][(int)cord.x1] * fgroup->scale_z;
	fgroup->color = (fgroup->land[(int)cord.y0][(int)cord.x0] != 0)
		? 0xff0000 : 0x34e8eb;
	zoom_scale(&cord, fgroup);
	if (fgroup->perspective == 1)
		isometric(&cord.x0, &cord.y0, cord.z0, fgroup->rot);
	if (fgroup->perspective == 1)
		isometric(&cord.x1, &cord.y1, cord.z1, fgroup->rot);
	cord.d_x = cord.x1 - cord.x0;
	cord.d_y = cord.y1 - cord.y0;
	cord.step_x = cord.d_x / MAX(ft_abs(cord.d_x), ft_abs(cord.d_y));
	cord.step_y = cord.d_y / MAX(ft_abs(cord.d_x), ft_abs(cord.d_y));
	while (((int)(cord.x0 - cord.x1) || (int)(cord.y0 - cord.y1))
		&& is_fit(cord.x0, cord.y0, fgroup))
	{
		mlx_pixel_put(fgroup->mlx_ptr, fgroup->win_ptr,
		cord.x0 + fgroup->move_x, cord.y0 + fgroup->move_y, fgroup->color);
		cord.x0 += cord.step_x;
		cord.y0 += cord.step_y;
	}
}
