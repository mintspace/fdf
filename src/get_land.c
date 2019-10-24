/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_land.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:38:30 by dbubnov           #+#    #+#             */
/*   Updated: 2019/10/10 13:57:53 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_land_height(char *land, t_fgroup *fgroup)
{
	int		fd;
	char	*str;

	fgroup->land_height = 0;
	fd = open(land, O_RDONLY);
	ft_error_fd(fd);
	while (get_next_line(fd, &str) > 0)
	{
		fgroup->land_height++;
		free(str);
	}
	free(str);
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

	i = 0;
	fgroup->land = (int **)malloc(sizeof(int *) * fgroup->land_height);
	while (i < fgroup->land_height)
	{
		fgroup->land[i] = (int *)malloc(sizeof(int) * fgroup->land_width);
		i++;
	}
}

void	land_fill_str(int land_counter, char *str, t_fgroup *fgroup)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_strsplit(str, ' ');
	while (i < fgroup->land_width)
	{
		fgroup->land[land_counter][i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

void	land_fill(char *land, t_fgroup *fgroup)
{
	int		fd;
	int		land_counter;
	char	*str;

	fd = open(land, O_RDONLY);
	land_counter = 0;
	while (get_next_line(fd, &str) > 0)
	{
		land_fill_str(land_counter, str, fgroup);
		free(str);
		land_counter++;
	}
	free(str);
	close(fd);
}
