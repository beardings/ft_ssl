//
// Created by Mykola Ponomarov on 2019-01-12.
//

#include "../includes/ft_ssl.h"

void				read_again(t_ssl *ssl)
{
    int i;
    char buf[64];
    char *tmp;

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
    ssl_func[((int)ssl->comand * 2) - 1](ssl);
}

unsigned int		reverse_bytes(const unsigned int x, const char bytes)
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

size_t			base_count(intmax_t n, short int base)
{
    size_t c;

    if (n >= 0)
        c = 1;
    else if (n < 0)
        c = 2;
    while (n != 0)
    {
        n = n / base;
        c++;
    }
    if (base == 16 && c > 8)
        c--;
    return ((int)c);
}

char			*i_base(uintmax_t n, short int base)
{
    int 	c;
    char	*str;
    char	*bases;

    bases = "0123456789abcdef";
    c = base_count(n, base);
    str = (char *)malloc(sizeof(char) * c);
    if (str == NULL)
        return (NULL);
    ft_bzero(str, c);
    str[c] = '\0';
    while (c >= 0)
    {
        str[--c] = bases[n % base];
        n /= base;
    }
    return (str);
}

void		swipe(unsigned long int *size)
{
    unsigned long int	reversed;
    unsigned char		*n1;
    unsigned char		*n2;

    reversed = *size;
    n1 = (unsigned char *)size;
    n2 = (unsigned char *)&reversed;
    n2[0] = n1[7];
    n2[1] = n1[6];
    n2[2] = n1[5];
    n2[3] = n1[4];
    n2[4] = n1[3];
    n2[5] = n1[2];
    n2[6] = n1[1];
    n2[7] = n1[0];
    *size = reversed;
}