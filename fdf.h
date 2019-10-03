/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:57:14 by metalium          #+#    #+#             */
/*   Updated: 2019/10/02 18:46:51 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"
# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)


typedef struct s_fgroup
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		map_x;
	int		map_y;
	
	char	**map;
	char	**map_color;
}			t_fgroup;

float		ft_abs(float i);
void		bres_line(float x0,  float y0, float x1, float y1, t_fgroup *fgroup);
int			deal_key(int key, void *data);

#endif