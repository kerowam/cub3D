/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:54:23 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/08 01:13:19 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *sorc, size_t len)
{
	char	*dst;
	char	*src;
	size_t	count;

	count = 0;
	dst = (char *) dest;
	src = (char *) sorc;
	if (!dest && !sorc)
		return (0);
	while (count < len)
	{
		dst[count] = src[count];
		count++;
	}
	return (dest);
}
