/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:26:29 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:38:44 by mponomar         ###   ########.fr       */
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
}

void		check_comand(t_ssl *ssl, char *str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (i < COMANDS)
	{
		if (!strcmp(str, comands[i]))
		{
			ssl->comand = i + 1;
			return ;
		}
		i++;
	}
	if (!ssl->comand)
		print_error(str);
}

int			main(int argc, char **argv)
{
	t_ssl	*ssl;

	ssl = init_struct();
	set_hashes();
	if (argc == 1)
		read_from_console(ssl);
	else
		read_from_argv(ssl, argv);
	return (0);
}
