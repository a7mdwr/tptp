/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:06:14 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 19:08:13 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra(t_push *s)
{
	t_list	*last;
	t_list	*second_last;

	if (!s->stack_a || !s->stack_a->next)
		return ;
	second_last = s->stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(&s->stack_a, last);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_push *s)
{
	t_list	*last;
	t_list	*second_last;

	if (!s->stack_b || !s->stack_b->next)
		return ;
	second_last = s->stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(&s->stack_b, last);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_push *s)
{
	if (!s->stack_a || !s->stack_a->next || !s->stack_b || !s->stack_b->next)
		return ;
	silent_rra(s);
	silent_rrb(s);
	ft_putendl_fd("rrr", 1);
}
