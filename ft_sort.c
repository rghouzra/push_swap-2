/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:07:40 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 03:01:42 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lst_to_arr(t_list *stack)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * ft_lstsize(stack));
	i = 0;
	while (stack)
	{
		arr[i++] = stack->content;
		stack = stack->next;
	}
	return (arr);
}

int ft_get_max_lis(int *lis, t_list *stack)
{
	int max;
	size_t i;

	max = lis[0];
	i = 0;
	while (++i < ft_lstsize(stack))
		if (lis[i] > max)
			max = lis[i];
	return (max);
}

int *ft_get_lis(t_list **stack)
{
	int *lis;
	int *index_lis;
	int *arr;
	size_t i;
	size_t j;

	if (ft_is_up_down(*stack))
		while (ft_get_min(*stack) != (*stack)->content)
			ft_rotate_abr(stack, NULL, 'a');
	else
		while (ft_get_min(*stack) != (*stack)->content)
			ft_reverse_rotate_abr(stack, NULL, 'a');

	arr = ft_lst_to_arr(*stack);
	lis = malloc(sizeof(int) * ft_lstsize(*stack));
	index_lis = malloc(sizeof(int) * ft_lstsize(*stack));
	i = -1;
	while (++i < ft_lstsize(*stack))
	{
		lis[i] = 1;
		index_lis[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				index_lis[i] = j;
				lis[i] = lis[j] + 1;
			}
		}
	}
	return (free(arr), free(lis), index_lis);
}


