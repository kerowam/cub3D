/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:58:10 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/08 02:23:22 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *sorc, size_t len)
{
	char	*dst;
	char	*src;

	dst = (char *) dest;
	src = (char *) sorc;
	if (!dest && !sorc)
		return (0);
	if (dest > sorc)
	{
		while (len-- > 0)
		{	
			dst[len] = src[len];
		}
	}
	else
	{
		ft_memcpy(dest, sorc, len);
	}
	return (dest);
}
