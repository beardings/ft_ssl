//
// Created by Mykola Ponomarov on 03.01.2019.
//

#include "../includes/ft_ssl.h"

void				parsing_argv(t_ssl_md5 *ssl_md5, char **argv, int *i)
{
    if (!argv || !argv[(*i)])
        return ;
    while (argv[*i] && argv[++(*i)])
    {
        if (argv[*i][0] == '-')
            check_flags(md5, argv, i);
        else
            check_file(md5, argv[*i]);
        update_hashes();
    }
    (!md5->flag_data && !md5->flag_usage) ? dispatcher_cmd(md5, 0) : 0;
}

void		check_comand(t_ssl_md5 *ssl_md5, char *str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (i < COMANDS) {
        if (!strcmp(str, comands[i]))
        {
            ssl_md5->comand = i + 1;
            return ;
        }
        i++;
    }
    if (!ssl_md5->comand)
        print_error(str);
}

//static inline void	check_file(t_md5 *md5, char *file)
//{
//    char	buf[1];
//
//    md5->fd = open(file, O_RDONLY);
//    md5->flag_data = 1;
//    if (md5->fd < 0)
//        ft_printf("{red}Error: {yellow}Can't open file!{eoc}\n");
//    else
//    {
//        if (read(md5->fd, &buf[0], 0) < 0)
//            ft_printf("{red}Error: {yellow}Can't read file!{eoc}\n");
//        else
//            dispatcher_cmd(md5, 0);
//        close(md5->fd);
//    }
//}
