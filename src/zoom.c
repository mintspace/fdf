/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:11:36 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/09 16:55:55 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_scale(t_cord *cord, t_fgroup *fgroup)
{
	cord->x0 *= fgroup->zoom;
	cord->x1 *= fgroup->zoom;
	cord->y0 *= fgroup->zoom;
	cord->y1 *= fgroup->zoom;
}
