/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:27:12 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:37:47 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	s_flag(t_ssl *ssl, char **str, int *i)
{
	int	j;

	j = -1;
	while (str[*i][++j] != 's')
		;
	if (!str[*i][++j])
		(str[++(*i)]) ? ssl->str = ft_strdup(str[*i]) : 0;
	else
		ssl->str = ft_strdup(&str[*i][j]);
	if (!str[*i])
	{
		print_argument(ssl);
		ssl->usage_f = 1;
	}
	else
	{
		if (ssl->flags != Q_FLAG)
			ssl->flags = S_FLAG;
		use_comand(ssl, 1);
	}
	(ssl->str) ? free(ssl->str) : 0;
}

void	p_flag(t_ssl *ssl)
{
	ssl->str = ft_strdup("");
	if (ssl->flags == P_FLAG)
		use_comand(ssl, 1);
	else
	{
		ssl->flags = P_FLAG;
		use_comand(ssl, 0);
		if (ssl->flags == Q_FLAG || ssl->flags == R_FLAG)
		{
			free(ssl->str);
			set_hashes();
			ssl->str = ft_strdup("");
			use_comand(ssl, 1);
		}
	}
	(ssl->str) ? free(ssl->str) : 0;
}

void	flag_q_r(t_ssl *ssl, char flag)
{
	if (flag == 'r')
		ssl->flags = R_FLAG;
	else
		ssl->flags = Q_FLAG;
	if (ssl->flags == P_FLAG)
		p_flag(ssl);
}

void	check_flags(t_ssl *ssl, char **str, int *i)
{
	int		j;

	j = 0;
	while (str[(*i)][++j])
	{
		if ((str[(*i)][j] == 'r' && !(ssl->flags == R_FLAG))
				|| (str[(*i)][j] == 'q' && !(ssl->flags == Q_FLAG)))
			flag_q_r(ssl, str[(*i)][j]);
		else if (str[(*i)][j] == 'p')
			p_flag(ssl);
		else if (str[(*i)][j] == 's')
		{
			s_flag(ssl, str, i);
			return ;
		}
		else if (str[(*i)][j] != 's' && str[(*i)][j] != 'p'
				&& str[(*i)][j] != 'r' && str[(*i)][j] != 'q')
		{
			print_option(str[(*i)][j], ssl);
			ssl->usage_f = 1;
			return ;
		}
		set_hashes();
	}
}

void	check_file(t_ssl *ssl, char *file)
{
	char	buf[1];

	ssl->fd = open(file, O_RDONLY);
	ssl->data_f = 1;
	if (ssl->fd < 0)
		print_error_fd(file, ssl);
	else
	{
		if (read(ssl->fd, &buf[0], 0) < 0)
			print_error_file(file, ssl);
		else
		{
			ssl->str = ft_strdup(file);
			use_comand(ssl, 0);
			free(ssl->str);
		}
		close(ssl->fd);
	}
}
