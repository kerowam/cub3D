/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 04:07:32 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/01 22:27:24 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(char **texture, t_map *info_map)
{
	if (!strncmp(texture[0], "NO", 3))
		info_map->north_texture_path = ft_strdup(texture[1]);
	else if (!strncmp(texture[0], "SO", 3))
		info_map->south_texture_path = ft_strdup(texture[1]);
	else if (!strncmp(texture[0], "EA", 3))
		info_map->east_texture_path = ft_strdup(texture[1]);
	else if (!strncmp(texture[0], "WE", 3))
		info_map->west_texture_path = ft_strdup(texture[1]);
}

void	get_color(char **texture, t_map *info_map)
{
	char	**color;

	color = ft_split(texture[1], ',');
	if (!color || color[3])
	{
		write (2, "Error: Invalid map\n", 19);
		exit (1);
		return ;
	}
	if (!strncmp(texture[0], "F", 2))
	{
		info_map->floor[0] = ft_atoi(color[0]);
		info_map->floor[1] = ft_atoi(color[1]);
		info_map->floor[2] = ft_atoi(color[2]);
	}
	else if (!strncmp(texture[0], "C", 2))
	{
		info_map->ceiling[0] = ft_atoi(color[0]);
		info_map->ceiling[1] = ft_atoi(color[1]);
		info_map->ceiling[2] = ft_atoi(color[2]);
	}
	free_split(color);
}

void	get_textures_and_colors(char *line, t_map *info_map, int *n)
{
	char	**texture;

	texture = ft_split(line, ' ');
	if (!texture || texture[2])
	{
		write (2, "Error: Invalid map\n", 19);
		free (line);
		exit (1);
		return ;
	}
	if (!strncmp(texture[0], "NO", 3) || !strncmp(texture[0], "SO", 3)
		|| !strncmp(texture[0], "EA", 3) || !strncmp(texture[0], "WE", 3))
	{
		get_texture(texture, info_map);
		*n += 1;
	}
	else if (!strncmp(texture[0], "F", 2) || !strncmp(texture[0], "C", 2))
	{
		get_color(texture, info_map);
		*n += 1;
	}
	free_split(texture);
}

int	check_line_map(char *line)
{
	int	i;
	int	map;

	i = 0;
	map = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0'
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == '\n' || line[i] == '\t')
		{
			if (line[i] == '1' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'E'
				|| line[i] == 'S' || line[i] == 'W')
				map++;
			i++;
		}
		else
			return (0);
	}
	if (map > 0)
		return (1);
	else
		return (0);
}

void	get_width(char *line, t_map *info_map)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
			i++;
		/*else if (line[i] == '\t')
			i += 4;*/
		else if (line[i] == '1' || line[i] == '0' || line[i] == 'W'
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S')
		{
			i++;
			width = i;
		}
	}
	if (width > info_map->map_width)
		info_map->map_width = width;
}

void	get_line_map(char *line, t_map *info_map, int y)
{
	int	x;

	x = 0;
	info_map->map[y] = (char *)malloc(info_map->map_width + 1);
	if (!info_map->map[y])
	{
		write (2, "Error: Invalid map\n", 19);
		free (line);
		exit (1);
		return ;
	}
	while (x < info_map->map_width)
	{
		while (line[x] && line[x] != '\n')
		{
			info_map->map[y][x] = line[x];
			x++;
		}
		while (x < info_map->map_width)
		{
			info_map->map[y][x] = ' ';
			x++;
		}
		info_map->map[y][x] = '\0';
	}
}

void	get_map(char *line, t_map *info_map, int *n)
{
	int	y;

	y = *n - 6;
	if (!ft_strncmp(line, "\n", 2) && info_map->map_status == 1)
		info_map->map_status = 2;
	if (check_line_map(line) && (info_map->map_status == 0 || info_map->map_status == 1))
	{
		if (info_map->map_status == 0)
			info_map->map_status = 1;
		if (info_map->map_status == 1)
		{
			get_line_map(line, info_map, y);
			*n += 1;
		}
	}
	//else if...
	else if (ft_strncmp(line, "\n", 2) && info_map->map_status == 2)
	{
		write (2, "Error: Invalid map\n", 19);
		free (line);
		exit (1);
		return ;
	}
}

void	get_map_size(int fd, t_map *info_map)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_line_map(line))
		{
			count++;
			get_width(line, info_map);
		}
	}
	info_map->map_height = count;
	info_map->map = (char **)malloc(sizeof(char *) * info_map->map_height);
	if (!info_map->map)
	{
		write(2, "Error: Memory allocation failled\n", 33);
		exit(1);
		return ;
	}
}

void	get_map_info(char *file, t_map *info_map)
{
	char	*line;
	int		n;
	int		fd;

	n = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: Cannot open file\n", 24);
		exit(1);
		return ;
	}
	get_map_size(fd, info_map);
	close(fd);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		while (n < 7 && !ft_strncmp(line, "\n", 2))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (line && line[0] && n < 6)
			get_textures_and_colors(line, info_map, &n);
		else if (line && line[0] && n >= 6)
			get_map(line, info_map, &n);
		free(line);
	}
	close (fd);
}