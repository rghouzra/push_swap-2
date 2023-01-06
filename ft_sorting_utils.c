/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:29:18 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/06 23:30:28 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_up_down(t_list *stack, size_t i)
{
	t_list *temp;

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
