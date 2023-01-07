/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_sequence.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:18:23 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 03:53:55 by bel-idri         ###   ########.fr       */
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

int ft_get_max(int *arr)
{
	int i;
	int max;

	i = 0;
	max = arr[0];
	while (arr[i])
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	best_move_lis(t_list **stack)
{
	if (ft_is_up_down(*stack))
		while (ft_get_min(*stack) != (*stack)->content)
			ft_rotate_abr(stack, NULL, 'a');
	else
		while (ft_get_min(*stack) != (*stack)->content)
			ft_reverse_rotate_abr(stack, NULL, 'a');
}

int	*ft_get_lis(t_list **stack)
{
	int *lis;
	int *index_lis;
	int *arr;
	size_t i;
	size_t j;

	best_move_lis(stack);
	arr = ft_lst_to_arr(*stack);
	lis = malloc(sizeof(int) * ft_lstsize(*stack));
	index_lis = malloc(sizeof(int) * ft_lstsize(*stack));
	i = -1;
	while (++i < ft_lstsize(*stack))
	{
		lis[i] = 1;
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

int	*ft_get_content(t_list *stack)
{
	int *arr;
	int	*index_lis;
	int	*content;
	size_t i;


	content = malloc(sizeof(int) * ft_lstsize(stack));
	index_lis = ft_get_lis(&stack);
	arr = ft_lst_to_arr(stack);
	content[0] = arr[ft_get_max(index_lis)];
	i = 0;
	// while (i < ft_lstsize(stack) - 1)
	// {
	// 	content[i + 1] = arr[index_lis[i]];
	// 	i++;
	// }
	return (free(arr), free(index_lis), content);
}
