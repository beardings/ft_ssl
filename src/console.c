//
// Created by Mykola Ponomarov on 03.01.2019.
//

#include "../includes/ft_ssl.h"

void	use_comand(t_ssl_md5 *ssl_md5, char str)
{
    int 	i;

    i = 0;
    ssl_md5->data_f = 1;
    while (i < COMANDS) {
        if (ssl_md5->comand == i)
        {
            if (!str)
                md5_func[i - 1](ssl_md5);
            else
                md5_func[i](ssl_md5);
        }
        i++;
    }
}

void	check_line(t_ssl_md5 *ssl_md5)
{
    char 	**str;
    int		i;

    str = ft_strsplit(ssl_md5->line, ' ');
    i = 0;
    if (str && str[0])
        check_comand(ssl_md5, str[0]);
    if (ssl_md5->comand && str && str[1])
        parsing_argv(ssl_md5, &str[0], &i);
    else if (ssl_md5->comand)
        use_comand(ssl_md5, 0);
    else
        while (str[++i])
            ;
    if (str && str[0])
        while (i > -1)
            free(str[i--]);
    str ?  free(str) : 0;
    ssl_md5->line ? free(ssl_md5->line) : 0;
    ft_bzero(ssl_md5, sizeof(t_ssl_md5));
}

void read_from_console(t_ssl_md5 *ssl_md5)
{
    ft_printf("OpenSSL> ");
    while (get_next_line(0, &ssl_md5->line))
    {
        check_line(ssl_md5);
        set_hashes();
        ft_printf("OpenSSL> ");
    }
}