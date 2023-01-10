/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:09:39 by bel-idri          #+#    #+#             */
/*   Updated: 2023/01/10 21:03:28 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


#include <stdio.h>
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char *s;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	if (!ft_parsing(&stack_a, av))
		return (write(1, "Error\n", 6), 1);

	while((s = get_next_line(STDIN_FILENO)))
	{
		if (!ft_strncmp(s, "sa\n",3) && ft_strlen(s) == 3)
			ft_swap_abs_b(&stack_a, &stack_b, 'a');
		else if (!ft_strncmp(s, "sb\n", 3) && ft_strlen(s) == 3)
			ft_swap_abs_b(&stack_a, &stack_b, 'b');
		else if (!ft_strncmp(s, "ss\n", 3) && ft_strlen(s) == 3)
			ft_swap_abs_b(&stack_a, &stack_b, 's');
		else if (!ft_strncmp(s, "pa\n", 3) && ft_strlen(s) == 3)
			ft_push_ab_b(&stack_a, &stack_b, 'a');
		else if (!ft_strncmp(s, "pb\n", 3) && ft_strlen(s) == 3)
			ft_push_ab_b(&stack_a, &stack_b, 'b');
		else if (!ft_strncmp(s, "ra\n", 3) && ft_strlen(s) == 3)
			ft_rotate_abr_b(&stack_a, &stack_b, 'a');
		else if (!ft_strncmp(s, "rb\n", 3) && ft_strlen(s) == 3)
			ft_rotate_abr_b(&stack_a, &stack_b, 'b');
		else if (!ft_strncmp(s, "rr\n", 3) && ft_strlen(s) == 3)
			ft_rotate_abr_b(&stack_a, &stack_b, 'r');
		else if (!ft_strncmp(s, "rra\n", 4) && ft_strlen(s) == 4)
			ft_reverse_rotate_abr_b(&stack_a, &stack_b, 'a');
		else if (!ft_strncmp(s, "rrb\n", 4) && ft_strlen(s) == 4)
			ft_reverse_rotate_abr_b(&stack_a, &stack_b, 'b');
		else if (!ft_strncmp(s, "rrr\n", 4) && ft_strlen(s) == 4)
			ft_reverse_rotate_abr_b(&stack_a, &stack_b, 'r');
		else
		{
			ft_free_stack(&stack_a);
			ft_free_stack(&stack_b);
			return (write(1, "Error\n", 6), free(s), 1);
		}
		free(s);
	}
	
	if (!stack_b && ft_is_sort(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
