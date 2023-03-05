/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:14:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/05 16:34:05 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmphead;
	t_list	*tmp;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	tmphead = lst;
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			return (ft_lstclear(&head, del), NULL);
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}