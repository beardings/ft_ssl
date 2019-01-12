/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:27:23 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/05 17:27:28 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		print_error(char *str)
{
    ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", str);
    ft_printf("Standard commands:\n\n");
    ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
    ft_printf("Cipher commands:\n");
    exit(0);
}

void		print_usage(void)
{
    ft_printf("usage: ft_ssl command [command opts] [command args]\n");
    exit(0);
}

void print_by_flags(t_ssl *ssl, char *hash, char *comand)
{
    if (!ssl->flags)
        ft_printf("%s\n", hash);
    else if (ssl->flags == P_FLAG)
        ft_printf("%s%s\n", ssl->str, hash);
    else if (ssl->flags == R_FLAG)
        ft_printf("%s\n", hash);
    else if (ssl->flags == Q_FLAG)
        ft_printf("%s\n", hash);
    else if (ssl->flags == S_FLAG)
        ft_printf("%s (\"%s\") = %s\n", comand, ssl->str, hash);
}


void	print_md5(t_ssl *ssl)
{
    char			tmp[33];
    char			*hex;
    int				i;
    unsigned int	rev;

    i = 0;
    while (i < 4)
    {
        rev = reverse_bytes(md5_hash[i], 4);
        hex = i_base(rev, 16);
        ft_memcpy(&tmp[i * 8], hex, 8);
        free(hex);
        i++;
    }
    tmp[32] = '\0';
    print_by_flags(ssl, &tmp[0], "MD5");
}