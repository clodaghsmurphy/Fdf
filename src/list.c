/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:03:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/24 14:56:09 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_my_lstadd_back(t_tab **alst, t_tab *new)
{
	t_tab	*last;

	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last ->next != NULL)
		last = last ->next;
	last ->next = new;
}

t_tab	*ft_my_lstnew(char **tab)
{
	t_tab	*new_node;

	new_node = (t_tab *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node ->tab = tab;
	new_node ->next = NULL;
	return (new_node);
}

int	ft_my_lstsize(t_tab *lst)
{
	unsigned int	i;

	i = 1;
	if (lst == 0)
		return (0);
	while (lst ->next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

void	ft_my_lstclear(t_tab **lst)
{
	t_tab	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = temp ->next;
		free_char_tab((*lst)->tab);
		free(*lst);
		*lst = temp;
	}
}
