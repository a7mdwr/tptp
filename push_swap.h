/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:58:41 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/27 16:58:41 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_push
{
	char	**array;
	t_list	*stack_a;
	int		size;
	t_list	*stack_b;
	t_list	*sort;
}	t_push;

void	free_2d(char **str);
int		chaek(int ac, char **av, t_push *s);
void	free_list(t_list *lst);
void	free_2d(char **str);
void	lst_id(t_list **lst);
t_list	*sort_list(t_list *lst, int (*cmp)(int, int));
t_list	*lst_dup(t_list *lst);
int		cmp(int a, int b);
void	initialize_list(t_push *s);
void	sort_five_numbers(t_push *s);
int		helper(char *s);
void	push_smallest(t_push *s);
void	sorting2(t_push *s);
void	sorting2_helper(t_push *s, int i);
void	sort_three_numbers(t_push *s);
int		sorted_check(t_list *lst);
void	silent_rra(t_push *s);
void	silent_rrb(t_push *s);
void	silent_rb(t_push *s);
void	silent_ra(t_push *s);
void	silent_sa(t_push *s);
void	silent_sb(t_push *s);
void	sa(t_push *s);
void	sb(t_push *s);
void	ss(t_push *s);
void	pb(t_push *s);
void	pa(t_push *s);
void	ra(t_push *s);
void	rb(t_push *s);
void	rr(t_push *s);
void	rrr(t_push *s);
void	rrb(t_push *s);
void	rra(t_push *s);
#endif
