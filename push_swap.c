/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:22:53 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/06 23:32:46 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *stack_a;
	temp1 = *stack_b;

	if (ft_lstsize(*stack_a) == 1 || ft_is_sort(*stack_a))
		return ;

	if (ft_lstsize(*stack_a) == 2)
		return(ft_swap_abs(stack_a, stack_b, 'a'));

	if (ft_lstsize(*stack_a) == 3)
		return(ft_sort_three(stack_a, stack_b));

	if (ft_lstsize(*stack_a) <= 5)
		return(ft_sort_five(stack_a, stack_b));

	if (ft_is_sort_rev(*stack_a))
		return (ft_sort_rev(stack_a, stack_b));

	// return(ft_sort(stack_a, stack_b));
}
