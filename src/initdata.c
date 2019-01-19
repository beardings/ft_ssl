/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:25:48 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:29:26 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	init_bonus_sha(void)
{
	g_sha512_hash[0] = 0x6a09e667f3bcc908;
	g_sha512_hash[1] = 0xbb67ae8584caa73b;
	g_sha512_hash[2] = 0x3c6ef372fe94f82b;
	g_sha512_hash[3] = 0xa54ff53a5f1d36f1;
	g_sha512_hash[4] = 0x510e527fade682d1;
	g_sha512_hash[5] = 0x9b05688c2b3e6c1f;
	g_sha512_hash[6] = 0x1f83d9abfb41bd6b;
	g_sha512_hash[7] = 0x5be0cd19137e2179;
	g_sha224_hash[0] = 0xC1059ED8;
	g_sha224_hash[1] = 0x367CD507;
	g_sha224_hash[2] = 0x3070DD17;
	g_sha224_hash[3] = 0xF70E5939;
	g_sha224_hash[4] = 0xFFC00B31;
	g_sha224_hash[5] = 0x68581511;
	g_sha224_hash[6] = 0x64F98FA7;
	g_sha224_hash[7] = 0xBEFA4FA4;
	g_sha384_hash[0] = 0xcbbb9d5dc1059ed8;
	g_sha384_hash[1] = 0x629a292a367cd507;
	g_sha384_hash[2] = 0x9159015a3070dd17;
	g_sha384_hash[3] = 0x152fecd8f70e5939;
	g_sha384_hash[4] = 0x67332667ffc00b31;
	g_sha384_hash[5] = 0x8eb44a8768581511;
	g_sha384_hash[6] = 0xdb0c2e0d64f98fa7;
	g_sha384_hash[7] = 0x47b5481dbefa4fa4;
}

void	set_hashes(void)
{
	g_md5_hash[0] = 0x67452301;
	g_md5_hash[1] = 0xEFCDAB89;
	g_md5_hash[2] = 0x98BADCFE;
	g_md5_hash[3] = 0x10325476;
	g_sha256_hash[0] = 0x6A09E667;
	g_sha256_hash[1] = 0xBB67AE85;
	g_sha256_hash[2] = 0x3C6EF372;
	g_sha256_hash[3] = 0xA54FF53A;
	g_sha256_hash[4] = 0x510E527F;
	g_sha256_hash[5] = 0x9B05688C;
	g_sha256_hash[6] = 0x1F83D9AB;
	g_sha256_hash[7] = 0x5BE0CD19;
	init_bonus_sha();
}

t_ssl	*init_struct(void)
{
	t_ssl *ssl;

	ssl = malloc(sizeof(t_ssl));
	ft_bzero(ssl, sizeof(t_ssl));
	return (ssl);
}
