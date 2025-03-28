/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:06:35 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 19:15:28 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_rra(t_push *s)
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
}

void	silent_rrb(t_push *s)
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
}

void	silent_rb(t_push *s)
{
	t_list	*first_nod;

	if (!s->stack_a || !s->stack_a->next || !s->stack_b || !s->stack_b->next)
		return ;
	first_nod = s->stack_b;
	s->stack_b = s->stack_b->next;
	first_nod->next = NULL;
	ft_lstadd_back(&s->stack_b, first_nod);
}

void	silent_ra(t_push *s)
{
	t_list	*first_nod;

	if (!s->stack_a || !s->stack_a->next)
		return ;
	first_nod = s->stack_a;
	s->stack_a = s->stack_a->next;
	first_nod->next = NULL;
	ft_lstadd_back(&s->stack_a, first_nod);
}

void	silent_sa(t_push *s)
{
	int	tmp;

	if (!s->stack_a || !s->stack_a->next)
		return ;
	tmp = s->stack_a->content;
	s->stack_a->content = s->stack_a->next->content;
	s->stack_a->next->content = tmp;
}
