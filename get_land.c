/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_land.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:38:30 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/03 21:30:57 by dbubnov          ###   ########.fr       */
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
}

void get_land_width(char *land, t_fgroup *fgroup)
{
	int		fd;
	char	*str;

	fgroup->land_width = 0;
	fd = open(land, O_RDONLY);
	get_next_line(fd, &str);
	fgroup->land_width = ft_wdcount(str, ' ');
	free(str);
}

int read_file(char *file_name, t_fgroup *fgroup)
{
	get_land_height(file_name, fgroup); // read file
	get_land_width(file_name, fgroup);
	return (0);
}