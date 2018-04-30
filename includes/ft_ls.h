/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgotta <frgotta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:19:15 by frgotta           #+#    #+#             */
/*   Updated: 2018/04/30 16:22:48 by frgotta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define __DARWIN_NULL

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include "../libft/libft.h"

void	ft_putstr(char const *str);
//void	ft_putendl(char const *s);

/*typedef	struct	s_stats
{

}				t_stats;*/

/*typedef	struct		s_info
{
	
	char 	*path;
	char 	*uid;
	char	chmd[10];
	
}					t_info;*/

typedef	struct		s_arg
{
	char 			*str;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct		s_flags
{
	int		ac;
	char	**av;
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
	char	*name;
}					t_flags;

/*typedef struct		s_info
{
	
}*/

int			ft_ls(t_flags *flg);
void		ft_checkflags(t_flags *flg, t_arg *begin_lst);
t_arg		*ft_list_arg(t_flags *flg, t_arg *parse_arg);
t_flags		*init_flags(void);
int			ft_check_opt(char *str);
int			ft_if_match(t_flags *flg, char *str);
int			ft_if_exist(char *str, t_flags *flg);
//t_list	*ft_lstnew(const void *content, size_t content_size);

#endif
