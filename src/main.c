

#include "../includes/ft_ssl.h"

int		main(int argc, char **argv)
{
    t_ssl_md5 *ssl_md5;

    ssl_md5 = init_struct();
    set_hashes();
    if (argc == 1)
        read_from_console(ssl_md5);
    else
        argv = NULL;
    return (0);
}