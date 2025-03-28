/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:05:45 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 17:13:45 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	lst_id(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = *lst;
	while (tmp)
	{
		i = 0;
		tmp2 = *lst;
		while (tmp2)
		{
			if (tmp2->content < tmp->content)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->id = i;
		tmp = tmp->next;
	}
}

void	free_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	cmp(int a, int b)
{
	return (a - b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*tmp;
	int		sorted;

	sorted = 0;
	if (!lst)
		return (NULL);
	while (!sorted)
	{
		sorted = 1;
		tmp = lst;
		while (tmp && tmp->next)
		{
			if ((*cmp)(tmp->content, tmp->next->content) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = swap;
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}
