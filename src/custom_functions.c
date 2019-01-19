/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:25:42 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/19 20:27:23 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

size_t					base_count(intmax_t n, short int base)
{
	size_t		c;

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

char					*i_base(uintmax_t n, short int base)
{
	int					c;
	char				*str;
	char				*bases;

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

void					swipe(unsigned long int *size)
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

char					*base_long(unsigned long n, int base)
{
	char				buf[65];
	char				*ret;
	int					i;
	int					j;

	ft_bzero(buf, 65);
	j = 0;
	*buf = n == 0 ? 48 : 0;
	while (n > 0)
	{
		buf[j++] = (n % base < 10 ? n % base : n % base + 39) + 48;
		n /= base;
	}
	i = ft_strlen(buf);
	j = i;
	if ((ret = malloc(sizeof(char) * (i + 1))))
	{
		ft_bzero(ret, i + 1);
		while (i--)
			ret[j - i - 1] = buf[i];
	}
	return (ret);
}
