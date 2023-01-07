/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:07:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/07 21:14:37 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*ft_best_move_to_push_a(t_list **stack_a, t_list **stack_b)
{
	int	**steps_a;
	int	**steps_b;
	size_t	i;
	size_t	j;
	t_list	*temp;
	t_list	*temp1;

	temp = *stack_a;
	temp1 = *stack_b;
	steps_a = (int **)malloc(sizeof(int *) * ft_lstsize(*stack_b));
	steps_b = (int **)malloc(sizeof(int *) * ft_lstsize(*stack_b));
	i = -1;
	while (++i < ft_lstsize(*stack_b))
	{
		steps_a[i] = (int *)malloc(sizeof(int) * 2);
		steps_b[i] = (int *)malloc(sizeof(int) * 2);
	}
	i = -1;
	while (++i < ft_lstsize(*stack_b))
	{
		if (ft_is_up_down(temp1))
			steps_a[i][0] = ft_up_steps(*stack_b, temp1->content);
		else
			steps_a[i][0] = ft_down_steps(*stack_b, temp1->content);
	}
}

int	ft_up_steps(t_list *stack, int content)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		if (stack->content == content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	ft_down_steps(t_list *stack, int content)
{
	size_t	i;

	while (stack)
	{
		if (stack->content == content)
			i = 0;
		stack = stack->next;
		i++;
	}
	return (i + 1);
}

void	ft_push_to_a(t_list **stack_a, t_list **stack_b)
{

}

void	ft_rotate_a_b(t_list **stack_a, t_list **stack_b)
{

}
