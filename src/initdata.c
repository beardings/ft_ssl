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
}

t_ssl *init_struct(void)
{
    t_ssl *ssl;

    ssl = malloc(sizeof(t_ssl));
    ft_bzero(ssl, sizeof(t_ssl));
    return ssl;
}
