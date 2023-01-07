/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:29:18 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 02:39:49 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_up_down(t_list *stack)
{
	t_list	*temp;
	size_t	i;

	i = 0;
	temp = stack;
	while (stack)
	{
		if (ft_get_min(temp) == stack->content)
		{
			if (i <= ft_lstsize(temp) / 2)
				return (1);
		}
		stack = stack->next;
		i++;
	}
	return (0);
}

int	ft_is_sort(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_sort_rev(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int ft_get_min(t_list *stack)
{
	int min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
