/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 04:04:14 by gfredes-          #+#    #+#             */
/*   Updated: 2024/07/01 23:16:10 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	init_map(void)
{
	t_map	info_map;
	int		i;

	info_map.north_texture_path = NULL;
	info_map.south_texture_path = NULL;
	info_map.east_texture_path = NULL;
	info_map.west_texture_path = NULL;
	i = 0;
	while (i < 3)
	{
		info_map.floor[i] = -1;
		info_map.ceiling[i] = -1;
		i++;
	}
	info_map.map_width = 0;
	info_map.map_height = 0;
	info_map.map = NULL;
	info_map.map_status = 0;
	info_map.player = 0;
	return (info_map);
}