/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:32:19 by frgotta           #+#    #+#             */
/*   Updated: 2018/05/22 14:32:21 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"



int		ft_manage_info(char *str, t_flags *flg)
{
	struct stat *s;

	if (stat(str, s) != 0)
	{
		write(2, "ls :", 4);
        write(2, str, ft_strlen(str));
        write(2, ": ", 2);
        perror("");
		exit(-1);
    }
    else
        ft_get_info(str, flg);
	return (0);
}