/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:11:52 by gfredes-          #+#    #+#             */
/*   Updated: 2022/12/30 21:11:08 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapedlst;
	t_list	*newlst;

	mapedlst = 0;
	while (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		if (!newlst)
		{	
			ft_lstclear(&mapedlst, del);
			return (0);
		}
		else
			ft_lstadd_back(&mapedlst, newlst);
		lst = lst->next;
	}
	return (mapedlst);
}
