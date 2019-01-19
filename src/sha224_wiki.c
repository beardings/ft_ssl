/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_wiki.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:44:47 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:46:31 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

#define R(x, k) ((x >> k) | (x << (32 - k)))
#define CC(x, y, z) ((x & y) ^ ((~x) & z))
#define M(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define BG0(x) (R(x, 2) ^ R(x, 13) ^ R(x, 22))
#define BG1(x) (R(x, 6) ^ R(x, 11) ^ R(x, 25))
#define SG0(x) (R(x, 7) ^ R(x, 18) ^ (x >> 3))
#define SG1(x) (R(x, 17) ^ R(x, 19) ^ (x >> 10))

static void	third_st(unsigned int *sha224)
{
	int				i;
	unsigned int	st1;
	unsigned int	st2;

	i = 0;
	while (i < 64)
	{
		st1 = g_sha224_hash[7] + BG1(g_sha224_hash[4]) +
			CC(g_sha224_hash[4], g_sha224_hash[5], g_sha224_hash[6])
			+ g_sha224_table[i] + sha224[i];
		st2 = BG0(g_sha224_hash[0]) +
			M(g_sha224_hash[0], g_sha224_hash[1], g_sha224_hash[2]);
		g_sha224_hash[7] = g_sha224_hash[6];
		g_sha224_hash[6] = g_sha224_hash[5];
		g_sha224_hash[5] = g_sha224_hash[4];
		g_sha224_hash[4] = g_sha224_hash[3] + st1;
		g_sha224_hash[3] = g_sha224_hash[2];
		g_sha224_hash[2] = g_sha224_hash[1];
		g_sha224_hash[1] = g_sha224_hash[0];
		g_sha224_hash[0] = st1 + st2;
		i++;
	}
}

static void	secont_st(unsigned int *sha224)
{
	unsigned int	copy[8];
	int				i;

	i = 0;
	while (i < 8)
	{
		copy[i] = g_sha224_hash[i];
		i++;
	}
	third_st(sha224);
	i = 0;
	while (i < 8)
	{
		g_sha224_hash[i] = copy[i] + g_sha224_hash[i];
		i++;
	}
}

static void	first_st(t_ssl *ssl, unsigned int *sha224)
{
	int				i;

	i = -1;
	while (++i < 16)
		sha224[i] = reverse_b(ssl->input_int[i], 4);
	while (i < 64)
	{
		sha224[i] = SG1(sha224[i - 2]) + sha224[i - 7] +
			SG0(sha224[i - 15]) + sha224[i - 16];
		++i;
	}
}

void		sha224_wiki(t_ssl *ssl)
{
	unsigned int	sha224[64];

	ft_bzero(&sha224[0], 64);
	first_st(ssl, &sha224[0]);
	secont_st(&sha224[0]);
}
