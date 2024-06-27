/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:40:15 by gfredes-          #+#    #+#             */
/*   Updated: 2024/06/27 00:55:20 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	index_i;
	size_t	index_f;

	index_i = 0;
	index_f = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (0);
	if (s1[index_i] == '\0' || index_f == 0)
		return (ft_strdup(""));
	while (s1[index_i] != '\0' && ft_strchr((char *)set, s1[index_i]))
		index_i++;
	while (ft_strchr((char *)set, s1[index_f]))
		index_f--;
	return (ft_substr(s1, index_i, (index_f - index_i + 1)));
}
