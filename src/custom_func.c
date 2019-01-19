/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:24:41 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:25:23 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void				read_again(t_ssl *ssl)
{
	int				i;
	char			buf[64];
	char			*tmp;

	i = 0;
	if (!ssl->str)
		ssl->str = ft_memalloc(1);
	while ((i = read(0, &buf, 64)))
	{
		tmp = ssl->str;
		buf[i] = '\0';
		ssl->str = ft_strjoin(ssl->str, buf);
		free(tmp);
	}
	g_ssl_func[((int)ssl->comand * 2) - 1](ssl);
}

unsigned int		reverse_b(const unsigned int x, const char bytes)
{
	unsigned int	reversed;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)&x;
	n2 = (unsigned char *)&reversed;
	if (bytes == 2)
	{
		n2[0] = n1[1];
		n2[1] = n1[0];
	}
	else
	{
		n2[0] = n1[3];
		n2[1] = n1[2];
		n2[2] = n1[1];
		n2[3] = n1[0];
	}
	return ((bytes == 1) ? x : reversed);
}

unsigned long		reverse_bl(const unsigned long x, const char bytes)
{
	unsigned long	reversed;
	unsigned char	*n1;
	unsigned char	*n2;

	n1 = (unsigned char *)&x;
	n2 = (unsigned char *)&reversed;
	n2[0] = n1[7];
	n2[1] = n1[6];
	n2[2] = n1[5];
	n2[3] = n1[4];
	n2[4] = n1[3];
	n2[5] = n1[2];
	n2[6] = n1[1];
	n2[7] = n1[0];
	return ((bytes == 1) ? x : reversed);
}
