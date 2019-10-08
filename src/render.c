/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:42:49 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/07 18:33:01 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_fgroup *fgroup)
{
	int		i;
	int		j;

	j = 0;
	mlx_clear_window(fgroup->mlx_ptr, fgroup->win_ptr);
	while (j < fgroup->land_height)
	{
		i = 0;
		while (i < fgroup->land_width)
		{
			if (i < fgroup->land_width - 1)
				bres_line(i, j, i + 1, j, fgroup);
			if (j < fgroup->land_height - 1)
				bres_line(i, j, i, j + 1, fgroup);
			i++;
		}
		j++;
	}
}
