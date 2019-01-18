//
// Created by Nikolas Ponomarov on 2019-01-16.
//

#include "../includes/ft_ssl.h"

static void	double_line(t_ssl *ssl)
{
    ft_memcpy(&ssl->input_int[0], &ssl->input_char[0], 64);
    sha512_wiki(ssl);
    ft_bzero(&ssl->input_int[0], 64);
    ft_bzero(&ssl->input_char[0], 64);
    swipe(&ssl->size);
    ft_memcpy(&ssl->input_char[0] + 56, (char *)&ssl->size, 8);
    ft_memcpy(&ssl->input_int[0], &ssl->input_char[0], 64);
    sha512_wiki(ssl);
}

static void	line(t_ssl *ssl)
{
    swipe(&ssl->size);
    ft_memcpy(&ssl->input_char[0] + 56, (char *)&ssl->size, 8);
    ft_memcpy(&ssl->input_int[0], &ssl->input_char[0], 64);
    sha512_wiki(ssl);
}

static void	last_step(t_ssl *ssl, int i, int n)
{
    ssl->size += i * 8;
    ssl->input_char[n] = 128;
    if (i < 56)
        line(ssl);
    else
        double_line(ssl);
    i = -1;
    while (++i < 8)
        sha512_hash[i] = reverse_bytes_long(sha512_hash[i], 8);
    print_sha512(ssl);
    ft_bzero(&ssl->input_char[0], 64);
    ft_bzero(&ssl->input_int[0], 64);
    ssl->size = 0;
}

void				fd_sha512(t_ssl *ssl)
{
    unsigned int	i;
    unsigned int	n;

    i = 0;
    n = 0;
    if (ssl->fd == 0)
    {
        read_again(ssl);
        return ;
    }
    while ((i = read(ssl->fd, &ssl->input_char[n], 64 - n)) > 63 || i > 0)
    {
        ssl->size += i * 8;
        n += i;
        if (n < 64)
            continue ;
        ft_memcpy(&ssl->input_int[0], &ssl->input_char[0], 64);
        sha512_wiki(ssl);
        ft_bzero(&ssl->input_char[0], 64);
        ft_bzero(&ssl->input_int[0], 64);
        n = 0;
    }
    last_step(ssl, i, n + i);
}

void				str_sha512(t_ssl *ssl)
{
    unsigned int	i;
    unsigned int	n;

    i = 1;
    n = 0;
    while (i > 0)
    {
        ft_strncpy((char *)&ssl->input_char[0], &ssl->str[n], 64);
        i = ft_strlen((char *)&ssl->input_char[0]);
        n += i;
        if (i < 64)
            break ;
        ssl->size += i * 8;
        ft_memcpy(&ssl->input_int[0], &ssl->input_char[0], 64);
        sha512_wiki(ssl);
        ft_bzero(&ssl->input_char[0], 64);
        ft_bzero(&ssl->input_int[0], 64);
    }
    last_step(ssl, i, i);
}