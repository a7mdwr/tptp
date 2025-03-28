/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:08:00 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 19:16:37 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

t_list	*lst_dup(t_list *lst)
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(lst->content);
		if (!new_node)
		{
			free_list(new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

void	initialize_list(t_push *s)
{
	int		i;
	t_list	*new;

	i = 0;
	while (s->array[i])
	{
		new = ft_lstnew((int)ft_atoi(s->array[i]));
		ft_lstadd_back(&s->stack_a, new);
		i++;
	}
}

int	helper(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	sorted_check(t_list *lst)
{
	t_list	*tmp;

	if (!lst || !lst->next)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	silent_sb(t_push *s)
{
	int	tmp;

	if (!s->stack_b || !s->stack_b->next)
		return ;
	tmp = s->stack_b->content;
	s->stack_b->content = s->stack_b->next->content;
	s->stack_b->next->content = tmp;
}
