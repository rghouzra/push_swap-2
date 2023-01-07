/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:07:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 19:02:10 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move_lis(t_list **stack)
{
	if (ft_is_up_down(*stack))
		while (ft_get_min(*stack) != (*stack)->content)
			ft_rotate_abr(stack, NULL, 'a');
	else
		while (ft_get_min(*stack) != (*stack)->content)
			ft_reverse_rotate_abr(stack, NULL, 'a');
}

void	ft_push_to_b(t_list **stack_a, t_list **stack_b, int *a)
{
	size_t	i;
	size_t	j;
	size_t	size;
	t_list	*temp;

	temp = *stack_a;
	j = -1;
	size = ft_lstsize(*stack_a);
	while (++j < size)
	{
		i = -1;
		while (++i < ft_lstsize(temp))
			if (temp->content == a[i])
				temp->found = 1;
		temp = temp->next;
	}
	j = -1;
	while (++j < size)
	{
		if ((*stack_a)->found == 1)
			ft_rotate_abr(stack_a, stack_b, 'a');
		else
			ft_push_ab(stack_a, stack_b, 'b');
	}
}
