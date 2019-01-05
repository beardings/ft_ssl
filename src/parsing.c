/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:27:12 by mponomar          #+#    #+#             */
/*   Updated: 2019/01/05 17:27:17 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	s_flag(t_ssl *ssl, char **str, int *i)
{
    int j;

    j = -1;
    while (str[*i][++j] != 's')
        ;
    if (!str[*i][++j])
        (str[++(*i)]) ? ssl->str = ft_strdup(str[*i]) : 0;
    else
        ssl->str = ft_strdup(&str[*i][j]);
    if (!str[*i])
    {
        ft_printf("md5 -s");
        ssl->usage_f = 1;
    }
    else
        use_comand(ssl, 1);
    (ssl->str) ? free(ssl->str) : 0;
}

void	p_flag(t_ssl *ssl)
{
    if (ssl->flags & P_FLAG)
    {
        ssl->str = ft_strdup("");
        use_comand(ssl, 1);
        free(ssl->str);
    }
    else
    {
        use_comand(ssl, 0);
        ssl->flags+= P_FLAG;
    }
}

void				check_flags(t_ssl *ssl, char **str, int *i)
{
    int		j;

    j = 0;
    while (str[(*i)][++j])
    {
        if (str[(*i)][j] == 'r' && !(ssl->flags & P_FLAG))
            ssl->flags += R_FLAG;
        else if (str[(*i)][j] == 'q' && !(ssl->flags & P_FLAG))
            ssl->flags += Q_FLAG;
        else if (str[(*i)][j] == 'p')
            p_flag(ssl);
        else if (str[(*i)][j] == 's')
        {
            s_flag(ssl, str, i);
            return ;
        }
        else if (str[(*i)][j] != 's' && str[(*i)][j] != 'p'
                 && str[(*i)][j] != 'r' && str[(*i)][j] != 'q')
        {
            ft_printf("ft_ssl: Error: '%s' is an invalid command!", str[(*i)][j]);
            ssl->usage_f = 1;
            return ;
        }
        set_hashes();
    }
}

void	check_file(t_ssl *ssl, char *file)
{
    char	buf[1];

    ssl->fd = open(file, O_RDONLY);
    ssl->data_f = 1;
    if (ssl->fd < 0)
        ft_printf("Error: Can't open file!\n");
    else
    {
        if (read(ssl->fd, &buf[0], 0) < 0)
            ft_printf("Error: {yellow}Can't read file!\n");
        else
            use_comand(ssl, 0);
        close(ssl->fd);
    }
}

void		check_comand(t_ssl *ssl, char *str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (i < COMANDS) {
        if (!strcmp(str, comands[i]))
        {
            ssl->comand = i + 1;
            return ;
        }
        i++;
    }
    if (!ssl->comand)
        print_error(str);
}
