/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:06:47 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 15:16:25 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	sort_three_numbers(t_push *s)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstsize(s->stack_a) != 3 || !sorted_check(s->stack_a))
		return ;
	a = s->stack_a->id;
	b = s->stack_a->next->id;
	c = s->stack_a->next->next->id;
	if (a == 2 && b == 0 && c == 1)
		ra(s);
	else if (a == 1 && b == 0 && c == 2)
		sa(s);
	else if (a == 1 && b == 2 && c == 0)
		rra(s);
	else if (a == 0 && b == 2 && c == 1)
	{
		sa(s);
		ra(s);
	}
	else if (a == 2 && b == 1 && c == 0)
	{
		sa(s);
		rra(s);
	}
}

void	sort_five_numbers(t_push *lst)
{
	while (ft_lstsize(lst->stack_a) > 3)
	{
		if (lst->stack_a->id == 0 || lst->stack_a->id == 1)
			pb(lst);
		else if (ft_lstlast(lst->stack_a)->id == 0 || ft_lstlast(lst->stack_a)->id == 1)
			rra(lst);
		else
			ra(lst);
	}
	sort_three_numbers(lst);
	if (lst->stack_b->id < lst->stack_b->next->id)
		sb(lst);
	pa(lst);
	pa(lst);
}

// void	sorting2_helper(t_push *s, int i)
// {
// 	while (i)
// 	{
// 		if (s->stack_a->id % 2 == 1)
// 		{
// 			s->stack_a->id /= 2;
// 			ra(s);
// 		}
// 		else if (s->stack_a->id % 2 == 0)
// 		{
// 			s->stack_a->id /= 2;
// 			pb(s);
// 		}
// 		i--;
// 	}
// }

void	sorting2(t_push *s)
{
	int	i;

	while (sorted_check(s->stack_a))
	{
		i = ft_lstsize(s->stack_a);
		while (i)
		{
			if (s->stack_a->id % 2 == 1)
			{
				s->stack_a->id /= 2;
				ra(s);
			}
			else if (s->stack_a->id % 2 == 0)
			{
				s->stack_a->id /= 2;
				pb(s);
			}
			i--;
		}
		if (s->stack_b)
		{
			while (s->stack_b)
				pa(s);
		}
	}
}
