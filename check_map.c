/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:54:54 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/02 18:07:55 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line_map(char *line, int mode)
{
	int	i;
	int	map;

	i = 0;
	map = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0'
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == '\n' || line[i] == '\t')
		{
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				map++;
			i++;
		}
		else
		{
			invalid_map(mode);
			return (0);
		}
	}
	if (map > 0)
		return (1);
	else
		return (0);
}

void	check_all_ones(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == ' ' || line[x] == '\t' || line [x] == '1')
			x++;
		else
		{
			write (2, "Error: Invalid map\n", 19);
			exit (1);
			return ;
		}
	}
	return ;
}

int	check_valid_neighbor(t_map *info_map, int y, int x)
{
	if (info_map->map[y][x] != '1' && info_map->map[y][x] != '0'
		&& info_map->map[y][x] != 'N' && info_map->map[y][x] != 'S'
		&& info_map->map[y][x] != 'E' && info_map->map[y][x] != 'W')
		return (1);
	else
		return (0);
}

void	check_map_limits(t_map *info_map, int y)
{
	int	x;

	x = 0;
	while (info_map->map[y][x])
	{
		if (info_map->map[y][x] == ' ' || info_map->map[y][x] == '\t'
			|| info_map->map[y][x] == '1')
			x++;
		else if (info_map->map[y][x] == '0' || info_map->map[y][x] == 'N'
			|| info_map->map[y][x] == 'S' || info_map->map[y][x] == 'E'
			|| info_map->map[y][x] == 'W')
		{
			if (x == 0 || x == info_map->map_width - 1
				|| check_valid_neighbor(info_map, y, x - 1)
				|| check_valid_neighbor(info_map, y, x + 1)
				|| check_valid_neighbor(info_map, y - 1, x)
				|| check_valid_neighbor(info_map, y + 1, x))
			{
				invalid_map(1);
				return ;
			}
			x++;
		}
	}
}

void	check_closed_map(t_map *info_map)
{
	int	y;

	y = 0;
	while (y < info_map->map_height)
	{
		if (y == 0 || y == info_map->map_height - 1)
			check_all_ones(info_map->map[y]);
		else
			check_map_limits(info_map, y);
		y++;
	}
}
