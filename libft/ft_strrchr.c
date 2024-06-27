/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:15:30 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/09 00:31:03 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *)&s[len_s]);
	while (len_s >= 0)
	{
		if (s[len_s] == (char) c)
			return ((char *)&s[len_s]);
		len_s--;
	}
	return (0);
}
