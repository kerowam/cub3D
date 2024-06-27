/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:31:53 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/29 19:59:35 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextlst;

	if (*lst)
	{
		while (*lst)
		{
			nextlst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nextlst;
		}
	}	
	*lst = NULL;
}
