/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:26:51 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/11 22:14:08 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_lst;
	t_list	*new_lst;

	ret_lst = NULL;
	new_lst = NULL;
	while (lst != NULL)
	{
		if (f(lst->content) != NULL)
		{
			new_lst = (t_list *)malloc(sizeof(t_list));
			if (!new_lst)
				return (NULL);
			new_lst->content = f(lst->content);
			new_lst->next = NULL;
			ft_lstadd_back(&ret_lst, new_lst);
		}
		else
			del(lst->content);
		lst = lst->next;
	}
	return (ret_lst);
}
