/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:42:00 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:42:35 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_md5(t_ssl *ssl)
{
	char			tmp[33];
	char			*hex;
	int				i;
	unsigned int	rev;

	i = 0;
	while (i < 4)
	{
		rev = reverse_b(g_md5_hash[i], 4);
		hex = i_base(rev, 16);
		ft_memcpy(&tmp[i * 8], hex, 8);
		free(hex);
		i++;
	}
	tmp[32] = '\0';
	print_by_fl(ssl, &tmp[0], "MD5");
}

void	print_sha256(t_ssl *ssl)
{
	char			tmp[65];
	char			*hex;
	int				i;
	unsigned int	rev;

	i = 0;
	while (i < 8)
	{
		rev = reverse_b(g_sha256_hash[i], 4);
		hex = i_base(rev, 16);
		ft_memcpy(&tmp[i * 8], hex, 8);
		free(hex);
		i++;
	}
	tmp[64] = '\0';
	print_by_fl(ssl, &tmp[0], "SHA256");
}

void	print_sha224(t_ssl *ssl)
{
	char			tmp[57];
	char			*hex;
	int				i;
	unsigned int	rev;

	i = 0;
	while (i < 7)
	{
		rev = reverse_b(g_sha224_hash[i], 4);
		hex = i_base(rev, 16);
		ft_memcpy(&tmp[i * 8], hex, 8);
		free(hex);
		i++;
	}
	tmp[56] = '\0';
	print_by_fl(ssl, &tmp[0], "SHA224");
}

void	print_sha512(t_ssl *ssl)
{
	char			tmp[129];
	char			*hex;
	int				i;
	unsigned long	rev;

	i = 0;
	while (i < 8)
	{
		rev = reverse_bl(g_sha512_hash[i], 8);
		hex = base_long(rev, 16);
		ft_memcpy(&tmp[i * 16], hex, 16);
		free(hex);
		i++;
	}
	tmp[128] = '\0';
	print_by_fl(ssl, &tmp[0], "SHA512");
}

void	print_sha384(t_ssl *ssl)
{
	char			tmp[97];
	char			*hex;
	int				i;
	unsigned long	rev;

	i = 0;
	while (i < 6)
	{
		rev = reverse_bl(g_sha384_table[i], 8);
		hex = base_long(rev, 16);
		ft_memcpy(&tmp[i * 16], hex, 16);
		free(hex);
		i++;
	}
	tmp[96] = '\0';
	print_by_fl(ssl, &tmp[0], "SHA384");
}
