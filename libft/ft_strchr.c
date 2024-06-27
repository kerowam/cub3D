/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:54:58 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/09 00:13:43 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	count;

	count = 0;
	if ((char) c == '\0')
	{	
		while (s[count] != '\0')
			count++;
		return ((char *)&s[count]);
	}
	while (s[count] != '\0')
	{
		if (s[count] == (char) c)
		{
			return ((char *)&s[count]);
		}
		count++;
	}
	return (0);
}
