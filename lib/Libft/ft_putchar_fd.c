/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:58:34 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/26 11:58:39 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main()
{
	int	fd;

	fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		printf("open error");
	ft_putchar_fd('Z', fd);
}*/
