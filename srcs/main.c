/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:25:29 by frgotta           #+#    #+#             */
/*   Updated: 2018/04/12 18:14:38 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*t_flags         *init_flags(void)
{
    t_flags     *flg;

    flg = (t_flags*)malloc(sizeof(t_flags));
    if (flg == NULL)
        return (NULL);
    flg->a = 0;
    flg->l = 0;
    flg->r = 0;
    flg->R = 0;
    flg->t = 0;
    flg->ac = 0;
    flg->av = NULL;
    return (flg);
}*/

int		main(int argc, char **argv)
{
    t_flags     flg;

    ft_memset(&flg, 0, sizeof(t_flags));
    flg.ac = argc;
    flg.av = argv;
  //  printf("%d\n", flg->ac);
  //  printf("[%s]\n", "aa");
   // printf("%d\n", flg->ac);  
    ft_ls(&flg);
}
