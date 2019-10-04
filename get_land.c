/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_land.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metalium <metalium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:38:30 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/04 09:23:39 by metalium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_land_height(char *land, t_fgroup *fgroup) // land = "42.filler"
{
	int		fd;
	char	*str;

	fgroup->land_height = 0;
	fd = open(land, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		fgroup->land_height++;
		free(str);
	}
	close(fd);
}

void	get_land_width(char *land, t_fgroup *fgroup)
{
	int		fd;
	char	*str;

	fgroup->land_width = 0;
	fd = open(land, O_RDONLY);
	get_next_line(fd, &str);
	fgroup->land_width = ft_wdcount(str, ' ');
	free(str);
	close(fd);
}

void	land_alocate(t_fgroup *fgroup)
{
	int		i;

	fgroup->land = (int **)malloc(sizeof(int *) * fgroup->land_height);
	while (i < fgroup->land_height)
	{
		fgroup->land[i] = (int *)malloc(sizeof(int) * fgroup->land_width);
		i++;
	}
}

void	land_fill_str(char *str, t_fgroup *fgroup)
{

}

void	land_fill(char *land, t_fgroup *fgroup)
{
	int		fd
	char	*str;

	while ()


}

// Get if done

int		read_file(char *file_name, t_fgroup *fgroup)
{
	get_land_height(file_name, fgroup); // read file
	get_land_width(file_name, fgroup);
	land_alocate(fgroup);
	land_fill(file_name, fgroup);
	return (0);
}
