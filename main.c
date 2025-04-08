/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:06:34 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/27 15:06:34 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parser(char **av)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i] == ' ')
			i++;
		if (av[j][i] == '\0')
			return (0);
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		n;
	t_push	s;

	if (!parser(av))
		return (write(2, "Error\n", 6), 0);
	ft_bzero(&s, sizeof(s));
	n = chaek(ac, av, &s);
	if (n == 0)
		return (write(2, "Error\n", 6), 0);
	if (ft_lstsize(s.stack_a) == 3)
		sort_three_numbers(&s);
	else if (ft_lstsize(s.stack_a) == 5 || ft_lstsize(s.stack_a) == 4)
		sort_five_numbers(&s);
	if (ft_lstsize(s.stack_a) > 5)
		sorting2(&s);
	free_list(s.stack_a);
}
