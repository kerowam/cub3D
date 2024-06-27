/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:27:55 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/08 22:15:02 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *sorc, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (sorc[i] != '\0' && i < size - 1)
		{
			dest[i] = sorc[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(sorc));
}
