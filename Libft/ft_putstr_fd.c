/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:03:09 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/26 12:03:11 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
int     main()
{
        int     fd;

        fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if (fd == -1)
                printf("open error");
        ft_putstr_fd("hello", fd);
}*/
