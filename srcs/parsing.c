/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:21:17 by frgotta           #+#    #+#             */
/*   Updated: 2018/04/13 11:42:33 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_if_exist(char *str, t_flags *flg)
{
	DIR		*doc;
	struct stat *s;

	//stat(str, s);
	doc = opendir(str);
/*	if (doc == NULL)
	{
		ft_putstr("ls :");
		ft_putstr(str);
		ft_putstr(": ");
		perror("");
		exit(-1);
	}*/
	if (/*!S_ISREG(s->st_mode) || */doc == NULL)
	{
		ft_putstr("ls :");
		ft_putstr(str);
		ft_putstr(": ");
		perror("");
		exit(-1);
	}
	else
	{
		flg->name = strdup(str);
		ft_putendl(flg->name);
	}
	closedir(doc);
	return (0);
}
int		ft_if_match(t_flags *flg, char *str)
{
	int		i;
	i = 1;

	while (str[i])
	{
		if (str[i] == 'a' && flg->a != 1)
			flg->a = 1;
		else if (str[i] == 'l' && flg->l != 1)
			flg->l = 1;
		else if (str[i] == 'r' && flg->r != 1)
			flg->r = 1;
		else if (str[i] == 't' && flg->t != 1)
			flg->t = 1;
		else if (str[i] == 'R' && flg->R != 1)
			flg->R = 1;
		i++;
	}
	return (0);
}


int			ft_check_opt(char *str)
{
    int		i;

	i = 0;
	char *str1;

	if (str[i] != '-')
		return(-1);
	while (str[++i])
	{
		if (str[i] != 'a' && str[i] != 'l' && str[i] != 'r' && str[i] != 't' && str[i] != 'R')
		{
			ft_putstr("ft_ls : illegal option -- ");
			ft_putchar(str[i]);
			ft_putendl("\nusage: ft_ls [-Ralrt] [file ...]");
			exit(-1);
		}
	}
	return (0);
}

void		ft_checkflags(t_flags *flg, t_arg *begin_lst)
{   
	while (begin_lst->next)
    {
		//printf("%s\n", begin_lst->str);
		if (begin_lst->str[0] == '-' && begin_lst->str[1] != '-')
		{
			ft_check_opt(begin_lst->str);
			ft_if_match(flg, begin_lst->str);
        	//begin_lst = begin_lst->next;
		}
		else if (begin_lst->str[0] == '-' && begin_lst->str[1] == '-')
		{
			begin_lst = begin_lst->next;
			//printf("%s\n", begin_lst->str);
			ft_if_exist(begin_lst->str, flg);
		}
		else
			ft_if_exist(begin_lst->str, flg);
		begin_lst = begin_lst->next;
	}
	//printf("[%s]\n", begin_lst->next-> str);
}
