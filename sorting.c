/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:26:47 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/08 16:21:40 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_rev(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) - 2)
	{
		ft_reverse_rotate_abr(stack_a, stack_b, 'a');
		ft_push_ab(stack_a, stack_b, 'b');
	}
	ft_swap_abs(stack_a, stack_b, 'a');
	while (ft_lstsize(*stack_b))
		ft_push_ab(stack_a, stack_b, 'a');
}

void	ft_sort_three(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content)
		ft_rotate_abr(stack_a, NULL, 'a');
	else if ((*stack_a)->next->content > (*stack_a)->content && \
			(*stack_a)->next->content > (*stack_a)->next->next->content)
		ft_reverse_rotate_abr(stack_a, NULL, 'a');
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap_abs(stack_a, NULL, 'a');
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) != 3)
	{
		if (ft_is_up_down(*stack_a, ft_get_min(*stack_a)))
		{
			while (ft_get_min(*stack_a) != (*stack_a)->content)
				ft_rotate_abr(stack_a, stack_b, 'a');
			ft_push_ab(stack_a, stack_b, 'b');
		}
		else
		{
			while (ft_get_min(*stack_a) != (*stack_a)->content)
				ft_reverse_rotate_abr(stack_a, stack_b, 'a');
			ft_push_ab(stack_a, stack_b, 'b');
		}
	}
	ft_sort_three(stack_a);
	if (ft_lstsize(*stack_b) == 2)
		ft_push_ab(stack_a, stack_b, 'a');
	ft_push_ab(stack_a, stack_b, 'a');
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int		*a;

	a = ft_get_content(stack_a);
	ft_push_to_b(stack_a, stack_b, a);
	ft_best_move_to_push_a(stack_a, stack_b);

}

