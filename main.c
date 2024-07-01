/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:56:13 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/01 04:10:16 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_info(t_map *info_map)
{
	printf("North texture: %s\n", info_map->north_texture_path);
	printf("South texture: %s\n", info_map->south_texture_path);
	printf("East texture: %s\n", info_map->east_texture_path);
	printf("West texture: %s\n", info_map->west_texture_path);
	printf("Floor: %d, %d, %d\n", info_map->floor[0], info_map->floor[1], info_map->floor[2]);
	printf("Ceiling: %d, %d, %d\n", info_map->ceiling[0], info_map->ceiling[1], info_map->ceiling[2]);
}

int	main(int argc, char **argv)
{
	t_map	info_map;

	check_args(argc, argv);
	info_map = init_map();
	get_map_info(argv[1], &info_map);
	print_map_info(&info_map);
}
