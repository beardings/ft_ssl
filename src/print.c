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

void        print_error_fd(char *file, t_ssl *ssl)
{
    if (ssl->comand == 1)
        ft_printf("md5: %s: No such file or directory!\n", file);
    else if (ssl->comand == 2)
        ft_printf("sha256: %s: No such file or directory!\n", file);
    else if (ssl->comand == 3)
        ft_printf("sha512: %s: No such file or directory!\n", file);
    else if (ssl->comand == 4)
        ft_printf("sha224: %s: No such file or directory!\n", file);
    else if (ssl->comand == 5)
        ft_printf("sha384: %s: No such file or directory!\n", file);
}

void        print_error_file(char *file, t_ssl *ssl)
{
    if (ssl->comand == 1)
        ft_printf("md5: %s: Can't read file or directory!\n", file);
    else if (ssl->comand == 2)
        ft_printf("sha256: %s: Can't read file or directory!\n", file);
    else if (ssl->comand == 3)
        ft_printf("sha512: %s: Can't read file or directory!\n", file);
    else if (ssl->comand == 4)
        ft_printf("sha224: %s: No such file or directory!\n", file);
    else if (ssl->comand == 5)
        ft_printf("sha384: %s: Can't read file or directory!\n", file);
}


void        print_option(char c, t_ssl *ssl)
{
    if (ssl->comand == 1)
        ft_printf("md5: illegal option -- %c\n", c);
    else if (ssl->comand == 2)
        ft_printf("sha256: illegal option -- %c\n", c);
    else if (ssl->comand == 3)
        ft_printf("sha512: illegal option -- %c\n", c);
    else if (ssl->comand == 4)
        ft_printf("sha224: illegal option -- %c\n", c);
    else if (ssl->comand == 5)
        ft_printf("sha384: illegal option -- %c\n", c);
    print_usage();
}

void        print_argument(t_ssl *ssl)
{
    if (ssl->comand == 1)
        ft_printf("md5: option requires an argument -- s\n");
    else if (ssl->comand == 2)
        ft_printf("sha256: option requires an argument -- s\n");
    else if (ssl->comand == 3)
        ft_printf("sha512: option requires an argument -- s\n");
    else if (ssl->comand == 4)
        ft_printf("sha224: option requires an argument -- s\n");
    else if (ssl->comand == 5)
        ft_printf("sha384: option requires an argument -- s\n");
    print_usage();
}

void print_by_fl(t_ssl *ssl, char *hash, char *comand)
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