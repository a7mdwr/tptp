/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:06:08 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/28 19:16:29 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push *s)
{
	int	tmp;

	if (!s->stack_a || !s->stack_a->next)
		return ;
	tmp = s->stack_a->content;
	s->stack_a->content = s->stack_a->next->content;
	s->stack_a->next->content = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_push *s)
{
	int	tmp;

	if (!s->stack_b || !s->stack_b->next)
		return ;
	tmp = s->stack_b->content;
	s->stack_b->content = s->stack_b->next->content;
	s->stack_b->next->content = tmp;
	ft_putendl_fd("sb", 1);
}

void	ss(t_push *s)
{
	if (!s->stack_a || !s->stack_a->next || !s->stack_b || !s->stack_b->next)
		return ;
	silent_sa(s);
	silent_sb(s);
	ft_putendl_fd("ss", 1);
}
