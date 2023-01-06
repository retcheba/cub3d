/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:09:48 by retcheba          #+#    #+#             */
/*   Updated: 2022/06/23 20:37:15 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;

	result = NULL;
	if (!lst)
		return (result);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			del(tmp->content);
		else
			ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
