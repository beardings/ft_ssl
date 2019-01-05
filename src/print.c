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
    ft_printf("usage: ft_ssl command [command opts] [command args]");
    exit(0);
}
