//
// Created by Nikolas Ponomarov on 2019-01-17.
//

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
        rev = reverse_bytes(md5_hash[i], 4);
        hex = i_base(rev, 16);
        ft_memcpy(&tmp[i * 8], hex, 8);
        free(hex);
        i++;
    }
    tmp[32] = '\0';
    print_by_flags(ssl, &tmp[0], "MD5");
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
        rev = reverse_bytes(sha256_hash[i], 4);
        hex = i_base(rev, 16);
        ft_memcpy(&tmp[i * 8], hex, 8);
        free(hex);
        i++;
    }
    tmp[64] = '\0';
    print_by_flags(ssl, &tmp[0], "SHA256");
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
        rev = reverse_bytes(sha224_hash[i], 4);
        hex = i_base(rev, 16);
        ft_memcpy(&tmp[i * 8], hex, 8);
        free(hex);
        i++;
    }
    tmp[56] = '\0';
    print_by_flags(ssl, &tmp[0], "SHA224");
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
        rev = reverse_bytes_long(sha512_hash[i], 8);
        hex = i_base(rev, 16);
        ft_memcpy(&tmp[i * 16], hex, 16);
        free(hex);
        i++;
    }
    tmp[128] = '\0';
    print_by_flags(ssl, &tmp[0], "SHA512");
}