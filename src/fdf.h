/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:57:14 by metalium          #+#    #+#             */
/*   Updated: 2019/10/09 16:55:31 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)

typedef struct	s_fgroup
{
	int			zoom;
	int			color;
	int			map_x;
	int			map_y;
	int			**land;
	int			move_x;
	int			move_y;
	int			scale_z;
	void		*mlx_ptr;
	void		*win_ptr;
	int			land_width;
	int			land_height;
	int			perspective;
	float		rot;
}				t_fgroup;

typedef struct	s_cord
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
}				t_cord;


float			ft_abs(float i);
int				ft_error_fd(int fd);
void			render(t_fgroup *fgroup);
void			init_fgroup(t_fgroup *fgroup);
int				ft_error(int argc, char *argv);
int				deal_key(int key, t_fgroup *fgroup);
void			get_land_height(char *land, t_fgroup *fgroup);
void			get_land_width(char *land, t_fgroup *fgroup);
int				read_file(char *file_name, t_fgroup *fgroup);
void			isometric(float *x, float *y, int z, float rot);
void			bres_line(t_cord cord, t_fgroup *fgroup);
void			zoom_scale(t_cord *cord, t_fgroup *fgroup);
void			land_alocate(t_fgroup *fgroup);
void			land_fill(char *land, t_fgroup *fgroup);
void			init_cord(t_cord *cord);

#endif


// float			ft_abs(float i);
// int				ft_error_fd(int fd);
// void			render(t_fgroup *fgroup);
// void			init_fgroup(t_fgroup *fgroup);
// int				ft_error(int argc, char *argv);
// int				deal_key(int key, t_fgroup *fgroup);
// void			get_land_height(char *land, t_fgroup *fgroup);
// void			get_land_width(char *land, t_fgroup *fgroup);
// int				read_file(char *file_name, t_fgroup *fgroup);
// void			isometric(float *x, float *y, int z, float rot);
// void			bres_line(float x0, float y0, float x1,
// 				float y1, t_fgroup *fgroup);
// void			zoom_scale(float *x0, float *y0, float *x1,
// 				float *y1, t_fgroup *fgroup);
// void			land_alocate(t_fgroup *fgroup);
// void			land_fill(char *land, t_fgroup *fgroup);
