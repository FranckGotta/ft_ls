/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:21:16 by frgotta           #+#    #+#             */
/*   Updated: 2017/11/10 13:34:41 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*link;
	t_list		*new_list;
	t_list		*tmp_f;

	tmp_f = f(lst);
	link = ft_lstnew(tmp_f->content, tmp_f->content_size);
	if (link == NULL)
		return (NULL);
	new_list = link;
	while (lst->next != NULL)
	{
		tmp_f = f(lst->next);
		if (!(link->next = ft_lstnew(tmp_f->content, tmp_f->content_size)))
			return (NULL);
		link = link->next;
		lst = lst->next;
	}
	return (new_list);
}
