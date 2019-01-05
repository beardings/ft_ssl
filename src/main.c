/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:26:29 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/05 17:26:36 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		main(int argc, char **argv)
{
    t_ssl *ssl;

    ssl = init_struct();
    set_hashes();
    if (argc == 1)
        read_from_console(ssl);
    else
        argv = NULL;
    return (0);
}
