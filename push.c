/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:06:20 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 19:09:27 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	pa(t_push *s)
{
	t_list	*tmp_b;

	if (!s->stack_b)
		return ;
	tmp_b = s->stack_b;
	s->stack_b = s->stack_b->next;
	tmp_b->next = NULL;
	ft_lstadd_front(&s->stack_a, tmp_b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_push *s)
{
	t_list	*tmp_a;

	if (!s->stack_a)
		return ;
	tmp_a = s->stack_a;
	s->stack_a = s->stack_a->next;
	ft_lstadd_front(&s->stack_b, tmp_a);
	ft_putendl_fd("pb", 1);
}

void	ra(t_push *s)
{
	t_list	*first_nod;

	if (!s->stack_a || !s->stack_a->next)
		return ;
	first_nod = s->stack_a;
	s->stack_a = s->stack_a->next;
	first_nod->next = NULL;
	ft_lstadd_back(&s->stack_a, first_nod);
	ft_putendl_fd("ra", 1);
}

void	rb(t_push *s)
{
	t_list	*first_nod;

	if (!s->stack_a || !s->stack_a->next || !s->stack_b || !s->stack_b->next)
		return ;
	first_nod = s->stack_b;
	s->stack_b = s->stack_b->next;
	first_nod->next = NULL;
	ft_lstadd_back(&s->stack_b, first_nod);
	ft_putendl_fd("rb", 1);
}

void	rr(t_push *s)
{
	if (!s->stack_b || !s->stack_a)
		return ;
	silent_ra(s);
	silent_rb(s);
	ft_putendl_fd("rr", 1);
}
