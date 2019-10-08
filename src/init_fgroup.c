/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fgroup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:37:21 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/07 18:56:52 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fgroup(t_fgroup *fgroup)
{
	fgroup->zoom = 20;
	fgroup->move_x = 200;
	fgroup->move_y = 200;
	fgroup->rot = 0.8;
	fgroup->scale_z = 1;
	fgroup->perspective = 1;
}
