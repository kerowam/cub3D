/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:33:55 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/01 21:23:32 by gfredes-         ###   ########.fr       */
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
	char	**map;
}	t_map;

// check_args.c

void	check_args(int argc, char **argv);

// init.c

t_map	init_map(void);

// free.c

void	free_split(char **split);

// map.c

void	get_texture(char **texture, t_map *info_map);
void	get_color(char **texture, t_map *info_map);
void	get_textures_and_colors(char *line, t_map *info_map, int *n);
void	get_map_info(char *file, t_map *info_map);

#endif