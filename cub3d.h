/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:33:55 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/02 18:55:02 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	*north_texture_path;
	char	*south_texture_path;
	char	*east_texture_path;
	char	*west_texture_path;
	int		floor[3];
	int		ceiling[3];
	int		map_width;
	int		map_height;
	int		map_status;
	int		player;
	char	player_view;
	char	**map;
}	t_map;

// check_args.c

void	check_args(int argc, char **argv);

// init.c

t_map	init_map(void);

// free.c

void	free_split(char **split);
void	free_map(t_map *info_map);

// map.c

void	get_texture(char **texture, t_map *info_map);
void	get_color(char **texture, t_map *info_map);
void	get_textures_and_colors(char *line, t_map *info_map, int *n);
void	get_map_info(char *file, t_map *info_map);

// colors_and_textures.c

void	get_texture(char **texture, t_map *info_map);
void	get_color(char **texture, t_map *info_map);
void	get_textures_and_colors(char *line, t_map *info_map, int *n);

//error.c

void	invalid_map(int mode);

// check_map.c

int		check_line_map(char *line, int mode);
void	check_all_ones(char *line);
int		check_valid_neighbor(t_map *info_map, int y, int x);
void	check_map_limits(t_map *info_map, int y);
void	check_closed_map(t_map *info_map);

// map_size.c

void	get_width(char *line, t_map *info_map);
void	get_map_size(int fd, t_map *info_map);

#endif