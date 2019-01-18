/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:25:48 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/05 17:25:57 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void    init_bonus_sha(void)
{
    sha512_hash[0] = 0x6a09e667f3bcc908;
    sha512_hash[1] = 0xbb67ae8584caa73b;
    sha512_hash[2] = 0x3c6ef372fe94f82b;
    sha512_hash[3] = 0xa54ff53a5f1d36f1;
    sha512_hash[4] = 0x510e527fade682d1;
    sha512_hash[5] = 0x9b05688c2b3e6c1f;
    sha512_hash[6] = 0x1f83d9abfb41bd6b;
    sha512_hash[7] = 0x5be0cd19137e2179;
    sha224_hash[0] = 0xC1059ED8;
    sha224_hash[1] = 0x367CD507;
    sha224_hash[2] = 0x3070DD17;
    sha224_hash[3] = 0xF70E5939;
    sha224_hash[4] = 0xFFC00B31;
    sha224_hash[5] = 0x68581511;
    sha224_hash[6] = 0x64F98FA7;
    sha224_hash[7] = 0xBEFA4FA4;
}

void	set_hashes(void)
{
    md5_hash[0] = 0x67452301;
    md5_hash[1] = 0xEFCDAB89;
    md5_hash[2] = 0x98BADCFE;
    md5_hash[3] = 0x10325476;
    sha256_hash[0] = 0x6A09E667;
    sha256_hash[1] = 0xBB67AE85;
    sha256_hash[2] = 0x3C6EF372;
    sha256_hash[3] = 0xA54FF53A;
    sha256_hash[4] = 0x510E527F;
    sha256_hash[5] = 0x9B05688C;
    sha256_hash[6] = 0x1F83D9AB;
    sha256_hash[7] = 0x5BE0CD19;
    init_bonus_sha();
}

t_ssl *init_struct(void)
{
    t_ssl *ssl;

    ssl = malloc(sizeof(t_ssl));
    ft_bzero(ssl, sizeof(t_ssl));
    return ssl;
}
