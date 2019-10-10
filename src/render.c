/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:42:49 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/09 16:52:10 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cord_x(t_cord *cord)
{
	cord->x0++;
	cord->x1++;
}

void	cord_y(t_cord *cord)
{
	cord->y0++;
	cord->y1++;
	cord->x0 = 0;
	cord->x1 = 0;
}

void	render(t_fgroup *fgroup)
{
	t_cord	*cord;

	cord = (t_cord*)malloc(sizeof(t_cord));
	init_cord(cord);
	mlx_clear_window(fgroup->mlx_ptr, fgroup->win_ptr);
	while (cord->y0 < fgroup->land_height)
	{
		while (cord->x0 < fgroup->land_width)
		{
			if (cord->x0 < fgroup->land_width - 1)
			{
				cord->x1++;
				bres_line(*cord, fgroup);
				cord->x1--;
			}
			if (cord->y0 < fgroup->land_height - 1)
			{
				cord->y1++;
				bres_line(*cord, fgroup);
				cord->y1--;
			}
			cord_x(cord);
		}
		cord_y(cord);
	}
}
