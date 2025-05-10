/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:00:22 by fernando          #+#    #+#             */
/*   Updated: 2024/10/15 16:31:02 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		cnt;
	t_list	*res;
	t_list	*aux;

	if (!lst)
		return (0);
	cnt = ft_lstsize(lst);
	aux = 0;
	res = NULL;
	while (cnt > 0)
	{
		aux = ft_lstnew(NULL);
		if (!aux)
		{
			ft_lstclear(&aux, del);
			ft_lstclear(&res, del);
			return (0);
		}
		aux->content = f(lst->content);
		ft_lstadd_back(&res, aux);
		lst = lst->next;
		cnt--;
	}
	return (res);
}
