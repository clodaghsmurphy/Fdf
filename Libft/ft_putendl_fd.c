/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:02:42 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/26 12:02:43 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int     main()
{
        int     fd;

        fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if (fd == -1)
                printf("open error");
        ft_putendl_fd("hello", fd);
}*/
