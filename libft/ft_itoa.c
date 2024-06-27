/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:54:16 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/23 22:52:26 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{	
		len++;
		return (len);
	}
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	ln;

	ln = n;
	i = ft_numlen(ln);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (ln == 0)
		str[0] = '0';
	if (ln < 0)
	{	
		str[0] = '-';
		ln = ln * -1;
	}
	while (ln > 0)
	{
		str[i] = (ln % 10) + '0';
		ln = ln / 10;
		i--;
	}
	return (str);
}
