/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:05:55 by aradwan           #+#    #+#             */
/*   Updated: 2025/03/27 15:05:55 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

static char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = ' ';
	str[i + 1] = '\0';
	return (free(s1), str);
}

int	same_number(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->content == tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	initialize_and_check(t_push *s)
{
	t_list	*tmp;

	initialize_list(s);
	free_2d(s->array);
	lst_id(&s->stack_a);
	tmp = lst_dup(s->stack_a);
	sort_list(tmp, cmp);
	if (same_number(tmp))
	{
		free_list(tmp);
		free_list(s->stack_a);
		return (0);
	}
	free_list(tmp);
	return (1);
}

int	chaek(int ac, char **av, t_push *s)
{
	int		j;
	char	*str;

	j = 2;
	str = NULL;
	str = ft_strjoin(av[1], " ");
	while (j < ac)
	{
		str = ft_strjoin1(str, av[j]);
		j++;
	}
	s->array = ft_split(str, ' ');
	free(str);
	j = 0;
	while (s->array[j])
	{
		if (!helper(s->array[j]))
			return (free_2d(s->array), 0);
		j++;
	}
	if (!initialize_and_check(s))
		return (0);
	return (1);
}
