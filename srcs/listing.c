/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:07:17 by frgotta           #+#    #+#             */
/*   Updated: 2018/04/30 16:09:32 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		*go_begin(t_arg *finfo)
{
	t_arg		*tmp;

	while (finfo && finfo->prev != NULL)
	{
		tmp = finfo;
		finfo = finfo->prev;
		finfo->next = tmp;
		tmp = NULL;
	}
	return (finfo);
}

t_arg		*ft_init_arg(void)
{
	t_arg	*list_arg;

	list_arg = (t_arg *)malloc(sizeof(t_arg));
	if (list_arg == NULL)
		return (NULL);
	list_arg->str = NULL;
	list_arg->next = NULL;
	list_arg->prev = NULL;
	return (list_arg);
}

t_arg		*ft_new_maillon(t_arg *test)
{
	t_arg	*tmp;

	tmp = test;
	test = test->next;
	test = (t_arg *)malloc(sizeof(t_arg));
	if (test == NULL)
		return (NULL);
	test->str = NULL;
	test->next = NULL;
	test->prev = tmp;
	return (test);
}

t_arg		*ft_list_arg(t_flags *flg, t_arg *parse_arg)
{
	//t_arg	*parse_arg;
	int		i;
	t_arg	*begin_lst;
//	t_arg	*tmp;

	i = 1;
	begin_lst = parse_arg;
/*	parse_arg->str = (char *)malloc(sizeof(char) * ft_strlen(flg->av[i]));
	if (parse_arg->str == NULL)
		return (NULL);*/
	// printf("[%s]\n", begin_lst->str);
	while (i < flg->ac)
	{
		parse_arg->str = ft_strdup(flg->av[i]);
		parse_arg = ft_new_maillon(parse_arg);
		i++;
	}
	return (parse_arg);
}

