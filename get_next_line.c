/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haniakhater <haniakhater@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:50:26 by haniakhater       #+#    #+#             */
/*   Updated: 2022/02/02 18:32:46 by haniakhater      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    buff;
    char    line[7000000];
    int     b;
    int     i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    i = 0;
    b = read(fd, &buff, 1);
    while (b > 0)
    {
        line[i++] = buff;
        if (buff == '\n')
            break;
        b = read(fd, &buff, 1);
    }
    line[i] = '\0';
    if (b <= 0 && i == 0)
        return (NULL);
    return (ft_strdup(line));
}