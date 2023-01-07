/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:07:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 16:32:18 by bel-idri         ###   ########.fr       */
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
