/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:07:55 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/09 03:30:20 by bel-idri         ###   ########.fr       */
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

int	**ft_malloc_steps(t_list *stack_b)
{
	size_t	i;
	int		**steps;

	i = -1;
	steps = (int **)malloc(sizeof(int *) * ft_lstsize(stack_b));
	while (++i < ft_lstsize(stack_b))
		steps[i] = (int *)malloc(sizeof(int) * 3);
	return (steps);
}

void	ft_free_steps(int **steps, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		free(steps[i]);
	free(steps);
}

void	ft_steps_b(t_list *stack_b, int **steps)
{
	size_t	i;
	t_list	*temp;

	temp = stack_b;
	i = -1;
	while (++i < ft_lstsize(stack_b))
	{
		if (ft_is_up_down(stack_b,  temp->content))
			steps[i][0] = ft_up_steps(stack_b, temp->content);
		else
			steps[i][0] = ft_down_steps(stack_b, temp->content);
		temp = temp->next;
	}
}

int	ft_compare_max_min(int i, t_list *stack_a, t_list *temp1 , int **steps)
{
	if (ft_get_min(stack_a) > temp1->content)
	{
		if (ft_is_up_down(stack_a, ft_get_min(stack_a)))
			steps[i][1] = ft_up_steps(stack_a, ft_get_min(stack_a));
		else
			steps[i][1] = ft_down_steps(stack_a, ft_get_min(stack_a));
		return (1);
	}
	else if (ft_get_max(stack_a) < temp1->content)
	{
		if (ft_is_up_down(stack_a, ft_get_min(stack_a)))
			steps[i][1] = ft_up_steps(stack_a, ft_get_min(stack_a));
		else
			steps[i][1] = ft_down_steps(stack_a, ft_get_min(stack_a));
		return (1);
	}
	return (0);
}


void	ft_steps_a(t_list *stack_a, t_list *stack_b, int **steps)
{
	size_t	i;
	size_t	j;
	t_list	*temp;
	t_list	*temp1;

	temp1 = stack_b;
	i = -1;
	while (++i < ft_lstsize(stack_b))
	{
		j = -1;
		temp = stack_a;
		while (++j < ft_lstsize(stack_a) - 1)
		{
			if (ft_compare_max_min(i, stack_a, temp1, steps))
				break;
			if (temp->content < temp1->content && temp->next->content > temp1->content)
			{
				if (ft_is_up_down(stack_a,  temp->content))
					steps[i][1] = ft_up_steps(stack_a, temp->next->content);
				else
					steps[i][1] = ft_down_steps(stack_a, temp->next->content);
				break;
			}
			temp = temp->next;
		}
		temp1 = temp1->next;
	}
}

int *ft_samller_steps(int **steps, size_t size)
{
	int *smaller;
	int min;
	size_t	i;

	smaller = (int *)malloc(sizeof(int) * 2);
	i = -1;
	min = MAX;
	while (++i < size)
	{
		if ((steps[i][0] >= 0 && steps[i][1] >= 0) || (steps[i][0] <= 0 && steps[i][1] <= 0))
		{
			if (ft_abs(steps[i][0]) >= ft_abs(steps[i][1]))
				steps[i][2] = ft_abs(steps[i][0]);
			else
				steps[i][2] = ft_abs(steps[i][1]);
		}
		else
			steps[i][2] = ft_abs(steps[i][0]) + ft_abs(steps[i][1]);
		if(steps[i][2] < min)
			min = steps[i][2];
	}
	return ft_find_samller_steps(steps, size, min, smaller);
}

int	*ft_find_samller_steps(int **steps, size_t size, int min, int *smaller)
{
	size_t	i;

	i = -1;

	while (++i < size)
	{
		if (steps[i][2] == min)
		{
			smaller[0] = steps[i][0];
			smaller[1] = steps[i][1];
		}
	}
	return (smaller);
}


void	ft_best_move_to_push_a(t_list **stack_a, t_list **stack_b)
{
	int	**steps;
	int *one_step;

	while(ft_lstsize(*stack_b))
	{
		steps = ft_malloc_steps(*stack_b);
		ft_steps_b(*stack_b, steps);
		ft_steps_a(*stack_a, *stack_b, steps);
		one_step = ft_samller_steps(steps, ft_lstsize(*stack_b));
		ft_free_steps(steps, ft_lstsize(*stack_b));

		while (one_step[0] < 0 && one_step[1] < 0)
		{
			ft_reverse_rotate_abr(stack_a, stack_b, 'r');
			one_step[0]++;
			one_step[1]++;
		}
		while (one_step[0] > 0 && one_step[1] > 0)
		{
			ft_rotate_abr(stack_a, stack_b, 'r');
			one_step[0]--;
			one_step[1]--;
		}

		while (one_step[0] > 0)
		{
			ft_rotate_abr(stack_a, stack_b, 'b');
			one_step[0]--;
		}
		while (one_step[0] < 0)
		{
			ft_reverse_rotate_abr(stack_a, stack_b, 'b');
			one_step[0]++;
		}

		while (one_step[1] > 0)
		{
			ft_rotate_abr(stack_a, stack_b, 'a');
			one_step[1]--;
		}
		while (one_step[1] < 0)
		{
			ft_reverse_rotate_abr(stack_a, stack_b, 'a');
			one_step[1]++;
		}

		ft_push_ab(stack_a, stack_b, 'a');
		free(one_step);
	}


	if (ft_is_up_down(*stack_a, ft_get_min(*stack_a)))
		while (ft_get_min(*stack_a) != (*stack_a)->content)
			ft_rotate_abr(stack_a, stack_b, 'a');
	else
		while (ft_get_min(*stack_a) != (*stack_a)->content)
			ft_reverse_rotate_abr(stack_a, stack_b, 'a');




	// size_t i;
	// size_t j;
	// // print steps
	// i = -1;
	// while (++i < ft_lstsize(*stack_b))
	// {
	// 	j = -1;
	// 	while (++j < 2)
	// 		printf("step[%zu][%zu] = %d --  ",i,j, steps[i][j]);
	// 	printf("\n");
	// }
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

	i = 0;
	while (stack)
	{
		if (stack->content == content)
			i = 0;
		stack = stack->next;
		i++;
	}
	return (i * -1);
}

// void	ft_push_to_a(t_list **stack_a, t_list **stack_b)
// {

// }

// void	ft_rotate_a_b(t_list **stack_a, t_list **stack_b)
// {

// }

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
