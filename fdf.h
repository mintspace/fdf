/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:57:14 by metalium          #+#    #+#             */
/*   Updated: 2019/10/01 10:12:35 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct s_fgroup
{
	int		map_x;
	int		map_y;
	char	**map;
	char	**map_color;
}			t_fgroup;


#endif
