/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:24:48 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:24:13 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		parsing_flags(t_ssl *ssl, char **str, int *i)
{
	if (!str || !str[(*i)])
		return ;
	while (str[*i] && str[++(*i)])
	{
		if (str[*i][0] == '-' && str[*i][1])
			check_flags(ssl, str, i);
		else if (str[*i][0] == '-' && !str[*i][1])
			ssl->usage_f = 1;
		else
			check_file(ssl, str[*i]);
		set_hashes();
	}
	(!ssl->data_f && !ssl->usage_f) ? use_comand(ssl, 0) : 0;
}

void		use_comand(t_ssl *ssl, char str)
{
	int		i;

	i = 0;
	ssl->data_f = 1;
	while (i < COMANDS)
	{
		if (ssl->comand == i + 1)
		{
			if (!str)
				ssl_func[i * 2](ssl);
			else
				ssl_func[(i * 2) + 1](ssl);
			return ;
		}
		i++;
	}
}

void		check_line(t_ssl *ssl)
{
	char	**str;
	int		i;

	str = ft_strsplit(ssl->line, ' ');
	i = 0;
	if (str && str[0])
		check_comand(ssl, str[0]);
	if (ssl->comand && str && str[1])
		parsing_flags(ssl, &str[0], &i);
	else if (ssl->comand)
		use_comand(ssl, 0);
	else
		while (str[++i])
			;
	if (str && str[0])
		while (i > -1)
			free(str[i--]);
	str ? free(str) : 0;
	ssl->line ? free(ssl->line) : 0;
	ft_bzero(ssl, sizeof(t_ssl));
}

void		read_from_console(t_ssl *ssl)
{
	ft_printf("OpenSSL> ");
	while (get_next_line(0, &ssl->line))
	{
		check_line(ssl);
		set_hashes();
		ft_printf("OpenSSL> ");
	}
}

void		read_from_argv(t_ssl *ssl, char **argv)
{
	int		i;

	i = 1;
	if (argv && argv[1])
		check_comand(ssl, argv[1]);
	if (ssl->comand && argv && argv[2])
		parsing_flags(ssl, argv, &i);
	else if (ssl->comand)
		use_comand(ssl, 0);
}
