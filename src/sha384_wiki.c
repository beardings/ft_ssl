/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384_wiki.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:52:57 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:53:24 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

#define R(x, k) ((x >> k) | (x << (64 - k)))
#define CC(x, y, z) ((x & y) ^ ((~x) & z))
#define M(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define BG0(x) (R(x, 28) ^ R(x, 34) ^ R(x, 39))
#define BG1(x) (R(x, 14) ^ R(x, 18) ^ R(x, 41))
#define SG0(x) (R(x, 1) ^ R(x, 8) ^ (x >> 7))
#define SG1(x) (R(x, 19) ^ R(x, 61) ^ (x >> 6))

static void	third_st(unsigned long *sha384)
{
	int				i;
	unsigned long	st1;
	unsigned long	st2;

	i = 0;
	while (i < 80)
	{
		st1 = sha384_hash[7] + BG1(sha384_hash[4]) +
			CC(sha384_hash[4], sha384_hash[5], sha384_hash[6])
			+ sha384_table[i] + sha384[i];
		st2 = BG0(sha384_hash[0]) +
			M(sha384_hash[0], sha384_hash[1], sha384_hash[2]);
		sha384_hash[7] = sha384_hash[6];
		sha384_hash[6] = sha384_hash[5];
		sha384_hash[5] = sha384_hash[4];
		sha384_hash[4] = sha384_hash[3] + st1;
		sha384_hash[3] = sha384_hash[2];
		sha384_hash[2] = sha384_hash[1];
		sha384_hash[1] = sha384_hash[0];
		sha384_hash[0] = st1 + st2;
		i++;
	}
}

static void	secont_st(unsigned long *sha384)
{
	unsigned long	copy[8];
	int				i;

	i = 0;
	while (i < 8)
	{
		copy[i] = sha384_hash[i];
		i++;
	}
	third_st(sha384);
	i = 0;
	while (i < 8)
	{
		sha384_hash[i] = copy[i] + sha384_hash[i];
		i++;
	}
}

static void	first_st(t_ssl *ssl, unsigned long *sha384)
{
	int i;

	i = -1;
	while (++i < 16)
		sha384[i] = reverse_bl(ssl->input_long[i], 8);
	while (i < 80)
	{
		sha384[i] = SG1(sha384[i - 2]) + sha384[i - 7] +
			SG0(sha384[i - 15]) + sha384[i - 16];
		++i;
	}
}

void		sha384_wiki(t_ssl *ssl)
{
	unsigned long sha384[80];

	ft_bzero(&sha384[0], 80);
	first_st(ssl, &sha384[0]);
	secont_st(&sha384[0]);
}
