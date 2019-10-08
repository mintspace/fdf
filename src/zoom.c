/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:11:36 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/07 18:48:31 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_scale(float *x0, float *y0, float *x1, float *y1, t_fgroup *fgroup)
{
	*x0 *= fgroup->zoom;
	*x1 *= fgroup->zoom;
	*y0 *= fgroup->zoom;
	*y1 *= fgroup->zoom;
}
