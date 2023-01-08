/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:29:18 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/08 17:25:00 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_up_down(t_list *stack, int num)
{
	t_list	*temp;
	size_t	i;

	i = 0;
	temp = stack;
	while (stack)
	{
		if (num == stack->content)
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

int	ft_get_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_max(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
void	best_move_lis(t_list **stack)
{
	if (ft_is_up_down(*stack, ft_get_min(*stack)))
		while (ft_get_min(*stack) != (*stack)->content)
			ft_rotate_abr(stack, NULL, 'a');
	else
		while (ft_get_min(*stack) != (*stack)->content)
			ft_reverse_rotate_abr(stack, NULL, 'a');
}
