/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:53:56 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/02 12:54:58 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bres_line(float x0,  float y0, float x1, float y1)
{
    float d_x;
    float d_y;
    float step_x;
    float step_y;

    d_x = x1 - x0;
    d_y = y1 - y0;

    step_x = d_x / MAX(ft_abs(d_x), ft_abs(d_y));
    step_y = d_y / MAX(ft_abs(d_x), ft_abs(d_y));
    
    while ((int)x0 != (int)x1 || (int)y0 != (int)y1)
    {  
        mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x34e8eb);
        x0 += step_x;
        y0 += step_y;       
    }
}