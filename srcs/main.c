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
    DIR                 *dir;
    struct dirent       *content;
    struct stat         s;
    struct passwd       *pw;
    struct group        *gr;
    //struct 
    // t_flags     flg;

    // ft_memset(&flg, 0, sizeof(t_flags));
    // flg.ac = argc;
    // flg.av = argv;
    // printf("%s\n", argv[1]);

    //CHECK IF FILE EXIST
    if (stat(argv[1], &s) != 0) {
		ft_putstr("ls :");
		ft_putstr(argv[1]);
		ft_putstr(": ");
		ft_putendl("No such file or directory");
		exit(-1);
    }


    //-------------------


    //OPEN DIR AND LIST CONTENT
    if ((dir = opendir(argv[1])) != NULL) 
    {
      /* print all the files and directories within directory */
      while ((content = readdir(dir)) != NULL) {
          if (ft_strcmp(content->d_name, ".") == 0 || ft_strcmp(content->d_name, "..") == 0)
            ft_putstr("");
         else
             ft_putendl(content->d_name);
       }
       closedir (dir);
     } 
     else 
     {
       ft_putendl("Can't open dir");
       return EXIT_FAILURE;
     }

    //-------------------



    //DISPLAY PROPERTIES OF FILES
    ft_putstr((S_ISDIR(s.st_mode)) ? "d" : "-");
    ft_putstr((s.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((s.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((s.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((s.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((s.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((s.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((s.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((s.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr((s.st_mode & S_IXOTH) ? "x" : "-");
    ft_putstr(" ");
    ft_putnbr((s.st_nlink));
    ft_putstr(" ");

    // DISPLAY UID
    if ((pw = getpwuid(s.st_uid)) != NULL)
        ft_putstr(pw->pw_name);
    else
        ft_putnbr(s.st_uid);
    ft_putstr(" ");


    //DISPLAY GROUPE
    if ((gr = getgrgid(s.st_gid)) != NULL)
        ft_putstr(gr->gr_name);
    else
        ft_putnbr(gr->gr_gid);


    int			ft_ls(t_flags *flg)
    {
        int i;
        t_arg	*parse_arg;
        t_arg	*begin_lst;
        //	t_arg	*debut;
            
        //	begin_lst = parse_arg;
        i = 1;
        if (flg->ac >= 2)
    	{
        	parse_arg = ft_init_arg();
    		begin_lst = ft_list_arg(flg, parse_arg);
            // printf("%s\n", parse_arg->next->str);
        }
    	begin_lst = go_begin(begin_lst);
            /*while (begin_lst->next)
            {
                printf("[%s]\n", begin_lst->str);
                begin_lst = begin_lst->next;
            }*/
            //printf("%s\n", begin_lst->str);
    	ft_checkflags(flg, begin_lst);
        return (0);
    }
	
	// ft_putstr(getgrgid(s.st_uid));
  //  printf("%d\n", flg->ac);
  //  printf("[%s]\n", "aa");
   // printf("%d\n", flg->ac);  
    // ft_ls(&flg);
