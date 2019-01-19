//
// Created by Mykola Ponomarov on 2019-01-19.
//

#include "../includes/ft_ssl.h"

static void	double_line(t_ssl *ssl)
{
    ft_memcpy(&ssl->input_long[0], &ssl->input_char_long[0], 128);
    sha384_wiki(ssl);
    ft_bzero(&ssl->input_long[0], 128);
    ft_bzero(&ssl->input_char_long[0], 128);
    swipe(&ssl->size);
    ft_memcpy(&ssl->input_char_long[0] + 120, (char *)&ssl->size, 8);
    ft_memcpy(&ssl->input_long[0], &ssl->input_char_long[0], 128);
    sha384_wiki(ssl);
}

static void	line(t_ssl *ssl)
{
    swipe(&ssl->size);
    ft_memcpy(&ssl->input_char_long[0] + 120, (char *)&ssl->size, 8);
    ft_memcpy(&ssl->input_long[0], &ssl->input_char_long[0], 128);
    sha384_wiki(ssl);
}

static void	last_step(t_ssl *ssl, int i, int n)
{
    ssl->size += i * 8;
    ssl->input_char_long[n] = 128;
    if (i < 120)
        line(ssl);
    else
        double_line(ssl);
    i = -1;
    while (++i < 8)
        sha384_hash[i] = reverse_bl(sha384_hash[i], 8);
    print_sha384(ssl);
    ft_bzero(&ssl->input_char_long[0], 128);
    ft_bzero(&ssl->input_long[0], 128);
    ssl->size = 0;
}

void				fd_sha384(t_ssl *ssl)
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
    while ((i = read(ssl->fd, &ssl->input_char_long[n], 128 - n)) > 127 || i > 0)
    {
        ssl->size += i * 8;
        n += i;
        if (n < 128)
            continue ;
        ft_memcpy(&ssl->input_long[0], &ssl->input_char_long[0], 128);
        sha384_wiki(ssl);
        ft_bzero(&ssl->input_char_long[0], 128);
        ft_bzero(&ssl->input_long[0], 128);
        n = 0;
    }
    last_step(ssl, i, n + i);
}

void				str_sha384(t_ssl *ssl)
{
    unsigned int	i;
    unsigned int	n;

    i = 1;
    n = 0;
    while (i > 0)
    {
        ft_strncpy((char *)&ssl->input_char_long[0], &ssl->str[n], 128);
        i = ft_strlen((char *)&ssl->input_char_long[0]);
        n += i;
        if (i < 128)
            break ;
        ssl->size += i * 8;
        ft_memcpy(&ssl->input_long[0], &ssl->input_char_long[0], 128);
        sha384_wiki(ssl);
        ft_bzero(&ssl->input_char_long[0], 128);
        ft_bzero(&ssl->input_long[0], 128);
    }
    last_step(ssl, i, i);
}