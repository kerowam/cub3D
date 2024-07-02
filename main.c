/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:56:13 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/02 01:27:56 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_info(t_map *info_map)
{
	int	y;

	y = 0;
	printf("North texture: %s\n", info_map->north_texture_path);
	printf("South texture: %s\n", info_map->south_texture_path);
	printf("East texture: %s\n", info_map->east_texture_path);
	printf("West texture: %s\n", info_map->west_texture_path);
	printf("Floor: %d, %d, %d\n", info_map->floor[0], info_map->floor[1], info_map->floor[2]);
	printf("Ceiling: %d, %d, %d\n", info_map->ceiling[0], info_map->ceiling[1], info_map->ceiling[2]);
	printf("Map_width: %d\n", info_map->map_width);
	printf("Map_heigth: %d\n", info_map->map_height);
	printf("Map_status: %d\n", info_map->map_status);
	printf("Player_view: %c\n", info_map->player_view);
	printf("Map:\n");
	while (info_map->map[y])
	{
		/*size_t	len;

		len = ft_strlen(info_map->map[y]);
		printf("len line %d: %ld\n", y, len);*/
		printf("%s\n", info_map->map[y]);
		y++;

	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_map	info_map;

	check_args(argc, argv);
	info_map = init_map();
	get_map_info(argv[1], &info_map);
	print_map_info(&info_map);
}
