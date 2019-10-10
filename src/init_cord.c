/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:10:03 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/09 16:54:37 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_cord(t_cord *cord)
{
	cord->x0 = 0;
	cord->x1 = 0;
	cord->y0 = 0;
	cord->y1 = 0;
}