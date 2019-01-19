/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:53:53 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:54:59 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void	double_line(t_ssl *ssl)
{
	ft_memcpy(&ssl->input_long[0], &ssl->input_char_l[0], 128);
	sha512_wiki(ssl);
	ft_bzero(&ssl->input_long[0], 128);
	ft_bzero(&ssl->input_char_l[0], 128);
	swipe(&ssl->size);
	ft_memcpy(&ssl->input_char_l[0] + 120, (char *)&ssl->size, 8);
	ft_memcpy(&ssl->input_long[0], &ssl->input_char_l[0], 128);
	sha512_wiki(ssl);
}

static void	line(t_ssl *ssl)
{
	swipe(&ssl->size);
	ft_memcpy(&ssl->input_char_l[0] + 120, (char *)&ssl->size, 8);
	ft_memcpy(&ssl->input_long[0], &ssl->input_char_l[0], 128);
	sha512_wiki(ssl);
}

static void	last_step(t_ssl *ssl, int i, int n)
{
	ssl->size += i * 8;
	ssl->input_char_l[n] = 128;
	if (i < 120)
		line(ssl);
	else
		double_line(ssl);
	i = -1;
	while (++i < 8)
		g_sha512_hash[i] = reverse_bl(g_sha512_hash[i], 8);
	print_sha512(ssl);
	ft_bzero(&ssl->input_char_l[0], 128);
	ft_bzero(&ssl->input_long[0], 128);
	ssl->size = 0;
}

void		fd_sha512(t_ssl *ssl)
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
	while ((i = read(ssl->fd, &ssl->input_char_l[n], 128 - n)) > 127 || i > 0)
	{
		ssl->size += i * 8;
		n += i;
		if (n < 128)
			continue ;
		ft_memcpy(&ssl->input_long[0], &ssl->input_char_l[0], 128);
		sha512_wiki(ssl);
		ft_bzero(&ssl->input_char_l[0], 128);
		ft_bzero(&ssl->input_long[0], 128);
		n = 0;
	}
	last_step(ssl, i, n + i);
}

void		str_sha512(t_ssl *ssl)
{
	unsigned int	i;
	unsigned int	n;

	i = 1;
	n = 0;
	while (i > 0)
	{
		ft_strncpy((char *)&ssl->input_char_l[0], &ssl->str[n], 128);
		i = ft_strlen((char *)&ssl->input_char_l[0]);
		n += i;
		if (i < 128)
			break ;
		ssl->size += i * 8;
		ft_memcpy(&ssl->input_long[0], &ssl->input_char_l[0], 128);
		sha512_wiki(ssl);
		ft_bzero(&ssl->input_char_l[0], 128);
		ft_bzero(&ssl->input_long[0], 128);
	}
	last_step(ssl, i, i);
}
