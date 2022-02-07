/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:49:32 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/28 16:49:34 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_el;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst)
	{
		new_el = ft_lstnew(f(lst -> content));
		if (new_el == 0)
		{
			while (new_lst)
			{
				new_el = new_lst->next;
				(*del)(new_lst->content);
				free(new_lst);
				new_lst = new_el;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_el);
		lst = lst -> next;
	}
	return (new_lst);
}
/*
void    ft_allup(char   *str)
{
        unsigned int    i;

        i = 0;
        while (str[i + 1] != '\0')
                str[i++] = 'd';
}

void	del(void *ptr)
{
	free(ptr);
}
int main()
{
        char str[] = "hello";
        char str1[] = "there";
        t_list  *elem1;
        t_list  *elem2;
        t_list  *elem3;
        t_list  *elem4;

        elem1 = NULL;
        elem1 = ft_lstnew(str);
        elem2 = ft_lstnew(str1);
        elem1 -> next = elem2;
        elem3 = ft_lstnew(str);
        elem2 -> next = elem3;
        elem4 = ft_lstnew(str1);
        elem3 -> next = elem4;

        ft_lstmap(elem1, (void *)&ft_allup, &del);
        while (elem1)
        {
                printf("%s\n", elem1 -> content);
                elem1 = elem1 -> next;
        }
}*/
