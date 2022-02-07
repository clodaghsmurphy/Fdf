/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:49:10 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/30 11:14:19 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f((char *)lst -> content);
		lst = lst -> next;
	}
}

/*
void	ft_allup(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i + 1] != '\0')
		str[i++] = 'd';
}
int main()
{
	char str[] = "hello";
	char str1[] = "there";
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	
	elem1 = NULL;
	elem1 = ft_lstnew(str);
	elem2 = ft_lstnew(str1);
	elem1 -> next = elem2;
	elem3 = ft_lstnew(str);
	elem2 -> next = elem3;
	elem4 = ft_lstnew(str1);
	elem3 -> next = elem4;
	
	ft_lstiter(elem1, (void *)&ft_allup);
	while (elem1)
	{
		printf("%s\n", elem1 -> content);
		elem1 = elem1 -> next;
	}
}*/
