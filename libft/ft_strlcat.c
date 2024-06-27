/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:01 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/08 23:02:40 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *sorc, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	i = 0;
	j = 0;
	len_dest = ft_strlen(dest);
	if (size > 0 && len_dest < size - 1)
	{
		while (dest[i] != 0)
			i++;
		while (sorc[j] != 0 && j + i < size - 1)
		{
			dest[i + j] = sorc[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	if (len_dest >= size)
		len_dest = size;
	return (len_dest + ft_strlen(sorc));
}
