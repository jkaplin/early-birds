/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:11 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/20 10:52:15 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*new_elem;
	t_list	*ptr_fresh;
	t_list	*tmp;

	begin_lst = NULL;
	if (lst)
	{
		ptr_fresh = f(lst);
		begin_lst = ft_lstnew(ptr_fresh->content, ptr_fresh->content_size);
		new_elem = begin_lst;
		lst = lst->next;
	}
	while(lst)
	{
		ptr_fresh = f(lst);
		tmp = ft_lstnew(ptr_fresh->content, ptr_fresh->content_size);
		if (tmp)
		{
			new_elem->next = tmp;
			new_elem = tmp;
		}
		lst = lst->next;
	}
	return (begin_lst);
}
